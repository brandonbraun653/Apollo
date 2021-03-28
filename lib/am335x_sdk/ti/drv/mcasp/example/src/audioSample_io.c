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

#if defined(SOC_AM65XX) || defined (SOC_J721E)
 #define MCASP_UDMA_ENABLED
#else
 #define MCASP_EDMA_ENABLED
#endif 


#if defined(MCASP_EDMA_ENABLED)
 #include <ti/sdo/edma3/drv/edma3_drv.h>
 #include <ti/sdo/edma3/rm/edma3_rm.h>
 #include <ti/sdo/edma3/drv/sample/bios6_edma3_drv_sample.h>
#elif defined(MCASP_UDMA_ENABLED)
 #include <ti/drv/udma/include/udma_types.h>
 #include <ti/drv/udma/udma.h>
#endif 

#include "mcasp_osal.h"
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include "ICodec.h"
#include "mcasp_cfg.h"
#include "MCASP_log.h"

#ifdef MCASP_ENABLE_DEBUG_LOG
#include "mcasp_debug.h"
#endif

#include "stdio.h"
#include "string.h"

#include <ti/csl/cslr_mcasp.h>
#ifdef MEASURE_TIME
  #include "profiling.h"
#endif

#ifdef DEVICE_LOOPBACK
  #include "deviceloopback.h"
#endif

#ifdef AUDIO_EQ_DEMO
  #include "audioEQ.h"
#endif

#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/hal/Cache.h>

/* ========================================================================== */
/*                          IMPORTED VARIABLES                                */
/* ========================================================================== */

extern const ti_sysbios_heaps_HeapMem_Handle myHeap;

#define max(x,y) ( ((x) > (y))?(x):(y) )
/* ========================================================================== */
/*                          MACRO DEFINITIONS                                 */
/* ========================================================================== */

/*
 * Buffers placed in external memory are aligned on a 128 bytes boundary.
 * In addition, the buffer should be of a size multiple of 128 bytes for
 * the cache work optimally on the C6x.
 */
#define BUFLEN                  (128) /* number of samples per serializer in the frame  */
#define BUFALIGN                128 /* alignment of buffer for use of L2 cache */

/* This is the number of buffers used by the application to be issued and reclaimed 
   This number can be higher than 2 (Ping pong) also. The McASP driver puts them in 
   a queue internally and process them in order and give back to the application */
#define UDMA_FIFO_DEPTH      (2)
#define NUM_BUFS                (2) /* For ping pong */

#if defined (MCASP_UDMA_ENABLED)
  /* 
   * For UDMAP/PDMA the prime count needs to be 4
   * */
  #define PRIME_COUNT                (2)
#else 
  #define PRIME_COUNT                (2)
#endif
  
#define TOTAL_PACKETS_TO_TRANSFER  (98+2) /* Including priming */
#define NUM_APP_BUFS_QUEUE_ENTRIES  max(PRIME_COUNT,NUM_BUFS)
#define MCASP_TEST_MAX_SERIALIZERS  (TX_NUM_SERIALIZER) /* defined in mcasp_cfg.h */
#define MCASPFRAMES_RX_SIZE        (BUFLEN*sizeof(uint32_t)*MCASP_TEST_MAX_SERIALIZERS)

/* Putting it here so it can be changed through emulator */
volatile uint32_t test_num_bufs = NUM_BUFS;
volatile uint32_t test_prime_count = PRIME_COUNT;

/* For the loopback test,  we send a finite number of frames and test for ramp correctness.
   For other audio tests and the default case, the number of frames is infinite */
#ifdef DEVICE_LOOPBACK
#define NUM_TEST_FRAMES (TOTAL_PACKETS_TO_TRANSFER - PRIME_COUNT)
#endif





#if defined(AIC_CODEC)
#include <Aic31.h>
Ptr  hAicDev;
Ptr  hAicChannel;
#endif

/* Function prototype */
static Void createStreams();
static Void prime();

Ptr rxbuf[NUM_BUFS];
Ptr txbuf[NUM_BUFS];

/* McASP Device handles */
Ptr  hMcaspDev;
#if defined(AUDIO_DC_DIGITAL_TEST)
Ptr  hMcaspDevDIT;

/* Data payload structures for DIT mode */
Mcasp_PktAddrPayload  ditPayload;
Mcasp_PktAddrPayload  *pDitPayload;
Mcasp_UserDataRam     ditUserData;
Mcasp_ChStatusRam     ditChStatus;
Mcasp_Params          mcaspDITParams;
#endif  /* #if defined(AUDIO_DC_DIGITAL_TEST) */


/* McASP Device parameters */
Mcasp_Params mcaspParams;


/* Channel Handles */
Ptr hMcaspTxChan;
Ptr hMcaspRxChan;

volatile int RxFlag=0,TxFlag=0;
Semaphore_Handle semR,semT;
Semaphore_Params params;
int mcaspApiTest = FALSE;

typedef struct McASP_App_Buffer_s {
	Osal_Queue_Elem  link;
	uintptr_t *buf;
	uint32_t index;
}McASP_App_BufferInfo_t;

/* For TX and RX */
typedef enum {
 APP_BUFFER_RX=0,
 APP_BUFFER_TX=1
}McASP_App_Buffer_Direction_e;

Osal_Queue_Elem McASP_App_Buffer_FreeList[2];
Osal_Queue_Elem McASP_App_Buffer_TransitList[2];

McASP_App_BufferInfo_t McASP_App_bufs[2][NUM_APP_BUFS_QUEUE_ENTRIES];

#ifdef MCASP_ENABLE_DEBUG_LOG
uint32_t mcaspFrames_rx[NUM_TEST_FRAMES+PRIME_COUNT][MCASPFRAMES_RX_SIZE/4];
uint8_t mcaspFrame_rx_index=0;
#endif

