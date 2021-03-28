/*
 * audioSample_io.c
 *
 * This file contains the test / demo code to demonstrate the Audio component
 * driver functionality on SYS/BIOS 6.
 *
 * Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
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
#include <ti/csl/csl_chip.h>
#include <ti/sdo/edma3/drv/edma3_drv.h>
#include <ti/sdo/edma3/rm/edma3_rm.h>
#include <ti/sdo/edma3/drv/sample/bios6_edma3_drv_sample.h>
#include "mcasp_osal.h"
#include "ICodec.h"
#include "mcasp_cfg.h"
#include "MCASP_log.h"
#include "stdio.h"
#include "string.h"

#include <ti/csl/cslr_mcasp.h>
#ifdef MEASURE_TIME
  #include "profiling.h"
#endif

#ifdef DEVICE_LOOPBACK
  #include "deviceloopback.h"
#endif

#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Cache.h>

/* ========================================================================== */
/*                          IMPORTED VARIABLES                                */
/* ========================================================================== */


extern EDMA3_DRV_Handle hEdma;
extern HeapMem_Handle myHeap;
/* ========================================================================== */
/*                          MACRO DEFINITIONS                                 */
/* ========================================================================== */

/*
 * Buffers placed in external memory are aligned on a 128 bytes boundary.
 * In addition, the buffer should be of a size multiple of 128 bytes for
 * the cache work optimally on the C6x.
 */
#define BUFLEN                  (2*48000/1000) /* number of samples per serializer in the frame  */
#define BUFALIGN                128 /* alignment of buffer for use of L2 cache */

/* This is the number of buffers used by the application to be issued and reclaimed 
   This number can be higher than 2 (Ping pong) also. The McASP driver puts them in 
   a queue internally and process them in order and give back to the application */
#define NUM_BUFS                2

#if defined(AIC_CODEC)
#include <Aic31.h>
Ptr  hAicDev;
Ptr  hAicChannel;
#endif


/* Function prototype */
static Void createStreams();
static Void prime();

void SoundBufferPlay(void *pvBuffer, unsigned long ulEvent);
void SoundBufferRec(void *pvBuffer, unsigned long ulEvent);

Ptr rxbuf[NUM_BUFS];
Ptr txbuf[NUM_BUFS];

/* McASP Device handles */
Ptr  hMcaspDev;

/* McASP Device parameters */
Mcasp_Params mcaspParams;


/* Channel Handles */
Ptr hMcaspTxChan;
Ptr hMcaspRxChan;

int rxFrameIndex=(NUM_BUFS-1), txFrameIndex=(NUM_BUFS-1);
volatile int RxFlag=0,TxFlag=0;
Semaphore_Handle semR,semT;
Semaphore_Params params;

Error_Block eb;
/**************************************************************************************/
/*   FUNCTION DESCRIPTION: This utility function converts local GEM L2 address in to global
    memory addresses used by the EDMA inside McASP
*/
/**************************************************************************************/
static uint32_t getGlobalAddr (uint32_t addr)
{
    if ((addr >= 0x800000) && (addr < 0x1000000))
    {
#ifdef _TMS320C6X
        uint32_t coreNum;

        /* Get the core number. */
        coreNum = CSL_chipReadReg(CSL_CHIP_DNUM);

#if defined(SOC_AM572x) || defined(SOC_AM571x)
        /* Compute the global address. */
        return ((1 << 30) | (coreNum << 24) | (addr & 0x00ffffff));

#else
  /* Compute the global address. */
        return ((1 << 28) | (coreNum << 24) | (addr & 0x00ffffff));
#endif
#else
        return addr;
#endif
    }
    else
    {
        /* non-L2 address range */
        return addr;
    }
}
/*********************** APPLICATION DEFINED FUNCTIONS: Begin ****************************/
/* The below functions need to be defined by the application and are registered to the
   McASP driver during instantiation 
 */
