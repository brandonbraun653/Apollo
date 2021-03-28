/*
 * audioSample_io_regression.c
 *
 * This file contains the regression code to demonstrate the mcasp component
 * driver functionality on SYSBIOS
 *
 * Copyright (C) 2018-present Texas Instruments Incorporated - http://www.ti.com/
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
 *  \brief    sample application for demostration of audio playing
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
#include <ti/sysbios/io/IOM.h>
#include <xdc/runtime/Memory.h>
#include <ti/sysbios/heaps/HeapMem.h>
#include <xdc/runtime/IHeap.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/Log.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Semaphore.h>
#include <mcasp_drv.h>
#include "mcasp_osal.h"
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include "mcasp_cfg.h"
#include "MCASP_log.h"
#include "stdio.h"
#include "string.h"
#include <ti/csl/cslr_mcasp.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Cache.h>
#include "regression.h"

/************************* TEST PROFILES for Regression ****************************/
mcaspTestProfile_t mcaspTestProfile_1 = {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_1, /* testID */
   "I2S Default test , 1 ser, 2 tslots, buffer frmt: 1ser_multislot_interleaved",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   MCASP_NUM, /* instance_num */
   2, /* num_timeslots */
   MCASP_TEST_PROFILE_I2S, /* protocol */
   1, /* num_serializers */
   Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};

mcaspTestProfile_t mcaspTestProfile_2 = {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_2, /* testID */
   "I2S 2 Ser Test: 2 ser, 2 tslots, buffer frmt: MULTISER_MULTISLOT_SEMI_INTERLEAVED_1",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   MCASP_NUM, /* instance_num */
   2, /* num_timeslots */
   MCASP_TEST_PROFILE_I2S, /* protocol */
   2, /* num_serializers */
   Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};

mcaspTestProfile_t mcaspTestProfile_3 = {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_3, /* testID */
   "I2S 4 timeslots , 2 ser, 4 tslots, frmt: MULTISER_MULTISLOT_SEMI_INTERLEAVED_1",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   MCASP_NUM, /* instance_num */
   4, /* num_timeslots */
   MCASP_TEST_PROFILE_I2S, /* protocol */
   2, /* num_serializers */
   Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};



mcaspTestProfile_t mcaspTestProfile_4 = {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_4, /* testID */
   "DSP Burst mode test, 1 ser, 1 tslot, frmt: 1SER_1SLOT",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   MCASP_NUM, /* instance_num */
   1, /* num_timeslots */
   MCASP_TEST_PROFILE_DSP, /* protocol */
   1, /* num_serializers */
   Mcasp_BufferFormat_1SER_1SLOT, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};


mcaspTestProfile_t mcaspTestProfile_5 = {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_5, /* testID */
   "I2S Interleaved-2 format test , 2 ser , 2 tslot, frmt: MULTISER_MULTISLOT_SEMI_INTERLEAVED_2",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   MCASP_NUM, /* instance_num */
   2, /* num_timeslots */
   MCASP_TEST_PROFILE_I2S, /* protocol */
   2, /* num_serializers */
   Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};

mcaspTestProfile_t mcaspTestProfile_6= {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_6, /* testID */
   "McASP Instance/port test , Inst 1:  2 ser, 2 tslots, frmt: MULTISER_MULTISLOT_SEMI_INTERLEAVED_2",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   1, /* instance_num */
   2, /* num_timeslots */
   MCASP_TEST_PROFILE_I2S, /* protocol */
   2, /* num_serializers */
   Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};

mcaspTestProfile_t mcaspTestProfile_7= {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_7, /* testID */
   "McASP Instance/port test  , Inst 2:  2 ser, 2 tslots, MULTISER_MULTISLOT_SEMI_INTERLEAVED_2",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   2, /* instance_num */
   2, /* num_timeslots */
   MCASP_TEST_PROFILE_I2S, /* protocol */
   2, /* num_serializers */
   Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};


mcaspTestProfile_t mcaspTestProfile_8= {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_8, /* testID */
   "I2S 1 ser non-interleaved format test , 1 ser , 2 tslot, frmt: 1SER_MULTISLOT_NON_INTERLEAVED",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   MCASP_NUM, /* instance_num */
   2, /* num_timeslots */
   MCASP_TEST_PROFILE_I2S, /* protocol */
   1, /* num_serializers */
   Mcasp_BufferFormat_1SER_MULTISLOT_NON_INTERLEAVED, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};


mcaspTestProfile_t mcaspTestProfile_9= {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_9, /* testID */
   "DSP 1 ser non-interleaved format test ,2 ser , 1 tslot, frmt: MULTISER_1SLOT_SER_NON_INTERLEAVED,",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   MCASP_NUM, /* instance_num */
   1, /* num_timeslots */
   MCASP_TEST_PROFILE_DSP, /* protocol */
   2, /* num_serializers */
   Mcasp_BufferFormat_MULTISER_1SLOT_SER_NON_INTERLEAVED, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};