/* Initialize the queue of buffer info  and push them in to the free queues */
void McASP_App_BufferInfo_Init()
{
    uint32_t i,bufno;
	Osal_Queue_construct(&McASP_App_Buffer_FreeList[APP_BUFFER_RX], (void *)NULL);
	Osal_Queue_construct(&McASP_App_Buffer_TransitList[APP_BUFFER_RX], (void *)NULL);
	
	Osal_Queue_construct(&McASP_App_Buffer_FreeList[APP_BUFFER_TX], (void *)NULL);
	Osal_Queue_construct(&McASP_App_Buffer_TransitList[APP_BUFFER_TX], (void *)NULL);
	
    /* Put buffers in the queue */
	for(i=0;i<test_prime_count;i++) {
      /* For priming, we would need to put 'prime_count' number of buffers in to the Free List to begin with.
	   * During priming process, these will be popped and submitted to the McASP */
	    bufno= i%test_num_bufs;	/* There are only NUM_BUFS buffers allocated from memory. If more buffers are needed for priming, say 4, these 
	                                       buffers tx/rxBufs[NUM_BUFS]are to be re-used. */
	    McASP_App_bufs[APP_BUFFER_RX][i].buf = rxbuf[bufno];
	    McASP_App_bufs[APP_BUFFER_RX][i].index = bufno;
        Osal_Queue_put((Osal_Queue_handle(&McASP_App_Buffer_FreeList[APP_BUFFER_RX])),(Osal_Queue_Elem *)&McASP_App_bufs[APP_BUFFER_RX][i]);
      
	    McASP_App_bufs[APP_BUFFER_TX][i].buf = txbuf[bufno];
	    McASP_App_bufs[APP_BUFFER_TX][i].index = bufno;
        Osal_Queue_put((Osal_Queue_handle(&McASP_App_Buffer_FreeList[APP_BUFFER_TX])),(Osal_Queue_Elem *)&McASP_App_bufs[APP_BUFFER_TX][i]);
	}  
}
/* Pop a buffer not in use */
McASP_App_BufferInfo_t * McASP_App_Buffers_PopFree(McASP_App_Buffer_Direction_e dir)
{
  McASP_App_BufferInfo_t *ptr;
  ptr = Osal_Queue_get(&McASP_App_Buffer_FreeList[dir]);
  if(ptr!=NULL) {
    Osal_Queue_put((Osal_Queue_handle(&McASP_App_Buffer_TransitList[dir])),(Osal_Queue_Elem *)ptr);
  }
  return(ptr);
}

/* Get from the transit list */
McASP_App_BufferInfo_t * McASP_App_Buffers_PopTransitBuf(McASP_App_Buffer_Direction_e dir)
{
  McASP_App_BufferInfo_t *ptr;
  ptr = Osal_Queue_get(&McASP_App_Buffer_TransitList[dir]);
  return(ptr);
}
/* Release to free list */
void McASP_App_Buffers_Release(McASP_App_BufferInfo_t *bufQueueEntry,McASP_App_Buffer_Direction_e dir)
{
  Osal_Queue_put((Osal_Queue_handle(&McASP_App_Buffer_FreeList[dir])),(Osal_Queue_Elem *)bufQueueEntry);
}


Error_Block eb;

int mcaspControlChanTest(void * mcaspChan);

/**************************************************************************************/
/*   FUNCTION DESCRIPTION: This utility function converts local GEM L2 address in to global
    memory addresses used by the EDMA inside McASP
*/
/**************************************************************************************/
static uintptr_t getGlobalAddr (uintptr_t addr)
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

   McASP_App_BufferInfo_t *bufInfo_transit; /* The buffer in transit */
#ifdef MCASP_ENABLE_DEBUG_LOG
       uintptr_t *buf_ptr;
