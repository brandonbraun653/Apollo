/**
 * \file      main.c
 *
 * \brief     This file contains pruss example application code.This will
 *             test the API's of the PRUICSS driver, interrupt handling
 *             and event handling .



 * Copyright (c) 2015, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/** ============================================================================*/
#define PASM_DOS
#include <xdc/std.h>
#include <xdc/runtime/Error.h>
#include <xdc/runtime/System.h>
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <ti/drv/pruss/pruicss.h>
#include <ti/drv/pruss/test/src/test_pruss_intc_mapping.h>
#ifdef PASM_DOS
#include <ti/drv/pruss/test/src/pru_firmware/pruss_test_pru1_bin.h>
#else
#include <ti/drv/pruss/test/src/pru_firmware/firmware_ccs_pjt/pru_firmware_bin.h>
#endif
/* BIOS Header files */
#include <ti/sysbios/BIOS.h>

#ifdef UART_PRINT
#include <ti/drv/uart/UART_stdio.h>
#define PRINT UART_printf
#else
#define PRINT System_printf
#endif
/* Example/Board Header files */
static void Board_initPruss(void);
static void Board_initGeneral(void);
extern PRUICSS_Config pruss_config[2 + 1];

void* pruss_isr(void*);


#define HW_WR_REG32(addr, data)   *(unsigned int*)(addr) =(unsigned int)(data)

PRUICSS_Handle handle;
int eventregistered = 0;

/*
 *  ======== taskFxn ========
 */
void* pruss_isr(void * ptr)
{
	PRUICSS_pruClearEvent(handle,PRU1_ARM_EVENT);
}
int prueventsent = 0;

#define TESTING /*switch to test the UART driver's API.*/
Void taskFxn(UArg a0, UArg a1)
{

#ifdef UART_PRINT
	UART_stdioInit(0);
#endif
	PRUICSS_IntcInitData pruss_intc_initdata = PRUICSS_INTC_INITDATA;
	handle = PRUICSS_create(pruss_config,2);
	//handle = PRUICSS_create(pruss_config,2);

	PRUICSS_pruDisable(handle,0 );

	PRUICSS_pruDisable(handle,1);
#ifdef C66x
	PRUICSS_registerIrqHandler(handle,2,15,38,
								   1,
								   pruss_isr
								   );
#else
	PRUICSS_registerIrqHandler(handle,2,120+32,120+32,
									   1,
									   pruss_isr
									   );
#endif
	eventregistered = 1;
#ifdef PASM_DOS
	PRUICSS_setPRUBuffer(handle,1, (void*)XYZ, sizeof(XYZ));
#else
	PRUICSS_setPRUBuffer(handle,1, (void*)tiesc_eeprom, sizeof(tiesc_eeprom));
#endif
	PRUICSS_pruIntcInit(handle,&pruss_intc_initdata);
	PRUICSS_pruExecProgram(handle,1);
	PRUICSS_pruEnable(handle,1);
	Task_sleep(1000);
	while(1) {
		if(prueventsent == 0 ) {
			PRINT("sending the event to PRU\n");
			PRUICSS_pruSendEvent(handle,ARM_PRU1_EVENT);
			prueventsent =1;
		}
		else {
			Task_sleep(1000);
		}
	}
	PRUICSS_pruSendEvent(handle,ARM_PRU0_EVENT);
	PRUICSS_pruSendEvent(handle,ARM_PRU1_EVENT);

}
void eventwait (UArg a0, UArg a1)
{
  /*wait for the event registration*/
	while(eventregistered == 0)
	{
		Task_sleep(1000);
	}
	while(1)
	{
		PRINT("waiting for the event from PRU\n");
		PRUICSS_pruWaitEvent(handle,2);
		PRINT("got the event from PRU\n");
		prueventsent=0;
	}
}
/*
 *  ======== main ========
 */
Int main()
{
    Task_Handle task,task1;
    Error_Block eb,eb2;

   // UART_printf("enter main()\n");

    Board_initGeneral();
    Board_initPruss();

    Error_init(&eb);
    Error_init(&eb2);
    task = Task_create(taskFxn, NULL, &eb);
    if (task == NULL) {
    	//UART_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    BIOS_start();    /* does not return */
    return(0);
}



void Board_initPruss(void)
{
	// *(unsigned int*)(0x4a002b2c) =(unsigned int)(0x007400BA);
	 *(unsigned int*)(0x4a002b2c) =(unsigned int)(0x007400C5);
#ifdef C66x
	// *(unsigned int*)0x4A002954 = (unsigned int)(0x000800BA);
	 *(unsigned int*)0x4A002954 = (unsigned int)(0x000800C5);

#endif
}

void Board_initGeneral(void)
{


}

