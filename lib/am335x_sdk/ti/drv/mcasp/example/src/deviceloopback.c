/*
 * deviceloopback.c
 *
 * This file contains the test / demo code to demonstrate the Audio component
 * driver functionality on SYS/BIOS.
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

/** \file     deviceloopback.c
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
#include <xdc/runtime/Memory.h>
#include <ti/osal/osal.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Error.h>

#include "deviceloopback.h"

extern const ti_sysbios_heaps_HeapMem_Handle myHeap;

/* The Serializer/timeslot information, one for each direction TX/RX */
dlbTestInfo_t dlbTestInfo[2];
rampSynchState_e rampRxSynchState = RX_LOOPBACK_NOT_SYNCHED;
rampSynchState_e rampRxSynchStatePrev = RX_LOOPBACK_NOT_SYNCHED;
IHeap_Handle iheap;
/* Queue for events */
Osal_Queue_Elem dlbEventsQueue;
/******************************************************************************************
 * Print the events from the events queue.
 */
void dlb_process_events()
{
   dlbEvent_t *dlbEvent;
   /* Go through the events queue and print the status changes */
   while (((int32_t)TRUE) != Osal_Queue_empty((&dlbEventsQueue)))
   {
       dlbEvent = (dlbEvent_t *)  \
                            Osal_Queue_get((&dlbEventsQueue));

       if (NULL == dlbEvent)
       {
         /* Ideally control should not come here                   */
         break;
       }

     /* Print messages if DLB_ENABLE_DEBUG_MSGS is enabled. NOTE: Enabling this option
      * could cause failures because multiple UART messages prints between mcasp transfers can
      * cause McASP to lose events. Hence this option should be enabled for debugging purposes ONLY.
      */
      switch(dlbEvent->statusChange)
      {
        case FOUND_SYNC:
#ifdef DLB_ENABLE_DEBUG_MSGS
            MCASP_log("\nSync found for serializer %d, timeslot %d, on frame %d, sample_no=%d", dlbEvent->serIndex, dlbEvent->tsIndex, dlbEvent->frame_no,dlbEvent->sample_no);
#endif
            break;

        case LOST_SYNC_RAMP_VAL:
#ifdef DLB_ENABLE_DEBUG_MSGS
            MCASP_log("\n Sync lost: Ramp discontinuity for serializer %d timeslot %d, on frame %d, sample_no=%d", dlbEvent->serIndex, dlbEvent->tsIndex,dlbEvent->frame_no,dlbEvent->sample_no);
#endif
            break;

        case LOST_SYNC_SER_TS_MISMATCH:
#ifdef DLB_ENABLE_DEBUG_MSGS
            MCASP_log("\n Sync lost:  Serializer Or timeslot signature doesnt match for serializer %d timeslot %d, on frame %d, sample_no=%d", dlbEvent->serIndex,dlbEvent->tsIndex, dlbEvent->frame_no,dlbEvent->sample_no);
#endif
            break;
        default:
            break;
      }

      Memory_free(iheap,dlbEvent,sizeof(dlbEvent_t));
    }

}

/********************* LOOPBACK TEST INFORMATION ***********************************/
/*
 * In the loopback test, there will be a ramp sent to TX and checked up on reception for
 * any discontinuity.  The ramp is independent for each timeslot inside a serializer
 * and is sent/received for every serializer. On the TX side , the ramp is generated
 * and the samples to be sent kept under the dlbInfo[Tx].serInfo[ser].tsInfo.buf[] which is
 * an unpacked 32-bit sample buffer.
 * Then it is packed in to the host packed buffer before submitting to mcasp.
 * Up on reception, the received packed buffer (rxbuf[0/1] is unpacked in to the tsInfo[buf]
 * and then the ramp continuity is checked up on the unpacked 32 bit samples inside that buffer.
 *
 * */



/*****************************************************************************
 * Fetches the sample offset in the packed Host buffer for the
 * (ser,timeslot,sampleno,framesize) combination
 * ***************************************************************************/