#endif

	if(ioBuf->cmd == MCASP_READ)
	{   
		RxFlag++;
		/* Get the buffer which is supposed to be the next. It should be in the transit queue */
        bufInfo_transit = McASP_App_Buffers_PopTransitBuf(APP_BUFFER_RX);      
		if(ioBuf->addr != (uintptr_t *)getGlobalAddr((uintptr_t)bufInfo_transit->buf)) {
#if !defined(AUDIO_DC_DIGITAL_TEST)
		   MCASP_log("Rx Buf Address mismatch on packet [%d] Expected %p, got %p with size %d\n",RxFlag,(uintptr_t *)getGlobalAddr((uintptr_t)bufInfo_transit->buf),ioBuf->addr,ioBuf->size);
#endif
#ifdef MCASP_ENABLE_DEBUG_LOG
           mcaspDebugLog(DEBUG_APP_CALLBACK_READ_MISMATCH, RxFlag,getGlobalAddr((uintptr_t)bufInfo_transit->buf),(uintptr_t)ioBuf->addr,ioBuf->size);
#endif
		}
  	     
#ifdef MCASP_ENABLE_DEBUG_LOG		
		buf_ptr = (uintptr_t *)getGlobalAddr((uintptr_t)ioBuf->addr);
       	mcaspDebugLog(DEBUG_APP_CALLBACK_READ, (uintptr_t)ioBuf->addr,ioBuf->size, buf_ptr[0],buf_ptr[1]);
#endif
        
        /* Release it back to the Free list */ 
        McASP_App_Buffers_Release(bufInfo_transit,APP_BUFFER_RX);

	    /* post semaphore */
	    Semaphore_post(semR);
	
	} else if(ioBuf->cmd == MCASP_WRITE)
		{
		 TxFlag++;
        
          /* Get the buffer which is supposed to be in the top of the list */
          bufInfo_transit = McASP_App_Buffers_PopTransitBuf(APP_BUFFER_TX);      
		  if(ioBuf->addr != (uintptr_t *)getGlobalAddr((uintptr_t)bufInfo_transit->buf)) {
#if !defined(AUDIO_DC_DIGITAL_TEST)
		     MCASP_log("Tx Buf Address mismatch on packet[%d] Expected %p, got %p with size %d\n",TxFlag,(uintptr_t *)getGlobalAddr((uintptr_t)bufInfo_transit->buf),ioBuf->addr,ioBuf->size);
#endif
#ifdef MCASP_ENABLE_DEBUG_LOG		     
             mcaspDebugLog(DEBUG_APP_CALLBACK_WRITE_MISMATCH, TxFlag,getGlobalAddr((uintptr_t)bufInfo_transit->buf),(uintptr_t)ioBuf->addr,ioBuf->size);
#endif             
		  }

#ifdef MCASP_ENABLE_DEBUG_LOG		  
		  buf_ptr = (uintptr_t *)getGlobalAddr((uintptr_t)ioBuf->addr);
       	  mcaspDebugLog(DEBUG_APP_CALLBACK_WRITE, (uintptr_t)ioBuf->addr,ioBuf->size, buf_ptr[0], buf_ptr[1]);
#endif
          /* Release it back to the Free list */ 
          McASP_App_Buffers_Release(bufInfo_transit,APP_BUFFER_TX);
        
		  /* post semaphore */
		  Semaphore_post(semT);
		} else {
  		  MCASP_log("Callback: Spurious packet ! Buff addr = %p with size %d",ioBuf->addr,ioBuf->size);
#ifdef MCASP_ENABLE_DEBUG_LOG  		  
		  mcaspDebugLog(DEBUG_APP_CALLBACK_SPURIOUS, ioBuf->cmd,(uintptr_t)ioBuf->addr,ioBuf->size,MCASP_DEBUG_UNDEFINED);
#endif		  
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

#if defined(AIC_CODEC)    
  	char remName[10]="aic";
	int mode = IOM_INPUT;
#endif	
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
		mcaspAppCallback,
		NULL);

	if ((NULL == hAicChannel) &&
			(IOM_COMPLETED != status))
	{
		MCASP_log("AIC Create Channel Failed\n");
		BIOS_exit(0);
	}
#endif
	
#endif
	
#if defined(AUDIO_DC_DIGITAL_TEST)
	/* Create Mcasp channel for Tx */
	status = mcaspCreateChan(&hMcaspTxChan, hMcaspDevDIT,
							 MCASP_OUTPUT,
							 &mcasp_chanparam[1],
							 mcaspAppCallback, NULL);
#else
	/* Create Mcasp channel for Tx */
	status = mcaspCreateChan(&hMcaspTxChan, hMcaspDev,
							 MCASP_OUTPUT,
							 &mcasp_chanparam[1],
							 mcaspAppCallback, NULL);
#endif

	if((status != MCASP_COMPLETED) || (hMcaspTxChan == NULL))
	{
		MCASP_log("mcaspCreateChan for McASP2 Tx Failed\n");
		BIOS_exit(0);
	}

#ifdef MCASP_ENABLE_DEBUG_LOG    
    mcaspDebugLog(DEBUG_APP_AFTER_TX_CREATECHAN, MCASP_DEBUG_UNDEFINED, MCASP_DEBUG_UNDEFINED, MCASP_DEBUG_UNDEFINED,MCASP_DEBUG_UNDEFINED);
#endif    

	/* Create Mcasp channel for Rx */
	status = mcaspCreateChan(&hMcaspRxChan, hMcaspDev,
	                         MCASP_INPUT,
	                         &mcasp_chanparam[0],
	                         mcaspAppCallback, NULL);
	if((status != MCASP_COMPLETED) || (hMcaspRxChan == NULL))
	{
		MCASP_log("mcaspCreateChan for McASP2 Rx Failed\n");
		BIOS_exit(0);
	}
#ifdef MCASP_ENABLE_DEBUG_LOG    
    mcaspDebugLog(DEBUG_APP_AFTER_RX_CREATECHAN, MCASP_DEBUG_UNDEFINED, MCASP_DEBUG_UNDEFINED, MCASP_DEBUG_UNDEFINED,MCASP_DEBUG_UNDEFINED);
#endif



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
MCASP_Packet rxFrame[NUM_APP_BUFS_QUEUE_ENTRIES];
MCASP_Packet txFrame[NUM_APP_BUFS_QUEUE_ENTRIES];

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
    uint32_t tx_frame_size = BUFLEN*mcasp_chanparam[1].noOfSerRequested*tx_bytes_per_sample;
    uint32_t rx_frame_size = BUFLEN*mcasp_chanparam[0].noOfSerRequested*rx_bytes_per_sample;
    McASP_App_BufferInfo_t *appBuf_ptr;

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
    for(count = 0; count < test_num_bufs; count ++)
    {
        txbuf[count] = Memory_calloc(iheap, tx_frame_size,BUFALIGN, &eb);
        if(NULL == txbuf[count])
        {
            MCASP_log("\r\nMEM_calloc failed.\n");
        }
    }

#ifdef MCASP_ENABLE_DEBUG_LOG
    memset(mcaspFrames_rx,0xBB,sizeof(mcaspFrames_rx));
#endif
    
    McASP_App_BufferInfo_Init();

#ifdef AUDIO_EQ_DEMO
    audioEQ_allocate_bufs(iheap,rx_frame_size,BUFALIGN);