mcaspTestProfile_t mcaspTestProfile_10= {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_10, /* testID */
   "DSP 1 ser multislot interleaved format test ,2 ser , 1 tslot, frmt: MULTISER_1SLOT_SER_INTERLEAVED,",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   MCASP_NUM, /* instance_num */
   1, /* num_timeslots */
   MCASP_TEST_PROFILE_DSP, /* protocol */
   2, /* num_serializers */
   Mcasp_BufferFormat_MULTISER_1SLOT_SER_INTERLEAVED, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};

mcaspTestProfile_t mcaspTestProfile_11= {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_11, /* testID */
   "FIFO test: EventDMARatio=2 , I2S 1 ser ,2 tslot, frmt: 1SER_MULTISLOT_INTERLEAVED,,",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   MCASP_NUM, /* instance_num */
   2, /* num_timeslots */
   MCASP_TEST_PROFILE_I2S, /* protocol */
   1, /* num_serializers */
   Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   TRUE, /* enableFifo */
   2, /* hwFifoEventDMARatio */
};


mcaspTestProfile_t mcaspTestProfile_12= {

   /***** Test ID/description  *****/
   MCASP_REGRESSION_TEST_12, /* testID */
   "FIFO disable: EventDMARatio=2 , I2S 1 ser ,2 tslot, frmt: 1SER_MULTISLOT_INTERLEAVED,,",	/* testDescription */
   TRUE, /* powerCycleRequired */

   /***** Device Configuration *****/
   MCASP_NUM, /* instance_num */
   2, /* num_timeslots */
   MCASP_TEST_PROFILE_I2S, /* protocol */
   1, /* num_serializers */
   Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED, /* bufferformat */
   Mcasp_OpMode_TDM, /* opMode */
   Mcasp_WordLength_32, /* wordLength */
   FALSE, /* enableFifo */
   1, /* hwFifoEventDMARatio */
};

mcaspTestProfile_t * mcaspTestProfiles[] =
{
	&mcaspTestProfile_1,
	&mcaspTestProfile_2,
	&mcaspTestProfile_3,
	&mcaspTestProfile_4,
	&mcaspTestProfile_5,
	&mcaspTestProfile_6,
	&mcaspTestProfile_7,
	&mcaspTestProfile_8,
	&mcaspTestProfile_9,
	&mcaspTestProfile_10,
	&mcaspTestProfile_11,
	&mcaspTestProfile_12,
	
	NULL,
};