uint32_t get_sample_offset(uint32_t dir,uint32_t ser_no,uint32_t timeslot_no,
                           uint32_t sample_no,uint32_t frame_size_in_words)
{
    Mcasp_ChanParams * chanParams =   &mcasp_chanparam[dir];
    uint32_t num_serializers = chanParams->noOfSerRequested;
    uint32_t num_timeslots   = chanParams->noOfChannels;
    uint32_t sample_word_offset=0;

    switch (chanParams->dataFormat)
    {
      case Mcasp_BufferFormat_1SER_1SLOT:
      case Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED:
      case Mcasp_BufferFormat_MULTISER_1SLOT_SER_INTERLEAVED:
      case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1:
         sample_word_offset = sample_no* num_timeslots*num_serializers +
                              timeslot_no * num_serializers +
                              ser_no;
         break;

      case Mcasp_BufferFormat_MULTISER_1SLOT_SER_NON_INTERLEAVED:
      case Mcasp_BufferFormat_1SER_MULTISLOT_NON_INTERLEAVED:
      case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2:
          /* All serializers' data are together */
          sample_word_offset = ser_no*(frame_size_in_words/num_serializers) +
                               sample_no*num_timeslots +
                               timeslot_no;
          break;
      default:
          break;
    }
    return sample_word_offset;
}
/* Configures the loopback type based upon the MCASP configuration */
/*****************************************************************************
 * Initialize the loopback ramp test parameters. This involves initializing
 * the ramp related information for all the timeslots and all serializers
 * involved in the test.
 *****************************************************************************/
void initialize_dlbTestInfo(uint32_t frame_size_in_bytes_tx, uint32_t frame_size_in_bytes_rx) {

    uint32_t ser;
    uint32_t dir;
    uint32_t frameSizeBytesDir[2];

    Error_Block  eb;
	
    frameSizeBytesDir[0]=frame_size_in_bytes_rx;
    frameSizeBytesDir[1]=frame_size_in_bytes_tx;

	iheap = HeapMem_Handle_to_xdc_runtime_IHeap(myHeap);
	Error_init(&eb);

	/* Create a queue of events */
	Osal_Queue_construct(&dlbEventsQueue,(void *)NULL);

    /* Initialize for Tx and Rx */
	for(dir=0;dir<2;dir++)
    {
      Mcasp_ChanParams * chanParams =   &mcasp_chanparam[dir];
 	  /* In the loopback test, all serializers and their timeslots share the same data sizer per direction. The frame_size_in_bytes is split
        amongst all of them.
	*/
	  uint32_t samples_per_timeslot_bytes = frameSizeBytesDir[dir]/(chanParams->noOfSerRequested *chanParams->noOfChannels);
	  uint32_t samples_per_timeslot_words = samples_per_timeslot_bytes/(chanParams->wordWidth/8);

        /* For each serializer initialize its timeslot data */  
       for(ser = 0; ser < chanParams->noOfSerRequested ; ser++)
       {
         /* For Tx and Rx */
            uint32_t timeslot;
            serInfo_t *serInfoPtr;

            /* Get the serializer data structure */
            serInfoPtr = &(dlbTestInfo[dir].serInfo[ser]);
            serInfoPtr->index = chanParams->indexOfSersRequested[ser]; /* This is the actual serializer number */

             /* For all timeslots within the serializer */
            for (timeslot=0;timeslot<chanParams->noOfChannels;timeslot++)
            {
               tsInfo_t *tsInfoPtr = &(serInfoPtr->tsInfo[timeslot]);
               int index;

               tsInfoPtr->index = timeslot;

               /* Allocate the unpacked buffer. Each 'word' will be represented in 32 bit words in the unpacked buffer */
               tsInfoPtr->buf = Memory_calloc(iheap,samples_per_timeslot_words*4,4,&eb);

               if(NULL == tsInfoPtr->buf)
               {
                  MCASP_log("\r\nMEM_calloc failed for unpacked buffers for serializer (%d) and timeslot (%d).\n",ser, timeslot);
               }

               tsInfoPtr->sample_word_offsets = Memory_calloc(iheap,samples_per_timeslot_words*4,4,&eb);
			   
               if(NULL == tsInfoPtr->sample_word_offsets)
               {
                  MCASP_log("\r\nMEM_calloc failed for word offsets buffers for serializer (%d) and timeslot (%d).\n",ser, timeslot);
               }

               tsInfoPtr->buf_num_samples = samples_per_timeslot_words;

               /* Assign the remaining parameters */
               tsInfoPtr->ramp_last_val = 0;  /* For Tx, it is the last put value on the ramp, for Rx it is the last ramp value received */
               tsInfoPtr->ramp_synch_losses=0; /* Applicable to Rx */
               tsInfoPtr->ramp_transmission_errors=0;
               tsInfoPtr->ramp_synch_finds=0;  /* Applicable to Rx */
               tsInfoPtr->ramp_last_val= ~(0x0); /* Applicable to Rx Only */
			   tsInfoPtr->rampRxSynchState = RX_LOOPBACK_NOT_SYNCHED;
               tsInfoPtr->rampRxSynchStatePrev = RX_LOOPBACK_NOT_SYNCHED;
               tsInfoPtr->total_frames=0;

               /* Select the least word width for the ramp pattern. If we want to test the asymmetric loopback configuration,
                * the ramp value sent/received should be the minimum of the Tx and Rx direction */
               tsInfoPtr->ValwordWidth = (mcasp_chanparam[RX].wordWidth < mcasp_chanparam[TX].wordWidth)?mcasp_chanparam[RX].wordWidth:mcasp_chanparam[TX].wordWidth;
               tsInfoPtr->ramp_mask = SAMPLE_MASK(tsInfoPtr->ValwordWidth- (4+4)); /* 4,4 bits for Ser,Tslot info */
               tsInfoPtr->wordBitsSelect=chanParams->wordBitsSelect;

               for(index=0;index<tsInfoPtr->buf_num_samples;index++) {
                  tsInfoPtr->sample_word_offsets[index]=get_sample_offset (dir,ser,timeslot,index,frameSizeBytesDir[dir]/(chanParams->wordWidth/8));
               }

            }/* tsInfo */
            serInfoPtr->enabled=TRUE;
        } /* serializer */
    }/* Dir */
}