/*
 * This call back function is provided to the McASP driver during mcaspCreateChan()
 * and is called at the end of a transaction. This example uses the same call back function
 * for both TX and RX transfers and the call back argument is not being used in this
 * application and hence we pass NULL during mcaspCreateChan() as the call back argument.
 * This need not be the case for other applications where they could use a seperate
 * call back function for TX and RX. Also they could provide a non-NULL argument as
 * the call back argument and use it in their implementation of the call back function(s).
 */
void mcaspAppCallback(void* arg, MCASP_Packet *ioBuf)
{

	if(ioBuf->cmd == MCASP_READ)
	{
		RxFlag++;
		rxFrameIndex=((rxFrameIndex+1) %NUM_BUFS);

		if(ioBuf->addr != (void *)getGlobalAddr((uint32_t)rxbuf[rxFrameIndex])) {
		   MCASP_log("Rx Buf Address mismatch\n");
		}
	/* post semaphore */
	Semaphore_post(semR);
	}
	if(ioBuf->cmd == MCASP_WRITE)
		{
		txFrameIndex=((txFrameIndex+1) % NUM_BUFS);
		if(ioBuf->addr != (void *)getGlobalAddr((uint32_t)txbuf[txFrameIndex])) {
			MCASP_log("Tx Buf Address mismatch\n");
		}
		TxFlag++;
		/* post semaphore */
		Semaphore_post(semT);
		}

}
/*
 * This call back is used during interrupt processing and is defined by the
 * application for error handling. These functions are called back from within the
 * mcasp driver when an error interrupt happens and macspIsr() is being called.
 * The sample error handling functions just records these errors which
 * are later used for analyzing the errors seen.
 */
/* The below variables are used to quit the frame processing loop if an error occurs */
int gblErrFlagXmt=0;
int gblErrFlagRcv=0;
/* The below variables are used to analyze the errors if an error interrupt happens */
Mcasp_errCbStatus errCbStatusXmt;
Mcasp_errCbStatus errCbStatusRcv;

/* Error handler for Transmit side */
void GblErrXmt(Mcasp_errCbStatus errCbStat)
{
	gblErrFlagXmt=1;
	errCbStatusXmt=errCbStat;
}
/* Error handler for Rcv side */
void GblErrRcv(Mcasp_errCbStatus errCbStat)
{
    gblErrFlagRcv=1;
    errCbStatusRcv=errCbStat;
}
/*********************** APPLICATION DEFINED FUNCTIONS: End ****************************/




/**************************************************************************************/
/* FUNCTION DESCRIPTION: This function analyzes the result of error interrupts, if it
 * happened
*/
/**************************************************************************************/	 
void mcaspAnalyzeErrors(Mcasp_errCbStatus *errCbStat)
{
    MCASP_log("\n------------ Error stats --------------\n");
    MCASP_log("*****  isClkFailErr : %d\n",errCbStat->isClkFailErr);
    MCASP_log("*****  isDMAErr    : %d\n",errCbStat->isDMAErr);
    MCASP_log("*****  isSyncErr   : %d\n",errCbStat->isSyncErr);
    MCASP_log("*****  retVal      : %d \n",errCbStat->retVal);
    MCASP_log("*****  isRcvOvrRunOrTxUndRunErr : %d \n",errCbStat->isRcvOvrRunOrTxUndRunErr);
}

extern Int aic31SetVolume(Ptr devp, uint8_t volume);

/**************************************************************************************/
/* Routine to update/adjust the codec volume                                          */
/**************************************************************************************/
void mcaspUpdateVolume(uint8_t volume)
{
	aic31SetVolume(hAicDev, volume);
}