/******************************************************************************************/
/* Displays a test profile */
/******************************************************************************************/
void display_testProfile(mcaspTestProfile_t *testProfilePtr)
{
  	
   	MCASP_log("Test Profile: id=%d\n",testProfilePtr->testID);
   	MCASP_log("Test Profile: id=%s\n",testProfilePtr->testDescription);
   	
   	MCASP_log("Test Profile: mcasp instance=%d\n",testProfilePtr->instance_num);
   	MCASP_log("Test Profile: num_timeslots=%d\n",testProfilePtr->num_timeslots);
	
	switch(testProfilePtr->protocol)
   	{
  	   case MCASP_TEST_PROFILE_I2S:
         MCASP_log("Test Profile: protocol= I2S\n");
		  break;
	   case MCASP_TEST_PROFILE_DSP:
         MCASP_log("Test Profile: protocol= DSP\n");
		  break;
       default:
         MCASP_log("Test Profile: protocol= None!!!! Error!!\n");
         break;		  
	
	}
   	
   	MCASP_log("Test Profile: num_serializers=%d\n",testProfilePtr->num_serializers);
   	
	switch(testProfilePtr->bufferformat)
   	{
  	   case Mcasp_BufferFormat_1SER_1SLOT:
         MCASP_log("Test Profile: bufferformat= Mcasp_BufferFormat_1SER_1SLOT\n");
		  break;
	   case Mcasp_BufferFormat_1SER_MULTISLOT_NON_INTERLEAVED:
         MCASP_log("Test Profile: bufferformat= Mcasp_BufferFormat_1SER_MULTISLOT_NON_INTERLEAVED\n");
		  break;
	   case Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED:
         MCASP_log("Test Profile: bufferformat= Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED\n");
		  break;
	   case Mcasp_BufferFormat_MULTISER_1SLOT_SER_INTERLEAVED:
         MCASP_log("Test Profile: bufferformat= Mcasp_BufferFormat_MULTISER_1SLOT_SER_INTERLEAVED\n");
		  break;
	   case Mcasp_BufferFormat_MULTISER_1SLOT_SER_NON_INTERLEAVED:
         MCASP_log("Test Profile: bufferformat= Mcasp_BufferFormat_MULTISER_1SLOT_SER_NON_INTERLEAVED\n");
		  break;

	   case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1:
         MCASP_log("Test Profile: bufferformat= Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1\n");
		  break;

	   case Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2:
         MCASP_log("Test Profile: bufferformat= Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2\n");
		  break;

       default:
         MCASP_log("Test Profile: bufferformat= None!!!! Error!!\n");
         break;		  
	}
	
	
	switch(testProfilePtr->channelMode)
   	{
  	   case Mcasp_OpMode_TDM:
         MCASP_log("Test Profile: channelMode = Mcasp_OpMode_TDM\n");
		  break;
	   case Mcasp_OpMode_DIT:
         MCASP_log("Test Profile: channelMode= Mcasp_OpMode_DSP\n");
		  break;
       default:
         MCASP_log("Test Profile: channelMode= None!!!! Error!!\n");
         break;		  
	}
   	
	switch(testProfilePtr->wordLength)
   	{
  	   case Mcasp_WordLength_8:
         MCASP_log("Test Profile: wordLength = Mcasp_WordLength_8\n");
	     break;

  	   case Mcasp_WordLength_12:
         MCASP_log("Test Profile: wordLength = Mcasp_WordLength_12\n");
	     break;

  	   case Mcasp_WordLength_16:
         MCASP_log("Test Profile: wordLength = Mcasp_WordLength_16\n");
	     break;

  	   case Mcasp_WordLength_20:
         MCASP_log("Test Profile: wordLength = Mcasp_WordLength_20\n");
	     break;

  	   case Mcasp_WordLength_24:
         MCASP_log("Test Profile: wordLength = Mcasp_WordLength_24\n");
	     break;

  	   case Mcasp_WordLength_32:
         MCASP_log("Test Profile: wordLength = Mcasp_WordLength_32\n");
	     break;

       default:
         MCASP_log("Test Profile: wordLength= None!!!! Error!!\n");
         break;		  
	}

   MCASP_log("Test Profile: enableFifo=%d\n",testProfilePtr->enableFifo);
   MCASP_log("Test Profile: hwFifoEventDMARatio=%d",testProfilePtr->hwFifoEventDMARatio);
   MCASP_log ("\n-----------------------------------------------------------\n\n");  
  
}

/******************************************************************************************/
/* Displays a Regression Test menu */
/******************************************************************************************/

int32_t mcasp_regression_seek_testID()
{
   mcaspTestProfile_t *testProfilePtr;
   uint32_t testprofile;
   bool validInput=FALSE;
   int32_t			selection;
   char Response[10];

  do 
  {
   MCASP_log ("\n\n\n\n\n\n");
   MCASP_log ("MCASP Regression Test Menu\n");
   MCASP_log ("----------------------------------------------\n");  

   MCASP_log (" Test ID:   Description    Powercycle Required?\n");  
   
     /* Display the menu*/
     for(testprofile=0;testprofile<sizeof(mcaspTestProfiles)/sizeof(mcaspTestProfile_t *);testprofile++)
     {
        testProfilePtr = mcaspTestProfiles[testprofile];
    
        if(testProfilePtr==NULL) 
        {  /* End of test profiles */
	      break;
	    }
        MCASP_log ("%5d      %20s       %4s \n",testProfilePtr->testID,testProfilePtr->testDescription,((testProfilePtr->powerCycleRequired==TRUE)?"Yes":"No"));
	 }

    MCASP_log ("%5d     %50s      %4s \n",MCASP_REGRESSION_TEST_EXIT,"Exit the regression","Yes");
	
    MCASP_log ("\n\n");
    MCASP_log ("Please enter a test ID from the above list: ");
    
	 UART_scanFmt("%s", Response);
	 selection = atoi(Response);

      if(selection >= 0  && selection <MCASP_REGRESSION_TEST_MAX) {
		 validInput=TRUE;
	  } else {
         
         if( !((selection == MCASP_REGRESSION_ALL_NON_POWERCYCLE_TESTS) || 
             (selection == MCASP_REGRESSION_TEST_EXIT)) ) {
             MCASP_log ("Invalid selection: %d !! Please enter a valid test ID from the table!!!\n", selection);
         } else {
		   validInput=TRUE;
		 }   
	  }
	  
  } while(validInput==FALSE);
  
  return(selection);
}


extern uint32_t mcasp_instance_num;
#define MCASP_DIR_RX 0
#define MCASP_DIR_TX 1