/******************************************************************************************
 * Configures the loopback test parameters
 *****************************************************************************************/
void config_deviceloopback(uint32_t frame_size_in_bytes_tx, uint32_t frame_size_in_bytes_rx)
{
    initialize_dlbTestInfo(frame_size_in_bytes_tx,frame_size_in_bytes_rx);
    rampRxSynchState     = RX_LOOPBACK_NOT_SYNCHED;
    rampRxSynchStatePrev = RX_LOOPBACK_NOT_SYNCHED;
}

/******************************************************************************************
 * Generate the ramp pattern for all serializers and their timeslots
 *****************************************************************************************/
void gen_ramp_pattern(uint32_t frame_size_in_bytes)
{

   /* For Tx */
   uint32_t dir=TX,ser,timeslot; /* Ramp is generated ONLY for TX */
   Mcasp_ChanParams * chanParams =   &mcasp_chanparam[dir];
   uint32_t num_serializers = chanParams->noOfSerRequested;
   
   /* Go to each serializer and insert the ramp patter, per timeslot buffer.
    i.e Each timeslot will have its own ramp */
   for(ser = 0; ser < num_serializers; ser++)
   {
       serInfo_t *serInfoPtr;
       serInfoPtr = &(dlbTestInfo[dir].serInfo[ser]);

       if(serInfoPtr->enabled==TRUE)
       {
           uint32_t num_timeslots = chanParams->noOfChannels;
           /* sample_val = fn(serializer_no(4 bits), timeslot_no (4 bits), ramp_val) */
           /* For all timeslots within the serializer */
           for (timeslot=0;timeslot<num_timeslots;timeslot++)
           {
			  uint32_t ramp_val,index,sample;
              tsInfo_t *tsInfoPtr = &(serInfoPtr->tsInfo[timeslot]);
              tsInfoPtr->index = timeslot;
              
			  /* Go through the samples in the buffer, and generate the ramp pattern */
              for(index=0;index<tsInfoPtr->buf_num_samples;index++) /* 32 bit samples */
			  {
                /* Calculate the new ramp value */
                ramp_val = (tsInfoPtr->ramp_last_val+1) & tsInfoPtr->ramp_mask;
                tsInfoPtr->ramp_last_val = ramp_val; /* Overwriting with the new one */

                /* Prepare the sample value to put */
                sample = CREATE_SAMPLE_VAL(ser,timeslot,tsInfoPtr->ValwordWidth,ramp_val);
				
                /* if the Rx word width is less, we do restritct the sample to valWordWidth.
                 * However if the Rx side is MSB aligned (such as in HDMI), then we may want to
                 * shift the ValwordWidth contents to MSB
                 */
                if(mcasp_chanparam[RX].wordBitsSelect==Mcasp_WordBitsSelect_MSB)
                {
                  sample = sample << (mcasp_chanparam[TX].wordWidth - tsInfoPtr->ValwordWidth);
                }
                tsInfoPtr->buf[index]=sample;
                tsInfoPtr->ramp_last_sample = sample ;
			  }	
           }/* tsInfo */
         }
     }

}