#endif
    for(count = 0; count < test_prime_count; count ++)
    {
            /* Pop a free application buffer */
            appBuf_ptr=McASP_App_Buffers_PopFree(APP_BUFFER_RX);
            /* Issue the first & second empty buffers to the input stream         */
	        memset((uint8_t *)appBuf_ptr->buf, (0xB0+count), rx_frame_size);
    
			/* RX frame processing */
			rxFrame[count].cmd = MCASP_READ;
			rxFrame[count].addr = (void*)(getGlobalAddr((uintptr_t)appBuf_ptr->buf));
 		    rxFrame[count].size = rx_frame_size;
			rxFrame[count].arg = (uintptr_t) hMcaspRxChan;
			rxFrame[count].status = 0;
			rxFrame[count].misc = 1;   /* reserved - used in callback to indicate asynch packet */

#ifdef MCASP_ENABLE_DEBUG_LOG    
		   /* Submit McASP packet for Rx */
  	       mcaspDebugLog(DEBUG_APP_SUBMIT_READ, (uintptr_t)rxFrame[count].addr, rxFrame[count].size,((uint32_t *)(rxFrame[count].addr))[0],((uint32_t *)(rxFrame[count].addr))[1]);
#endif
		   status = mcaspSubmitChan(hMcaspRxChan, &(rxFrame[count]));

#ifdef MCASP_ENABLE_DEBUG_LOG    
      	   mcaspDebugLog(DEBUG_APP_SUBMIT_READ_COMPLETE, (uintptr_t)rxFrame[count].addr, rxFrame[count].size, ((uint32_t *)(rxFrame[count].addr))[0],((uint32_t *)(rxFrame[count].addr))[1]);
#endif
	
		if((status != MCASP_PENDING))
			MCASP_log ("Debug: Error McASP2 RX : Prime  buffer  #%d submission FAILED\n", count);


    }
    for(count = 0; count < (test_prime_count); count ++)
    {
         /* Pop a free application buffer */
         appBuf_ptr=McASP_App_Buffers_PopFree(APP_BUFFER_TX);
	     memset((uint8_t *)appBuf_ptr->buf, (0xA0+count), tx_frame_size);
#if defined(AUDIO_DC_DIGITAL_TEST)
         pDitPayload->addr = (uint32_t *)getGlobalAddr((uintptr_t)appBuf_ptr->buf);
#endif
   			/* TX frame processing */
		 txFrame[count].cmd = MCASP_WRITE;
#if defined(AUDIO_DC_DIGITAL_TEST)
         txFrame[count].addr = (void*)(pDitPayload);
#else
         txFrame[count].addr = (void*)(getGlobalAddr((uintptr_t)appBuf_ptr->buf));
#endif
		 txFrame[count].size = tx_frame_size;
	 
   		 txFrame[count].arg = (uintptr_t) hMcaspTxChan;
   		 txFrame[count].status = 0;
   		 txFrame[count].misc = 1;   /* reserved - used in callback to indicate asynch packet */

#ifdef MCASP_ENABLE_DEBUG_LOG    
   		 /* Submit McASP packet for Tx */
 	     mcaspDebugLog(DEBUG_APP_SUBMIT_WRITE, (uintptr_t)txFrame[count].addr, txFrame[count].size, ((uint32_t *)(txFrame[count].addr))[0],((uint32_t *)(txFrame[count].addr))[1]);
#endif

   		status = mcaspSubmitChan(hMcaspTxChan, &(txFrame[count]));
   		if((status != MCASP_PENDING))
   			MCASP_log ("Debug: Error McASP2 TX : Prime  buffer  #%d submission FAILED\n", count);
#ifdef MCASP_ENABLE_DEBUG_LOG 
		mcaspDebugLog(DEBUG_APP_SUBMIT_WRITE_COMPLETE, (uintptr_t)txFrame[count].addr, txFrame[count].size, ((uint32_t *)(txFrame[count].addr))[0],((uint32_t *)(txFrame[count].addr))[1]);
#endif
     }

}

#if defined(MCASP_EDMA_ENABLED)
extern EDMA3_DRV_GblConfigParams sampleEdma3GblCfgParams[];
/* EnableEDMA event in the SampleCfg*/
static void enableEDMAHwEvent(uint32_t edmaNum, uint32_t eventNo) {
  sampleEdma3GblCfgParams[edmaNum].dmaChannelHwEvtMap[eventNo/32] |= (1 << (eventNo%32));
}

EDMA3_DRV_Handle McaspApp_edmaInit(Mcasp_HwInfo *cfg)
{
    EDMA3_DRV_Handle hEdma;
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

    return hEdma;
}
#else
/*
 * Ring parameters
 */
/** \brief Number of ring entries - we can prime this much memcpy operations */
#define UDMA_TEST_APP_RING_ENTRIES      (UDMA_FIFO_DEPTH)
/** \brief Size (in bytes) of each ring entry (Size of pointer - 64-bit) */
#define UDMA_TEST_APP_RING_ENTRY_SIZE   (sizeof(uint64_t))
/** \brief Total ring memory */
#define UDMA_TEST_APP_RING_MEM_SIZE     (UDMA_TEST_APP_RING_ENTRIES *  \
                                         UDMA_TEST_APP_RING_ENTRY_SIZE)
/**
 *  \brief UDMA host mode buffer descriptor memory size.
 *  Make it multiple of 128 byte alignment
 */
#define UDMA_TEST_APP_DESC_SIZE         (sizeof(CSL_UdmapCppi5HMPD) + (128U - sizeof(CSL_UdmapCppi5HMPD)))
#define UDMA_TEST_NUM_DESCS             (2)
/*
 * UDMA driver objects
 */
struct Udma_DrvObj      gUdmaDrvObj;
struct Udma_ChObj       gUdmaTxChObj;
struct Udma_ChObj       gUdmaRxChObj;
struct Udma_EventObj    gUdmaTxCqEventObj;
struct Udma_EventObj    gUdmaTdTxCqEventObj;
struct Udma_EventObj    gUdmaRxCqEventObj;
struct Udma_EventObj    gUdmaTdRxCqEventObj;

Udma_DrvHandle          gDrvHandle = NULL;
/*
 * UDMA Memories
 */