/****************************************************************************/
/***********   Configure MCASP structures as per the test profile ***********/
/****************************************************************************/
void configure_mcasp_with_testProfile(mcaspTestProfile_t *testProfilePtr)
{
  int i;
  
  
   /* instance number */
   mcasp_instance_num = testProfilePtr->instance_num;
  
  /* Num timeslots */
  mcasp_chanparam[MCASP_DIR_RX].noOfChannels=testProfilePtr->num_timeslots;
  mcasp_chanparam[MCASP_DIR_TX].noOfChannels=testProfilePtr->num_timeslots;
  
  /* protocol I2S, DSP */
  if(testProfilePtr->protocol == MCASP_TEST_PROFILE_I2S) {
	 mcasp_chanparam[MCASP_DIR_RX].mcaspSetup->fmt |= (1 << 16); /* 1 bit delay in frame sync */ 
	 mcasp_chanparam[MCASP_DIR_TX].mcaspSetup->fmt |= (1 << 16); /* 1 bit delay in frame sync */ 

	 mcasp_chanparam[MCASP_DIR_RX].mcaspSetup->frSyncCtl = 0x00000113; /* I2S mode,
                                             * Frame sync is one word
                                             * Internally generated frame sync
                                             * Falling edge is start of frame
                                             */ 
	 mcasp_chanparam[MCASP_DIR_TX].mcaspSetup->frSyncCtl = 0x00000113; /* I2S mode,
                                             * Frame sync is one word
                                             * Internally generated frame sync
                                             * Falling edge is start of frame
                                             */ 
#if 0
     if(testProfilePtr->num_timeslots!=2) {
		  MCASP_log("\n Test profile %d has wrong number of timeslots. For I2S mode it is always 2, hence changing it to 2 !!\n");
		  testProfilePtr->num_timeslots=2;
	 } 	  
#endif	 
   } else {
	 mcasp_chanparam[MCASP_DIR_RX].mcaspSetup->fmt &= ~(1 << 16); /* 1 bit delay in frame sync */ 
	 mcasp_chanparam[MCASP_DIR_TX].mcaspSetup->fmt &= ~(1 << 16); /* 1 bit delay in frame sync */ 
  
     mcasp_chanparam[MCASP_DIR_RX].mcaspSetup->frSyncCtl = 0x00000002; /* burst mode,
                                             * Frame sync is one bit
                                             * internally generated frame sync
                                             * Rising edge is start of frame
                                             */
     mcasp_chanparam[MCASP_DIR_TX].mcaspSetup->frSyncCtl = 0x00000002; /* burst mode,
                                             * Frame sync is one bit
                                             * internally generated frame sync
                                             * Rising edge is start of frame
                                             */                                             
   }
  
  
  for(i=0;i<testProfilePtr->num_timeslots;i++) {
  	mcasp_chanparam[MCASP_DIR_RX].mcaspSetup->tdm |= (1 << i); 
	mcasp_chanparam[MCASP_DIR_TX].mcaspSetup->tdm |= (1 << i); 
  }	  

  /* num_serializers */  
  mcasp_chanparam[MCASP_DIR_RX].noOfSerRequested=testProfilePtr->num_serializers;
  mcasp_chanparam[MCASP_DIR_TX].noOfSerRequested=testProfilePtr->num_serializers;
  
  /* buffer format */
  mcasp_chanparam[MCASP_DIR_RX].dataFormat = testProfilePtr->bufferformat;
  mcasp_chanparam[MCASP_DIR_TX].dataFormat = testProfilePtr->bufferformat;
  
  /* channelMode */
  mcasp_chanparam[MCASP_DIR_RX].channelMode=testProfilePtr->channelMode;
  mcasp_chanparam[MCASP_DIR_TX].channelMode=testProfilePtr->channelMode;

  /* wordLength */
  mcasp_chanparam[MCASP_DIR_RX].wordWidth=testProfilePtr->wordLength;
  mcasp_chanparam[MCASP_DIR_TX].wordWidth=testProfilePtr->wordLength;

  /* enableFifo */
  mcasp_chanparam[MCASP_DIR_RX].enableHwFifo=testProfilePtr->enableFifo;
  mcasp_chanparam[MCASP_DIR_TX].enableHwFifo=testProfilePtr->enableFifo;
  
  /* hwFifoEventDMARatio */
  mcasp_chanparam[MCASP_DIR_RX].hwFifoEventDMARatio=testProfilePtr->hwFifoEventDMARatio;
  mcasp_chanparam[MCASP_DIR_TX].hwFifoEventDMARatio=testProfilePtr->hwFifoEventDMARatio;
  
} 
/* ========================================================================== */
/*                             END OF FILE                                    */
/* ========================================================================== */