/*****************************************************************************
 * if dir==TX, this routine packs the ramp buffer contents in the timeslot->buf[] in to
 * the Host buffer
 * if dir==RX, this routine unpacks the ramp buffer contents in the Host buffer to
 * the timeslot->buf[]
 * ***************************************************************************/
void pack_unpack_buf (void *frame_buf, uint32_t frame_size,uint32_t dir)
{
   uint32_t ser,timeslot,index;
   Mcasp_ChanParams * chanParams =   &mcasp_chanparam[dir];

     /* For each serializer, for each timeslot finish writing its samples */
     for(ser = 0; ser < chanParams->noOfSerRequested; ser++)
     {
        serInfo_t *serInfoPtr=&(dlbTestInfo[dir].serInfo[ser]);

        if(serInfoPtr->enabled==TRUE)
        {
           uint32_t num_timeslots = chanParams->noOfChannels;
           /* For all timeslots within the serializer */
           for (timeslot=0;timeslot<num_timeslots;timeslot++)
           {
              tsInfo_t *tsInfoPtr = &(serInfoPtr->tsInfo[timeslot]);
              /* For each sample from the unpacked buffer, find its place inside the frame buffer and put it there */
			  for(index=0;index < tsInfoPtr->buf_num_samples;index++) /* 32 bit samples */
              {
                  /* Find the byte offset */
				  uint32_t sample_word_offset = tsInfoPtr->sample_word_offsets[index];
                  switch(chanParams->wordWidth)
                  {
                    case Mcasp_WordLength_32:
					  if(dir==TX) { /* Pack */
                        *((uint32_t* )frame_buf + sample_word_offset) = tsInfoPtr->buf[index];
					  } else { /* Un-Pack */
                        tsInfoPtr->buf[index] = *((uint32_t* )frame_buf + sample_word_offset);					  
					  }
                      break;
                    case Mcasp_WordLength_16:
					  if(dir==TX) { /* Pack */
   					    *((uint16_t* )frame_buf + sample_word_offset) = (uint16_t) tsInfoPtr->buf[index];
                      } else { /* Un Pack */
                        tsInfoPtr->buf[index] = *((uint16_t* )frame_buf + sample_word_offset);
					  }
					   break;
                    case Mcasp_WordLength_8:
					  if(dir==TX) { /* Pack */
   					    *((uint8_t* )frame_buf + sample_word_offset) = (uint8_t) tsInfoPtr->buf[index];
                      } else { /* Un Pack */
                        tsInfoPtr->buf[index] = *((uint8_t* )frame_buf + sample_word_offset);
					  }
                        break;
                    default:
                        break;
                  }

              }/* tsIndex */
              tsInfoPtr->total_frames++;

           }
        }
      }

}
/******************************************************************************************
 * Analyze the unpacked ramp pattern on the RX side and check for an discontinuity or errors
 ******************************************************************************************/
