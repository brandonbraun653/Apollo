/**
 *  \file   mcasp_debug.c
 *
 *  \brief  This file contains the debug functions used in mcasp example
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


/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/csl/hw_types.h>
/* TI-RTOS Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include "MCASP_log.h"
#include "mcasp_debug.h"


mcaspDebugPrints_t mcaspDebugPrints[MAX_NUM_DEBUG_PRINTS];
char mcaspDebugPrintsString[100][50];

uint32_t mcaspDebugPrints_index=0;
uint32_t mcaspDebugPrints_overflow=0;

void mcaspDebugLog(mcaspDebugPrint_e code, uint32_t val1, uint32_t val2, uint32_t val3,uint32_t val4)
{
	mcaspDebugPrints[mcaspDebugPrints_index].code=code;
	mcaspDebugPrints[mcaspDebugPrints_index].val[0]=val1;
	mcaspDebugPrints[mcaspDebugPrints_index].val[1]=val2;
	mcaspDebugPrints[mcaspDebugPrints_index].val[2]=val3;
	mcaspDebugPrints[mcaspDebugPrints_index].val[3]=val4;
   
 	mcaspDebugPrints_index++;
   	if(mcaspDebugPrints_index>=MAX_NUM_DEBUG_PRINTS) {
		mcaspDebugPrints_index=0;
		mcaspDebugPrints_overflow++;
		
	}
}

void mcaspDebugLog_PrintAll()
{

     uint32_t i;
     
     for(i=0;i<mcaspDebugPrints_index;i++) {   
	   
	  MCASP_log("[%d]:    %s    :val1=%x  val2=%x val3=%x val4= %x \n",i,mcaspDebugPrintsString[mcaspDebugPrints[i].code],
	                  mcaspDebugPrints[i].val[0],
	                  mcaspDebugPrints[i].val[1],
	                  mcaspDebugPrints[i].val[2],
	                  mcaspDebugPrints[i].val[3]);
    }

}

void mcaspDebugLog_init() {
   
	strcpy(mcaspDebugPrintsString[DEBUG_APP_AFTER_TX_CREATECHAN],"DEBUG_APP_AFTER_TX_CREATECHAN");
	strcpy(mcaspDebugPrintsString[DEBUG_APP_AFTER_RX_CREATECHAN],"DEBUG_APP_AFTER_RX_CREATECHAN");
	strcpy(mcaspDebugPrintsString[DEBUG_APP_PRIMING_BEGIN],"DEBUG_APP_PRIMING_BEGIN");
    strcpy(mcaspDebugPrintsString[DEBUG_APP_PRIMING_END],"DEBUG_APP_PRIMING_END");
	strcpy(mcaspDebugPrintsString[DEBUG_APP_SUBMIT_WRITE],"DEBUG_APP_SUBMIT_WRITE");
	strcpy(mcaspDebugPrintsString[DEBUG_APP_SUBMIT_WRITE_COMPLETE],"DEBUG_APP_SUBMIT_WRITE_COMPLETE");
	strcpy(mcaspDebugPrintsString[DEBUG_APP_SUBMIT_READ],"DEBUG_APP_SUBMIT_READ");
	strcpy(mcaspDebugPrintsString[DEBUG_APP_SUBMIT_READ_COMPLETE],"DEBUG_APP_SUBMIT_READ_COMPLETE");
	strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_READ],"DEBUG_NAVSS_READ");
	strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_READ_XYZ],"DEBUG_NAVSS_READ_XYZ");
	strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_WRITE],"DEBUG_NAVSS_WRITE");
	strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_WRITE_XYZ],"DEBUG_NAVSS_WRITE_XYZ");
	strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_SUBMIT_QUEUE_TX],"DEBUG_NAVSS_SUBMIT_QUEUE_TX");
	strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_SUBMIT_QUEUE_RX],"DEBUG_NAVSS_SUBMIT_QUEUE_RX");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_TX_ISR],"DEBUG_NAVSS_TX_ISR");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_TX_MCASP_CALLBACK],"DEBUG_NAVSS_TX_MCASP_CALLBACK");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_TX_MCASP_CALLBACK_COMPLETE],"DEBUG_NAVSS_TX_MCASP_CALLBACK_COMPLETE");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_TX_ISR_COMPLETE],"DEBUG_NAVSS_TX_ISR_COMPLETE");
    strcpy(mcaspDebugPrintsString[DEBUG_APP_TX_CALLBACK],"DEBUG_APP_TX_CALLBACK");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_RX_ISR],"DEBUG_NAVSS_RX_ISR");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_RX_MCASP_CALLBACK],"DEBUG_NAVSS_RX_MCASP_CALLBACK");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_RX_MCASP_CALLBACK_COMPLETE],"DEBUG_NAVSS_RX_MCASP_CALLBACK_COMPLETE");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_RX_ISR_COMPLETE],"DEBUG_NAVSS_RX_ISR_COMPLETE");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_POP_CQ],"DEBUG_NAVSS_POP_CQ");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_POP_FREEQ],"DEBUG_NAVSS_POP_FREEQ");
    strcpy(mcaspDebugPrintsString[DEBUG_APP_RX_CALLBACK],"DEBUG_APP_RX_CALLBACK");
    strcpy(mcaspDebugPrintsString[DEBUG_MCASPDRV_LOAD_DMA],"DEBUG_MCASPDRV_LOAD_DMA");
    strcpy(mcaspDebugPrintsString[DEBUG_MCASPDRV_ENABLE_TRANSFER],"DEBUG_MCASPDRV_ENABLE_TRANSFER");
    strcpy(mcaspDebugPrintsString[DEBUG_MCASPDRV_Mcasp_localEdmaProcessPkt],"DEBUG_MCASPDRV_Mcasp_localEdmaProcessPkt");
    strcpy(mcaspDebugPrintsString[DEBUG_APP_CALLBACK],"DEBUG_APP_CALLBACK");
    strcpy(mcaspDebugPrintsString[DEBUG_APP_CALLBACK_READ],"DEBUG_APP_CALLBACK_READ");
    strcpy(mcaspDebugPrintsString[DEBUG_APP_CALLBACK_WRITE],"DEBUG_APP_CALLBACK_WRITE");
    strcpy(mcaspDebugPrintsString[DEBUG_APP_CALLBACK_SPURIOUS],"DEBUG_APP_CALLBACK_SPURIOUS");
    strcpy(mcaspDebugPrintsString[DEBUG_APP_CALLBACK_READ_MISMATCH],"DEBUG_APP_CALLBACK_READ_MISMATCH");
    strcpy(mcaspDebugPrintsString[DEBUG_APP_CALLBACK_WRITE_MISMATCH],"DEBUG_APP_CALLBACK_WRITE_MISMATCH");
    strcpy(mcaspDebugPrintsString[DEBUG_NAVSS_EMPTY_CQ],"DEBUG_NAVSS_EMPTY_CQ");
	
}