/**************************************************************************************/
/* Sample Watchdog routine for parsing errors */
/**************************************************************************************/
void ErrorWatchDogRoutine()
{
    Mcasp_errCbStatus errCbStat_Xmt;
    Mcasp_errCbStatus errCbStat_Rcv;

    /* Query the transmit channel's error stat */
    mcaspControlChan(hMcaspTxChan,Mcasp_IOCTL_CHAN_QUERY_ERROR_STATS,&errCbStat_Xmt);
    mcaspControlChan(hMcaspTxChan,Mcasp_IOCTL_CHAN_QUERY_ERROR_STATS,&errCbStat_Rcv);

    /* For testing purpose, just print the contents. Application may choose to run this in
     * a background task and take action. In this example we are just printing the error */
    MCASP_log("\n\n******************* Transmit Watch dog stats ****************");
    mcaspAnalyzeErrors(&errCbStat_Xmt);

    MCASP_log("\n\n******************* Receive Watch dog stats ****************");
    mcaspAnalyzeErrors(&errCbStat_Rcv);
}

/**************************************************************************************/
/*   FUNCTION DESCRIPTION: This function creates the McASP channels for Tx and Rx 
     This function also creates the codec channels (if any)
*/
/**************************************************************************************/	 
static Void createStreams()
{
	int status;

    int mode = IOM_INPUT;
	char remName[10]="aic";
#if !defined(MCASP_MASTER)
/* Configure the external clock: In Slave mode, McASP is not the master, start initializing the external clock provider (AIC codec below),
   before configuring McASP clocks (in mcaspCreateChan() below) 
*/
#if defined(AIC_CODEC)
/* In this case AIC provides the frame clocks, hence we need to start it first */
	status = aic31MdCreateChan(
		&hAicChannel,
		hAicDev,
		remName,
		mode,
		(Ptr)(&AIC31_config),
		(IOM_TiomCallback)mcaspAppCallback,
		NULL);

	if ((NULL == hAicChannel) &&
			(IOM_COMPLETED != status))
	{
		MCASP_log("AIC Create Channel Failed\n");
		BIOS_exit(0);
	}
#endif
	
#endif
	
	
	mcasp_chanparam[0].edmaHandle = hEdma;
    mcasp_chanparam[1].edmaHandle = hEdma;

	/* Create Mcasp channel for Tx */
	status = mcaspCreateChan(&hMcaspTxChan, hMcaspDev,
							 MCASP_OUTPUT,
							 &mcasp_chanparam[1],
							 mcaspAppCallback, NULL);

	if((status != MCASP_COMPLETED) || (hMcaspTxChan == NULL))
	{
		MCASP_log("mcaspCreateChan for McASP2 Tx Failed\n");
		UART_printStatus("\n Some tests have failed.\n");
		BIOS_exit(0);
	}

	/* Create Mcasp channel for Rx */
	status = mcaspCreateChan(&hMcaspRxChan, hMcaspDev,
	                         MCASP_INPUT,
	                         &mcasp_chanparam[0],
	                         mcaspAppCallback, NULL);
	if((status != MCASP_COMPLETED) || (hMcaspRxChan == NULL))
	{
		MCASP_log("mcaspCreateChan for McASP2 Rx Failed\n");
		UART_printStatus("\n Some tests have failed.\n");
		BIOS_exit(0);
	}
#if defined(MCASP_MASTER) 
/* If MCASP master, configure the clock of the slave device attached to McASP now.
    In the below case, it is the AIC codec */

#if defined(AIC_CODEC)
	status = aic31MdCreateChan(
		&hAicChannel,
		hAicDev,
		remName,
		mode,
		(Ptr)(&AIC31_config),
		(IOM_TiomCallback)&mcaspAppCallback,
		NULL);

	if ((NULL == hAicChannel) &&
			(IOM_COMPLETED != status))
	{
		MCASP_log("AIC Create Channel Failed\n");
	}
	else
	{

	}
#endif

#endif

}

/*
 * ======== prime ========
 */
MCASP_Packet rxFrame[NUM_BUFS];
MCASP_Packet txFrame[NUM_BUFS];
#include <ti/sysbios/family/c64p/Hwi.h>