#define UDMA_TEST_APP_RING_MEM_SIZE_ALIGN ((UDMA_TEST_APP_RING_MEM_SIZE + UDMA_CACHELINE_ALIGNMENT) & ~(UDMA_CACHELINE_ALIGNMENT - 1U))
uint8_t gTxRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
uint8_t gTxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
uint8_t gTdTxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
uint8_t gUdmaTxHpdMem[MCASP_NUM_FREE_DESCS][UDMA_TEST_APP_DESC_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));

uint8_t gRxRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
uint8_t gRxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
uint8_t gTdRxCompRingMem[UDMA_TEST_APP_RING_MEM_SIZE_ALIGN] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));
uint8_t gUdmaRxHpdMem[MCASP_NUM_FREE_DESCS][UDMA_TEST_APP_DESC_SIZE] __attribute__((aligned(UDMA_CACHELINE_ALIGNMENT)));

Udma_DrvHandle McaspApp_udmaInit(Mcasp_HwInfo *cfg)
{
    int32_t         retVal = UDMA_SOK;
    Udma_InitPrms   initPrms;
    uint32_t        instId;
    int32_t i;

    if (gDrvHandle == NULL)
    {
        /* UDMA driver init */
#if defined (SOC_J721E) && defined (BUILD_MCU1_0)
        instId = UDMA_INST_ID_MCU_0;
#else
        instId = UDMA_INST_ID_MAIN_0;
#endif
        UdmaInitPrms_init(instId, &initPrms);
        retVal = Udma_init(&gUdmaDrvObj, &initPrms);
        if(UDMA_SOK == retVal)
        {
            gDrvHandle = &gUdmaDrvObj;
        }
    }

    if(gDrvHandle != NULL)
    {
        gDrvHandle = &gUdmaDrvObj;
        cfg->dmaInfo.descType =      CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR; 
        cfg->dmaInfo.txChHandle     = &gUdmaTxChObj;
        cfg->dmaInfo.rxChHandle     = &gUdmaRxChObj;
        cfg->dmaInfo.txRingMem      = (void *)&gTxRingMem[0];
        cfg->dmaInfo.cqTxRingMem    = (void *)&gTxCompRingMem[0];
        cfg->dmaInfo.tdCqTxRingMem  = (void *)&gTdTxCompRingMem[0];
        cfg->dmaInfo.rxRingMem      = (void *)&gRxRingMem[0];
        cfg->dmaInfo.cqRxRingMem    = (void *)&gRxCompRingMem[0];
        cfg->dmaInfo.tdCqRxRingMem  = (void *)&gTdRxCompRingMem[0];
        cfg->dmaInfo.ringCnt  = UDMA_TEST_APP_RING_ENTRIES;
        
       for(i=0;i<MCASP_NUM_FREE_DESCS;i++) {
         cfg->dmaInfo.txHpdMem[i]    = (void *)&gUdmaTxHpdMem[i];
         cfg->dmaInfo.rxHpdMem[i]    = (void *)&gUdmaRxHpdMem[i];
       } 
        
        cfg->dmaInfo.txEventHandle  = (void *)&gUdmaTxCqEventObj;
        cfg->dmaInfo.tdTxEventHandle= (void *)&gUdmaTdTxCqEventObj;
        cfg->dmaInfo.rxEventHandle  = (void *)&gUdmaRxCqEventObj;
        cfg->dmaInfo.tdRxEventHandle= (void *)&gUdmaTdRxCqEventObj;
    
    }

    return (gDrvHandle);
}

int32_t McaspApp_udma_deinit(void)
{
    int32_t         retVal = UDMA_SOK;

    if (gDrvHandle != NULL)
    {
        retVal = Udma_deinit(gDrvHandle);
        if(UDMA_SOK == retVal)
        {
            gDrvHandle = NULL;
        }
    }

    return (retVal);
}
#endif

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