void analyze_received_samples(uint32_t frame_size_in_bytes)
{

   /* For Tx */
   uint32_t dir=RX; /* Ramp is generated ONLY for TX */
   uint32_t ser,timeslot,index;
   Mcasp_ChanParams * chanParams =   &mcasp_chanparam[dir];
   uint32_t num_serializers = chanParams->noOfSerRequested;
   Error_Block eb;
   /* Go to each serializer and insert the ramp patter, per timeslot buffer.
    i.e Each timeslot will have its own ramp */
   for(ser = 0; ser < num_serializers; ser++)
   {
       serInfo_t *serInfoPtr;
       serInfoPtr = &(dlbTestInfo[dir].serInfo[ser]);

       if(serInfoPtr->enabled==TRUE)
       {
           uint32_t num_timeslots = chanParams->noOfChannels;
           /* sample_val = fn(serializer_no(4 bits), timeslot_no (4 bits), ramp_val) */
           /* For all timeslots within the serializer */

           for (timeslot=0;timeslot<num_timeslots;timeslot++)
           {
              tsInfo_t *tsInfoPtr = &(serInfoPtr->tsInfo[timeslot]);
              uint32_t continuous_sync=0;
			  /* Go through the samples in the buffer, and generate the ramp pattern */
              for(index=0;index<tsInfoPtr->buf_num_samples;index++) /* 32 bit samples */
			  {
  			    uint32_t receivedSample=tsInfoPtr->buf[index];
  			    uint32_t ramp_last_val_temp = tsInfoPtr->ramp_last_val;

                if(mcasp_chanparam[TX].wordBitsSelect==Mcasp_WordBitsSelect_MSB)
                 {
                    receivedSample = receivedSample >> (mcasp_chanparam[RX].wordWidth - tsInfoPtr->ValwordWidth);
                 }

				uint32_t receivedSample_val = EXTRACT_SAMPLE_VAL(ser,index,tsInfoPtr->ValwordWidth,receivedSample);
				uint32_t receivedSample_ser = EXTRACT_SAMPLE_SER(ser,index,tsInfoPtr->ValwordWidth,receivedSample);
				uint32_t receivedSample_ts  = EXTRACT_SAMPLE_TS(ser,index,tsInfoPtr->ValwordWidth,receivedSample);

				if(receivedSample_ser == ser && receivedSample_ts==timeslot) {
				  /* Calculate the new ramp value */
				  if(receivedSample_val != ((uint32_t)(ramp_last_val_temp+1)& tsInfoPtr->ramp_mask)) {
    				tsInfoPtr->ramp_transmission_errors++;
    				continuous_sync=0; /* Synch lost */
    			  } else {
    				continuous_sync++; /* Unbroken synch for sometime */
    			  }
				
                  tsInfoPtr->ramp_last_val = receivedSample_val & tsInfoPtr->ramp_mask ; /* Overwriting with the new one */

				  if(continuous_sync== RX_SYNC_THRESHOLD) {
    				tsInfoPtr->rampRxSynchState = RX_LOOPBACK_SYNCHED;
    			  }
				  else
				  {
    				/* Synch was present earlier and we lost it now , as indicated by continous_synch==0 */
    				if((continuous_sync==0) && (tsInfoPtr->rampRxSynchStatePrev==RX_LOOPBACK_SYNCHED)) 
					{
    				  tsInfoPtr->rampRxSynchState=RX_LOOPBACK_NOT_SYNCHED;
    				}
    			 }

    			/* If State changed */
 	            if(tsInfoPtr->rampRxSynchState!=tsInfoPtr->rampRxSynchStatePrev) 
				{
 	               if(tsInfoPtr->rampRxSynchState ==RX_LOOPBACK_SYNCHED) 
				   {
  	        	      tsInfoPtr->ramp_synch_finds++;
  	                  tsInfoPtr->statusChange=FOUND_SYNC;

  	                  /* Push the event in to the event queue */
  	                  {
  	                      dlbEvent_t *dlbEvent;
  	                      dlbEvent = (dlbEvent_t *)Memory_calloc(iheap,sizeof(dlbEvent_t),4,&eb);

                          if(dlbEvent)
                          {
  	                        dlbEvent->statusChange=FOUND_SYNC;
  	                        dlbEvent->dir=RX;
  	                        dlbEvent->frame_no=tsInfoPtr->total_frames;
  	                        dlbEvent->sample=receivedSample;
  	                        dlbEvent->sample_no=index;
                            dlbEvent->serIndex=serInfoPtr->index;
                            dlbEvent->tsIndex=timeslot;
                            Osal_Queue_put((Osal_Queue_handle(&dlbEventsQueue)),(Osal_Queue_Elem *)dlbEvent);
                          }
                          else
                          {
                             MCASP_log("\n ERROR! Memory creation failed for Event\n");
                          }
  	                  }

 	               } else 
				   {
 	                    /* Push the event in to the event queue */
 	                      {
 	                          dlbEvent_t *dlbEvent;
 	                          dlbEvent = (dlbEvent_t *)Memory_calloc(iheap,sizeof(dlbEvent_t),4,&eb);

 	                          if(dlbEvent)
 	                          {
 	                            dlbEvent->statusChange=LOST_SYNC_RAMP_VAL;
 	                            dlbEvent->dir=RX;
 	                            dlbEvent->frame_no=tsInfoPtr->total_frames;
 	                            dlbEvent->sample=receivedSample;
 	                            dlbEvent->sample_no=index;
 	                            dlbEvent->serIndex=serInfoPtr->index;
 	                            dlbEvent->tsIndex=timeslot;
 	                            Osal_Queue_put((Osal_Queue_handle(&dlbEventsQueue)),(Osal_Queue_Elem *)dlbEvent);
 	                          }
 	                          else
 	                          {
 	                            MCASP_log("\n ERROR! Memory creation failed for Event\n");
 	                          }
 	                      }

 	        	      tsInfoPtr->ramp_synch_losses++;
 	               }
 	               tsInfoPtr->rampRxSynchStatePrev=tsInfoPtr->rampRxSynchState;
				 }
				}
                else
                {
                    /* IF the sync was present earlier and now we see this discrepancy, there is a problem) */
                    if(tsInfoPtr->rampRxSynchStatePrev==RX_LOOPBACK_SYNCHED)
                    {
                      {
                          dlbEvent_t *dlbEvent;
                          dlbEvent = (dlbEvent_t *)Memory_calloc(iheap,sizeof(dlbEvent_t),4,&eb);

                          if(dlbEvent!=NULL) {
                            dlbEvent->statusChange=LOST_SYNC_SER_TS_MISMATCH;
                            dlbEvent->dir=RX;
                            dlbEvent->frame_no=tsInfoPtr->total_frames;
                            dlbEvent->sample=receivedSample;
                            dlbEvent->sample_no=index;
                            dlbEvent->serIndex=serInfoPtr->index;
                            dlbEvent->tsIndex=timeslot;
                            Osal_Queue_put((Osal_Queue_handle(&dlbEventsQueue)),(Osal_Queue_Elem *)dlbEvent);
                         } else {
                             MCASP_log("\n ERROR! Memory creation failed for Event\n");
                         }
                      }

                      tsInfoPtr->rampRxSynchState = RX_LOOPBACK_NOT_SYNCHED;
                      tsInfoPtr->ramp_synch_losses++;
                    }
                }

                  tsInfoPtr->ramp_last_sample = receivedSample ;
			  } /* for( index) */
           }/* for(tsInfo )*/
        } /* if(ser==enabled) */
    }/* for(ser) */
}
/******************************************************************************************
 * Processes the Tx and Rx Samples for Ramp generation & Ramp check
 ******************************************************************************************/