Hwi_Handle myHwi;
static Void prime()
{
	Error_Block  eb;
    int32_t        count = 0, status;
    IHeap_Handle iheap;
    uint32_t tx_bytes_per_sample=(mcasp_chanparam[1].wordWidth/8);
    uint32_t rx_bytes_per_sample=(mcasp_chanparam[0].wordWidth/8);
    /* This represents the actual  number of bytes being transferred by the
     * DMA to/from the Host memory to the McASP peripheral. This include all serializers and timeslots.
     * BUFLEN contains the samples per serializer (inclusive of its timeslots) */
    uint32_t tx_frame_size = BUFLEN*TX_NUM_SERIALIZER*tx_bytes_per_sample;
    uint32_t rx_frame_size = BUFLEN*RX_NUM_SERIALIZER*rx_bytes_per_sample;

    iheap = HeapMem_Handle_to_xdc_runtime_IHeap(myHeap);
    Error_init(&eb);

    /* Allocate buffers for the SIO buffer exchanges                          */
    for(count = 0; count < (NUM_BUFS ); count ++)
    {
        rxbuf[count] = Memory_calloc(iheap, rx_frame_size,BUFALIGN, &eb);
        if(NULL == rxbuf[count])
        {
            MCASP_log("\r\nMEM_calloc failed.\n");
        }
    }

    /* Allocate buffers for the SIO buffer exchanges                          */
    for(count = 0; count < (NUM_BUFS); count ++)
    {
        txbuf[count] = Memory_calloc(iheap, tx_frame_size,BUFALIGN, &eb);
        if(NULL == txbuf[count])
        {
            MCASP_log("\r\nMEM_calloc failed.\n");
        }
    }

    for(count = 0; count < NUM_BUFS; count ++)
    {
            /* Issue the first & second empty buffers to the input stream         */
	    memset((uint8_t *)rxbuf[count], (0xB0+count), rx_frame_size);
			/* RX frame processing */
			rxFrame[count].cmd = MCASP_READ;
			rxFrame[count].addr = (void*)(getGlobalAddr((uint32_t)rxbuf[count]));
		rxFrame[count].size = rx_frame_size;
			rxFrame[count].arg = (uint32_t) hMcaspRxChan;
			rxFrame[count].status = 0;
			rxFrame[count].misc = 1;   /* reserved - used in callback to indicate asynch packet */

		/* Submit McASP packet for Rx */
		status = mcaspSubmitChan(hMcaspRxChan, &(rxFrame[count]));
		if((status != MCASP_PENDING))
			MCASP_log ("Debug: Error McASP2 RX : Prime  buffer  #%d submission FAILED\n", count);


    }
    for(count = 0; count < (NUM_BUFS); count ++)
       {

	     memset((uint8_t *)txbuf[count], (0xA0+count), tx_frame_size);
   			/* TX frame processing */
   			txFrame[count].cmd = MCASP_WRITE;
   			txFrame[count].addr = (void*)(getGlobalAddr((uint32_t)txbuf[count]));
		txFrame[count].size = tx_frame_size;
   			txFrame[count].arg = (uint32_t) hMcaspTxChan;
   			txFrame[count].status = 0;
   			txFrame[count].misc = 1;   /* reserved - used in callback to indicate asynch packet */
   		/* Submit McASP packet for Tx */
   		status = mcaspSubmitChan(hMcaspTxChan, &(txFrame[count]));
   		if((status != MCASP_PENDING))
   			MCASP_log ("Debug: Error McASP2 TX : Prime  buffer  #%d submission FAILED\n", count);
       }

}

extern EDMA3_DRV_GblConfigParams sampleEdma3GblCfgParams[];
/* EnableEDMA event in the SampleCfg*/
static void enableEDMAHwEvent(uint32_t edmaNum, uint32_t eventNo) {
  sampleEdma3GblCfgParams[edmaNum].dmaChannelHwEvtMap[eventNo/32] |= (1 << (eventNo%32));
}