Void Audio_echo_Task()
{
    Mcasp_HwInfo hwInfo;
    volatile int32_t i32Count, status = 0;
	hMcaspDev  = NULL;
#ifdef DEVICE_LOOPBACK
    uint32_t timeout = 0;
#endif
    uint32_t semTimeout;
    int32_t txSemStatus, rxSemStatus;
    uint32_t rx_frames = 0, tx_frames = 0;

    uint32_t tx_bytes_per_sample=(mcasp_chanparam[1].wordWidth/8);
    uint32_t rx_bytes_per_sample=(mcasp_chanparam[0].wordWidth/8);
    /* This represents the actual  number of bytes being transferred by the
     * DMA to/from the Host memory to the McASP peripheral. This include all serializers and timeslots.
     * BUFLEN contains the samples per serializer (inclusive of its timeslots) */
    uint32_t tx_frame_size = BUFLEN*TX_NUM_SERIALIZER*tx_bytes_per_sample;
    uint32_t rx_frame_size = BUFLEN*RX_NUM_SERIALIZER*rx_bytes_per_sample;

    McASP_App_BufferInfo_t *appBuf_ptr_tx = NULL;
    McASP_App_BufferInfo_t *appBuf_ptr_rx = NULL;
#ifdef MEASURE_TIME
	profiling_init();
#endif

#if defined(AUDIO_EQ_DEMO)
    MCASP_log("\n******** Audio EQ Demo ********\n");
#elif defined(DEVICE_LOOPBACK)
    MCASP_log("\n******** Device Loopback demo ********\n");
    MCASP_log("The test will automatically send %d frames and does a ramp check\n",NUM_TEST_FRAMES);
    MCASP_log("\n Num frames sent =(%d + %d)\n", NUM_TEST_FRAMES, PRIME_COUNT);
#else
    MCASP_log("\n******** Audio Loopback demo ********\n");
    MCASP_log("Send audio signals in to the EVM's audio-in port and hear the same audio in the audio-out port\n");
#endif
  MCASP_log("NUM_BUFS=%d \n",test_num_bufs);
  MCASP_log("PRIME_COUNT=%d \n",test_prime_count);

#ifdef MCASP_ENABLE_DEBUG_LOG   
  mcaspDebugLog_init();
#endif


      Mcasp_socGetInitCfg(MCASP_NUM, &hwInfo);
#if defined(MCASP_EDMA_ENABLED)
    hwInfo.dmaHandle = McaspApp_edmaInit(&hwInfo);
#elif defined(MCASP_UDMA_ENABLED)
      /* Assign UDMA specific parameters */
      hwInfo.dmaHandle=McaspApp_udmaInit(&hwInfo);

      MCASP_log("DescType=%s \n",(hwInfo.dmaInfo.descType==CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR)?"TR":"PKT");
      MCASP_log("UDMA FifoDepth=%d \n",hwInfo.dmaInfo.ringCnt);
#endif

      Mcasp_socSetInitCfg(MCASP_NUM, &hwInfo);

#if defined(AUDIO_DC_DIGITAL_TEST)
      Mcasp_socGetInitCfg(MCASP_DIT_NUM, &hwInfo);
#if defined(MCASP_EDMA_ENABLED)
    hwInfo.dmaHandle = McaspApp_edmaInit(&hwInfo);
#elif defined(MCASP_UDMA_ENABLED)
      /* Assign UDMA specific parameters */
      hwInfo.dmaHandle=McaspApp_udmaInit(&hwInfo);

      MCASP_log("DescType=%s \n",(hwInfo.dmaInfo.descType==CSL_UDMAP_CPPI5_PD_DESCINFO_DTYPE_VAL_TR)?"TR":"PKT");
      MCASP_log("UDMA FifoDepth=%d \n",hwInfo.dmaInfo.ringCnt);
#endif
    Mcasp_socSetInitCfg(MCASP_DIT_NUM, &hwInfo);
#endif

	/* 2. SEM Initializations */
    Semaphore_Params_init(&params);

	/* Create semaphores to wait for buffer reclaiming */
    semR = Semaphore_create(0, &params, &eb);
    semT = Semaphore_create(0, &params, &eb);

	/* 3. McASP Initializations */
	/* Initialize McASP Tx and Rx parameters */

	mcaspParams    = Mcasp_PARAMS;
#if defined(AUDIO_DC_DIGITAL_TEST)
    mcaspDITParams = Mcasp_PARAMS;
#endif

#ifdef DEVICE_LOOPBACK
/* Enable MCASP DLB mode */
	mcaspParams.mcaspHwSetup.glb.dlbMode=(CSL_MCASP_DLBCTL_DLBEN_ENABLE |
										 ( CSL_MCASP_DLBCTL_ORD_XMTEVEN << CSL_MCASP_DLBCTL_ORD_SHIFT) |
										 ( CSL_MCASP_DLBCTL_MODE_XMTCLK << CSL_MCASP_DLBCTL_MODE_SHIFT) );

#endif

#if defined(AUDIO_DC_DIGITAL_TEST)
    mcaspDITParams.isDataBufferPayloadStructure = 1;

	mcaspParams.mcaspHwSetup.tx.clk.clkSetupClk = 0x63;
    mcaspParams.mcaspHwSetup.rx.clk.clkSetupClk = 0x23;
	mcaspDITParams.mcaspHwSetup.tx.clk.clkSetupClk = 0x63;
	mcaspDITParams.mcaspHwSetup.rx.clk.clkSetupClk = 0x23;

	/* Initialize user data and channel status bits */
	for(i32Count = 0; i32Count < 6; i32Count++)
	{
		ditUserData.userDataLeft[i32Count]  = 0;
		ditUserData.userDataRight[i32Count] = 0;

		ditChStatus.chStatusLeft[i32Count]  = 0;
		ditChStatus.chStatusRight[i32Count] = 0;
	}

	ditPayload.chStat         = &ditChStatus;
	ditPayload.userData       = &ditUserData;
	ditPayload.writeDitParams = TRUE;

	pDitPayload = &ditPayload;
#endif

	status = mcaspBindDev(&hMcaspDev, MCASP_NUM, &mcaspParams);
	if((status != MCASP_COMPLETED) || (hMcaspDev == NULL))
	{
		MCASP_log("mcaspBindDev for McASP Failed\n");
		abort();
	}

#if defined(AUDIO_DC_DIGITAL_TEST)
	status = mcaspBindDev(&hMcaspDevDIT, MCASP_DIT_NUM, &mcaspDITParams);
	if((status != MCASP_COMPLETED) || (hMcaspDevDIT == NULL))
	{
		MCASP_log("mcaspBindDev for McASP DIT channel Failed\n");
		abort();
	}
#endif

#if defined(AIC_CODEC)
	/* Bind AIC Codec */
    aic31MdBindDev(&hAicDev, 0, (Ptr)&Aic31_PARAMS);
#endif

    /* Call createStream function to create I/O streams                       */
    createStreams();

    MCASP_log("Initialization complete. priming about to begin \n");
    
    /* Call prime function to do priming                                      */
    prime();

#if defined(DEVICE_LOOPBACK)
    /* Configure the Device loopback test's paramters such as loopback mask */
    config_deviceloopback(tx_frame_size,rx_frame_size);
    /* Because we handle Rx and Tx in the thread, we need to poll on transfer
     * completion so that we don't block one channel from keeping up with the
     * ping-pong if it is ready to process more data.  Therefore, we make
     * semaphore timeout non-blocking
     */
    semTimeout = 0;
#else
    /* Since Rx data arrival due to Tx buffering in non device-loopback cases,
     * and because we need data from Rx before submitting to the Tx stream, we
     * wait indefinitely for both to complete.
     */
    semTimeout = BIOS_WAIT_FOREVER;
#endif

    /* Forever loop to continuously receive and transmit audio data           */
    for (i32Count = 0; i32Count >= 0; i32Count++)
    {

    	if(gblErrFlagXmt || gblErrFlagRcv)
    		break;

#if defined(DEVICE_LOOPBACK)
    	dlb_process_events();
#endif
        rxSemStatus = Semaphore_pend(semR, semTimeout);
        txSemStatus = Semaphore_pend(semT, semTimeout);

        if(rxSemStatus == TRUE)
        {
            /* Reclaim full buffer from the input stream if ready */
            appBuf_ptr_rx = McASP_App_Buffers_PopFree(APP_BUFFER_RX);
            grxFrameIndexCount = appBuf_ptr_rx->index;

            Cache_inv((void *)((uint8_t *)appBuf_ptr_rx->buf),rx_frame_size,Cache_Type_ALL, TRUE);
#ifdef MCASP_ENABLE_DEBUG_LOG
            memcpy(&mcaspFrames_rx[mcaspFrame_rx_index][0],appBuf_ptr_rx->buf,rx_frame_size);
            mcaspFrame_rx_index++;
#endif
        }

        if(txSemStatus == TRUE)
        {
            /* Reclaim full buffer from the output stream if ready */
            appBuf_ptr_tx = McASP_App_Buffers_PopFree(APP_BUFFER_TX);
            gtxFrameIndexCount = appBuf_ptr_tx->index;
        }

#ifdef MEASURE_TIME
    profiling_end();  
#endif

        /******************************* Sample Processing Begins ***************************/
	    /* (BUFLEN* RX_NUM_SERIALIZER) 32-bit samples samples have been accumulated in rxbuf[grxFrameIndexCount] now.
	       Application specific processing on these samples, before sending it back to McASP via 
	       txbuf[grxFrameIndexCount].
		   APPLICATION SPECIFIC PROCESSING could be done here. Below are the few audio demos and their
		   application specific processing shown below.
	    */
#if defined(AUDIO_EQ_DEMO)
        /* AUDIO_EQ CASE: The Audio EQ demo applies EQ parameters on the samples received from McASP before 
		   sending it back to the Tx McASP 
		*/
		audioEQ_process_samples((void *)((uint8_t *)appBuf_ptr_tx->buf),appBuf_ptr_rx->buf,rx_frame_size);
#elif defined(DEVICE_LOOPBACK)
        /* DEVICE LOOPBACK CASE: The Device loopback tests checks for Ramp continuity on the frame received 
		 (the previous Tx frame sent and received via loopback)	and sends a continual ramp 
		 on to the Tx McASP.
		*/
        total_frames_sent = rx_frames + tx_frames;

        /* For Device loopback test (ramp) we send a fininte number of frames. For other tests and
           the default case, the number of frames is inifinite and the demo never exits out of
           the for loop */
        if(total_frames_sent==NUM_TEST_FRAMES * 2)
            break;

        /* If we didn't reclaim any packets, sleep for small amount of time
         * and try again later.
         */
        if (rxSemStatus == FALSE && txSemStatus == FALSE)
            Task_sleep(1);

        /* If we have already handled the specified number of frames, don't try
         * to submit anymore to the stream.  Setting the status to FALSE will
         * prevent this from happening.
         */
        if (rx_frames == NUM_TEST_FRAMES)
            rxSemStatus = FALSE;
        if (tx_frames == NUM_TEST_FRAMES)
            txSemStatus = FALSE;

        if (++timeout > 1000)
        {
            MCASP_log("Error waiting for packets!\r\n");
            break;
        }
#else
        /* DEFAULT CASE: Copy the frame received and send it back to Tx buffer.
		   This way the audio received by McASP from the remote device, is loopbacked and sent back
		   to the device here.
		*/
   		memcpy((void *)((uint8_t *)appBuf_ptr_tx->buf),(void *)((uint8_t *)appBuf_ptr_rx->buf),rx_frame_size);
#endif

        /******************************* Sample Processing End ***************************/
        if(rxSemStatus == TRUE)
        {
#if defined(DEVICE_LOOPBACK)
             /* If we have received a buffer and haven't hit the test limit,
              * process the buffer and reset the timeout.
              */
             deviceloopback_process_samples(appBuf_ptr_rx->buf,rx_frame_size, RX);
             rx_frames++;
             timeout = 0;
#endif
            /* Issue an empty buffer to the input stream                          */
            rxFrame[grxFrameIndexCount].cmd = MCASP_READ;
            rxFrame[grxFrameIndexCount].addr = (void*)getGlobalAddr((uintptr_t)rxbuf[grxFrameIndexCount]);
            rxFrame[grxFrameIndexCount].size = rx_frame_size;
            rxFrame[grxFrameIndexCount].arg = (uintptr_t) hMcaspRxChan;
            rxFrame[grxFrameIndexCount].status = 0;
            rxFrame[grxFrameIndexCount].misc = 1;   /* reserved - used in callback to indicate asynch packet */
#ifdef MCASP_ENABLE_DEBUG_LOG
           mcaspDebugLog(DEBUG_APP_SUBMIT_READ, (uintptr_t)rxFrame[grxFrameIndexCount].addr, rxFrame[grxFrameIndexCount].size, ((uint32_t *)(rxFrame[grxFrameIndexCount].addr))[0], ((uint32_t *)(rxFrame[grxFrameIndexCount].addr))[1]);
#endif
            status = mcaspSubmitChan(hMcaspRxChan, &(rxFrame[grxFrameIndexCount]));
            if((status != MCASP_PENDING))
                MCASP_log ("Debug: Error McASP RX :  buffer  #%d submission FAILED\n", i32Count);
#ifdef MCASP_ENABLE_DEBUG_LOG
           mcaspDebugLog(DEBUG_APP_SUBMIT_READ_COMPLETE, (uintptr_t)rxFrame[grxFrameIndexCount].addr, rxFrame[grxFrameIndexCount].size, ((uint32_t *)(rxFrame[grxFrameIndexCount].addr))[0], ((uint32_t *)(rxFrame[grxFrameIndexCount].addr))[1]);
#endif
        }

        if(txSemStatus == TRUE)
        {
#if defined(DEVICE_LOOPBACK)
            /* If we have reclaimed a tx buffer and haven't hit the test
             * process the next buffer so it can be submitted to the stream.
             */
            deviceloopback_process_samples(appBuf_ptr_tx->buf,tx_frame_size, TX);
            tx_frames++;
#endif
            Cache_wbInv((void *)((uint8_t *)appBuf_ptr_tx->buf),tx_frame_size,Cache_Type_ALL, TRUE);

#if defined(AUDIO_DC_DIGITAL_TEST)
            pDitPayload->addr = (uint32_t *)getGlobalAddr((uintptr_t)appBuf_ptr_tx->buf);
#endif

            /* Issue full buffer to the output stream                             */
            /* TX frame processing */
            txFrame[gtxFrameIndexCount].cmd = MCASP_WRITE;
#if defined(AUDIO_DC_DIGITAL_TEST)
            txFrame[gtxFrameIndexCount].addr = (void*)(pDitPayload);
#else
            txFrame[gtxFrameIndexCount].addr = (void*)getGlobalAddr((uintptr_t)appBuf_ptr_tx->buf);
#endif
            txFrame[gtxFrameIndexCount].size = tx_frame_size;
            txFrame[gtxFrameIndexCount].arg = (uintptr_t) hMcaspTxChan;
            txFrame[gtxFrameIndexCount].status = 0;
            txFrame[gtxFrameIndexCount].misc = 1;   /* reserved - used in callback to indicate asynch packet */

#ifdef MCASP_ENABLE_DEBUG_LOG
           mcaspDebugLog(DEBUG_APP_SUBMIT_WRITE, (uintptr_t)txFrame[gtxFrameIndexCount].addr, txFrame[gtxFrameIndexCount].size, ((uint32_t *)(txFrame[gtxFrameIndexCount].addr))[0], ((uint32_t *)(txFrame[gtxFrameIndexCount].addr))[1]);
#endif

            status = mcaspSubmitChan(hMcaspTxChan, &(txFrame[gtxFrameIndexCount]));
            if((status != MCASP_PENDING))
                MCASP_log ("Debug: Error McASP TX : Prime  buffer  #%d submission FAILED\n", i32Count);

#ifdef MCASP_ENABLE_DEBUG_LOG
           mcaspDebugLog(DEBUG_APP_SUBMIT_WRITE_COMPLETE, (uintptr_t)txFrame[gtxFrameIndexCount].addr, txFrame[gtxFrameIndexCount].size, ((uint32_t *)(txFrame[gtxFrameIndexCount].addr))[0], ((uint32_t *)(txFrame[gtxFrameIndexCount].addr))[1]);
#endif
        }
#ifdef MEASURE_TIME
		profiling_start();
#endif
		
		/* Test Mcasp control API */
		status = mcaspControlChanTest(hMcaspRxChan);
		if(status != MCASP_COMPLETED) {
		    MCASP_log("mcaspControlChanTest Failed\n");
		}

    } /* end of for (i32Count = 0; i32Count >= 0; i32Count++) */
       
        MCASP_log("\nTotal frames sent:     %d", tx_frames);
        MCASP_log("\nTotal frames received: %d", rx_frames);
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
#if defined(AUDIO_DC_DIGITAL_TEST)
        status = mcaspUnBindDev(hMcaspDevDIT);
#endif

		{
			IHeap_Handle iheap;

			iheap = HeapMem_Handle_to_xdc_runtime_IHeap(myHeap);
			Error_init(&eb);
			for(i32Count = 0; i32Count < (test_num_bufs); i32Count ++)
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
	if(total_frames_sent!=NUM_TEST_FRAMES * 2) {
	   MCASP_log("\nTEST FAIL: Test quit after sending %d frames "
                 "and receiving %d frames.\n", tx_frames, rx_frames);
	}
	finish_deviceloopback();
#endif

#ifdef MCASP_DEBUGLOG_PRINT_DEBUG_LOGS
   MCASP_log("\n***********Debug logs***********\n\n");
   mcaspDebugLog_PrintAll();
#endif

#if defined(SOC_AM65XX) || defined(SOC_J721E)
    McaspApp_udma_deinit();
    Sciclient_deinit();
#endif

    BIOS_exit(0);
}

/*
 * This function tests the mcaspControlChan API.
 */
int mcaspControlChanTest(void * mcaspChan)
{
    static unsigned int testCount = 0;
    int status;

    status = MCASP_COMPLETED;

    /* Test this API every 100 frames to make sure it doesn't cause any audio glitch. */
    if((testCount % 100) == 0) {
        /* Testing the reconfiguration of wordWidth: first change it to 16. */
        mcasp_chanparam[0].wordWidth = Mcasp_WordLength_16;
        status = mcaspControlChan(mcaspChan, Mcasp_IOCTL_CHAN_PARAMS_WORD_WIDTH, &mcasp_chanparam[0]);

        /* If there is no error, change wordWidth back to 32. This shouldn't impact audio playing out. */
        if(status == MCASP_COMPLETED) {
           mcasp_chanparam[0].wordWidth = Mcasp_WordLength_32;
           status = mcaspControlChan(mcaspChan, Mcasp_IOCTL_CHAN_PARAMS_WORD_WIDTH, &mcasp_chanparam[0]);
        }
    }

    testCount++;

    return status;
}

/* ========================================================================== */
/*                             END OF FILE                                    */
/* ========================================================================== */