void deviceloopback_process_samples(void *buf, uint32_t len_in_bytes, int dir)
{
   /* Now check for ramp */
    if (dir == RX)
    {
        /* Unpack the Rx buffer */
        pack_unpack_buf (buf,len_in_bytes,RX);

        /* Analyze the received samples for ramp */
        analyze_received_samples(len_in_bytes);
    }
    else if (dir == TX)
    {
        /* Generate Ramp pattern for all serializers/timeslots */
        gen_ramp_pattern(len_in_bytes);
        /* Pack the ramp in to the transmit buffer */
        pack_unpack_buf (buf, len_in_bytes,TX);
    }
}

/******************************************************************************************
 * Prints the final test report
 ******************************************************************************************/
void finish_deviceloopback() {
	/* Analyze the results of the loopback test */
		/* Test ran to completion */
    /* For Tx */
     uint32_t dir=RX; /* Ramp is generated ONLY for TX */
     uint32_t ser,timeslot;
     Mcasp_ChanParams * chanParams =   &mcasp_chanparam[dir];
     uint32_t num_serializers = chanParams->noOfSerRequested;
     bool test_pass=TRUE;

     /* Go to each serializer and insert the ramp patter, per timeslot buffer.
      i.e Each timeslot will have its own ramp */
     for(ser = 0; ser < num_serializers; ser++)
     {
         serInfo_t *serInfoPtr;
         serInfoPtr = &(dlbTestInfo[dir].serInfo[ser]);

         if(serInfoPtr->enabled==TRUE)
         {
             uint32_t num_timeslots = chanParams->noOfChannels;
             /* sample_val = fn(serializer_no(4 bits), timeslot_no (4 bits), ramp_val) */
             /* For all timeslots within the serializer */

             for (timeslot=0;timeslot<num_timeslots;timeslot++)
             {
                tsInfo_t *tsInfoPtr = &(serInfoPtr->tsInfo[timeslot]);

                if(tsInfoPtr->ramp_synch_losses==0)
                {

                    if(tsInfoPtr->ramp_synch_finds==0)
                    {
                        MCASP_log("\nTEST FAIL: Ramp test never found sync on rx for Serializer=%d, timeslot=%d\n", serInfoPtr->index, timeslot);
                        test_pass=FALSE;
                    }
                }
                else
                {
                    MCASP_log("\nTEST FAIL: Sync losses sync on rx for Serializer=%d, timeslot=%d\n", serInfoPtr->index, timeslot);
                    test_pass=FALSE;
                }

             }
         }
     }
    if(test_pass==TRUE) {
	      MCASP_log("\nAll tests have passed\n");
	} else {
		 MCASP_log("\nTEST FAIL:Some tests have failed\n");
	}
}