/*
 * ======== echo ========
 * This function copies from the input SIO to the output SIO. You could
 * easily replace the copy function with a signal processing algorithm.
 */
extern Int aic31MdBindDev(Ptr *, Int, Ptr);

int gtxFrameIndexCount=0;
int grxFrameIndexCount=0;
int itemp;
int result, pwr_status, fs_status, bck_status;
int total_frames_sent=0;

/* For the loopback test,  we send a finite number of frames and test for ramp correctness.
   For other audio tests and the default case, the number of frames is infinite */
#ifdef DEVICE_LOOPBACK
#define NUM_TEST_FRAMES 100
#endif

Void Audio_echo_Task()
{
    volatile int32_t i32Count, status = 0;
	hMcaspDev  = NULL;
    uint32_t tx_bytes_per_sample=(mcasp_chanparam[1].wordWidth/8);
    uint32_t rx_bytes_per_sample=(mcasp_chanparam[0].wordWidth/8);
    /* This represents the actual  number of bytes being transferred by the
     * DMA to/from the Host memory to the McASP peripheral. This include all serializers and timeslots.
     * BUFLEN contains the samples per serializer (inclusive of its timeslots) */
    uint32_t tx_frame_size = BUFLEN*TX_NUM_SERIALIZER*tx_bytes_per_sample;
    uint32_t rx_frame_size = BUFLEN*RX_NUM_SERIALIZER*rx_bytes_per_sample;

#ifdef MEASURE_TIME
	profiling_init();
#endif

    MCASP_log("\n******** Audio Loopback demo ********\n");
    MCASP_log("Send audio signals in to the EVM's audio-in port and hear the same audio in the audio-out port\n");

    /* 1. EDMA Initializations */
    EDMA3_DRV_Result edmaResult = 0;

	enableEDMAHwEvent(EDMACC_NUM,MCASP_RX_DMA_CH);
    enableEDMAHwEvent(EDMACC_NUM,MCASP_TX_DMA_CH);
	
    hEdma = edma3init(EDMACC_NUM, &edmaResult);

    if (edmaResult != EDMA3_DRV_SOK)
        {
            /* Report EDMA Error
             */
            MCASP_log("\nEDMA driver initialization unsuccessful\n");
        }
        else
        {
           MCASP_log("\nEDMA driver initialization successful.\n");
        }

	/* 2. SEM Initializations */
    Semaphore_Params_init(&params);

	/* Create semaphores to wait for buffer reclaiming */
    semR = Semaphore_create(0, &params, &eb);
    semT = Semaphore_create(0, &params, &eb);

	/* 3. McASP Initializations */
	/* Initialize McASP Tx and Rx parameters */

	mcaspParams = Mcasp_PARAMS;


#ifdef DEVICE_LOOPBACK
/* Enable MCASP DLB mode */
	mcaspParams.mcaspHwSetup.glb.dlbMode=(CSL_MCASP_DLBCTL_DLBEN_ENABLE |
										 ( CSL_MCASP_DLBCTL_ORD_XMTEVEN << CSL_MCASP_DLBCTL_ORD_SHIFT) |
										 ( CSL_MCASP_DLBCTL_MODE_XMTCLK << CSL_MCASP_DLBCTL_MODE_SHIFT) );

#endif

	status = mcaspBindDev(&hMcaspDev, MCASP_NUM, &mcaspParams);
	if((status != MCASP_COMPLETED) || (hMcaspDev == NULL))
	{
		MCASP_log("mcaspBindDev for McASP Failed\n");
		UART_printStatus("\n Some tests have failed.\n");
		abort();
	}

#if defined(AIC_CODEC)
	/* Bind AIC Codec */
    aic31MdBindDev(&hAicDev, 0, (Ptr)&Aic31_PARAMS);
#endif

    /* Call createStream function to create I/O streams                       */
    createStreams();

    MCASP_log("Initialization complete. priming about to begin \n");
    UART_printStatus("\n All tests have passed.\n");
    /* Call prime function to do priming                                      */
    prime();

    MCASP_log("priming complete.\n");

#if defined(DEVICE_LOOPBACK)
    /* Configure the Device loopback test's paramters such as loopback mask */
    config_deviceloopback(tx_frame_size,rx_frame_size);
#endif

    /* Forever loop to continously receviec and transmit audio data           */
    for (i32Count = 0; i32Count >= 0; i32Count++)
    {

    	if(gblErrFlagXmt || gblErrFlagRcv)
    		break;

#if defined(DEVICE_LOOPBACK)
    	dlb_process_events();
#endif
    	Semaphore_pend(semR, BIOS_WAIT_FOREVER);
    	Semaphore_pend(semT, BIOS_WAIT_FOREVER);

#ifdef MEASURE_TIME
    profiling_end();  
#endif
/* For Device loopback test (ramp) we send a fininte number of frames. For other tests and 
   the default case, the number of frames is inifinite and the demo never exits out of 
   the for loop */
#if defined(DEVICE_LOOPBACK)
        if(total_frames_sent==NUM_TEST_FRAMES)
        	break;
#endif

    	/* Reclaim full buffer from the input stream                          */
    	gtxFrameIndexCount=txFrameIndex;
    	grxFrameIndexCount=rxFrameIndex;

    	Cache_inv((void *)((uint8_t *)rxbuf[grxFrameIndexCount]),rx_frame_size,Cache_Type_ALL, TRUE);
        /******************************* Sample Processing Begins ***************************/
	    /* (BUFLEN* RX_NUM_SERIALIZER) 32-bit samples samples have been accumulated in rxbuf[grxFrameIndexCount] now.
	       Application specific processing on these samples, before sending it back to McASP via 
	       txbuf[grxFrameIndexCount].
		   APPLICATION SPECIFIC PROCESSING could be done here. Below are the few audio demos and their
		   application specific processing shown below.
	    */
        /* DEFAULT CASE: Copy the frame received and send it back to Tx buffer.
		   This way the audio received by McASP from the remote device, is loopbacked and sent back
		   to the device here.
		*/
   		///memcpy((void *)((uint8_t *)txbuf[gtxFrameIndexCount]),(void *)((uint8_t *)rxbuf[grxFrameIndexCount]),rx_frame_size);

        /* USB Audio Class CASE: Copy the frame received from the USB Host via ISOC OUT and send it back to Tx buffer.
 		   This way the audio received by USB Device from the USB Host, is played back to
 		   the audio codec here.
 		*/
    	SoundBufferPlay(txbuf[gtxFrameIndexCount], 0);

        /* USB Audio Class CASE: Copy the frame received from the Audio Codec and send it to RX circular buffers.
 		   Whenthe USB Host request recording, the content in the RX circular buffers will be sent to the USB Host
 		   via ISOC IN
 		*/
       	SoundBufferRec(rxbuf[grxFrameIndexCount], 0);

    	/******************************* Sample Processing End ***************************/
        
   		Cache_wbInv((void *)((uint8_t *)txbuf[gtxFrameIndexCount]),tx_frame_size,Cache_Type_ALL, TRUE);

        /* Issue full buffer to the output stream                             */
        /* TX frame processing */
		txFrame[gtxFrameIndexCount].cmd = MCASP_WRITE;
		txFrame[gtxFrameIndexCount].addr = (void*)getGlobalAddr((uint32_t)txbuf[gtxFrameIndexCount]);
		txFrame[gtxFrameIndexCount].size = tx_frame_size;
		txFrame[gtxFrameIndexCount].arg = (uint32_t) hMcaspTxChan;
		txFrame[gtxFrameIndexCount].status = 0;
		txFrame[gtxFrameIndexCount].misc = 1;   /* reserved - used in callback to indicate asynch packet */

		status = mcaspSubmitChan(hMcaspTxChan, &(txFrame[gtxFrameIndexCount]));
		if((status != MCASP_PENDING))
			MCASP_log ("Debug: Error McASP TX : Prime  buffer  #%d submission FAILED\n", i32Count);

		/* Issue an empty buffer to the input stream                          */
		rxFrame[grxFrameIndexCount].cmd = MCASP_READ;
		rxFrame[grxFrameIndexCount].addr = (void*)getGlobalAddr((uint32_t)rxbuf[grxFrameIndexCount]);
		rxFrame[grxFrameIndexCount].size = rx_frame_size;
		rxFrame[grxFrameIndexCount].arg = (uint32_t) hMcaspRxChan;
		rxFrame[grxFrameIndexCount].status = 0;
		rxFrame[grxFrameIndexCount].misc = 1;   /* reserved - used in callback to indicate asynch packet */

		status = mcaspSubmitChan(hMcaspRxChan, &(rxFrame[grxFrameIndexCount]));
		if((status != MCASP_PENDING))
			MCASP_log ("Debug: Error McASP RX :  buffer  #%d submission FAILED\n", i32Count);

#ifdef MEASURE_TIME
		profiling_start();
#endif
		total_frames_sent++;
		
}
       
  	    MCASP_log("\nTotal %d frames sent",total_frames_sent);
  	    ErrorWatchDogRoutine();
  	    if(gblErrFlagXmt) {
  	       MCASP_log("\n Transmit ERROR occured\n");
  	       mcaspAnalyzeErrors(&errCbStatusXmt);
    	}

        if(gblErrFlagRcv) {
            MCASP_log("\n Receive ERROR occured\n");
            mcaspAnalyzeErrors(&errCbStatusRcv);
    	}

#if defined(DEVICE_LOOPBACK) && defined(TEST_ERROR_ISR_INVOCATION)
        {
            /* The below can be used to manually check the error ISR call back invocation.
             * The below ioctl command disables the device loopback forcefully.
             * Consequently Tx OverRun is triggered whose call back function is GlbErrXmt.
             * Put a CCS breakpoint at this function and watch it triggered.
             * Please note that the test may not recover from this state. */
            bool dlbMode=FALSE; /* Forcefully disable */
            Mcasp_localSubmitIoctl(hMcaspTxChan,Mcasp_IOCTL_SET_DLB_MODE,&dlbMode,NULL);
            Task_sleep(1000);
            /* The test should be hung by now after "Total 100 frames sent" */

        }
#endif
        MCASP_log("\nDeleting Rx channel");
        status = mcaspDeleteChan(hMcaspRxChan);
        MCASP_log("\nDeleting Tx channel");
        status = mcaspDeleteChan(hMcaspTxChan);
        MCASP_log("\nUnBinding Mcasp");
    	status = mcaspUnBindDev(hMcaspDev);

		{
			IHeap_Handle iheap;

			iheap = HeapMem_Handle_to_xdc_runtime_IHeap(myHeap);
			Error_init(&eb);
			for(i32Count = 0; i32Count < (NUM_BUFS); i32Count ++)
				{
					Memory_free(iheap,rxbuf[i32Count],rx_frame_size);
					Memory_free(iheap,txbuf[i32Count],tx_frame_size);
				}
		}
	  /* Display profiling results */	
#ifdef MEASURE_TIME
      profiling_display_results();
#endif

/* Application specific report(if any) */

#ifdef DEVICE_LOOPBACK
	/* Analyze and print results of the loopback test */
	if(total_frames_sent!=NUM_TEST_FRAMES) {
	   MCASP_log("\nTEST FAIL: Test quit after sending %d frames \n",total_frames_sent);
	}
	finish_deviceloopback();
#endif


    BIOS_exit(0);
}

