
/*
 * Copyright (c) 2014, Texas Instruments Incorporated
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

/*
 *  ======== uartecho.c ========
 */

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>

/* TI-RTOS Header files */
#include <ti/drv/uart/uart_drv.h>
/* Example/Board Header files */

static void Board_initUART(void);

static void Board_initGeneral(void);

extern UART_InitCfg uartInitCfg[];
/*
 *  ======== echoFxn ========
 *  Task for this function is created statically. See the project's .cfg file.
 *
 */

#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_SLEWCONTROL_SHIFT                                                 (19U)
#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_SLEWCONTROL_MASK                                                  (0x00080000U)
#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_SLEWCONTROL_SLOW_SLEW                                              (0U)
#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_SLEWCONTROL_FAST_SLEW                                              (1U)

#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_INPUTENABLE_SHIFT                                                 (18U)
#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_INPUTENABLE_MASK                                                  (0x00040000U)
#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_INPUTENABLE_ENABLE                                                 (1U)
#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_INPUTENABLE_DISABLE                                                (0U)

#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_PULLTYPESELECT_SHIFT                                              (17U)
#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_PULLTYPESELECT_MASK                                               (0x00020000U)
#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_PULLTYPESELECT_PULL_UP                                             (1U)
#define CTRL_CORE_PAD_UART1_TXD_UART1_TXD_PULLTYPESELECT_PULL_DOWN                                           (0U)


#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_SLEWCONTROL_SHIFT                                                 (19U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_SLEWCONTROL_MASK                                                  (0x00080000U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_SLEWCONTROL_SLOW_SLEW                                              (0U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_SLEWCONTROL_FAST_SLEW                                              (1U)

#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_INPUTENABLE_SHIFT                                                 (18U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_INPUTENABLE_MASK                                                  (0x00040000U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_INPUTENABLE_ENABLE                                                 (1U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_INPUTENABLE_DISABLE                                                (0U)

#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_PULLTYPESELECT_SHIFT                                              (17U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_PULLTYPESELECT_MASK                                               (0x00020000U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_PULLTYPESELECT_PULL_UP                                             (1U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_PULLTYPESELECT_PULL_DOWN                                           (0U)

#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_PULLUDENABLE_SHIFT                                                (16U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_PULLUDENABLE_MASK                                                 (0x00010000U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_PULLUDENABLE_ENABLE                                                (1U)
#define CTRL_CORE_PAD_UART1_RXD_UART1_RXD_PULLUDENABLE_DISABLE                                               (0U)

#define CTRL_CORE_PAD_UART1_CTSN_UART1_CTSN_INPUTENABLE_MASK                                                (0x00040000U)
#define CTRL_CORE_PAD_UART1_CTSN_UART1_CTSN_PULLTYPESELECT_MASK                                             (0x00020000U)
#define CTRL_CORE_PAD_UART1_RTSN_UART1_RTSN_WAKEUPENABLE_MASK                                               (0x01000000U)
#define CTRL_CORE_PAD_UART1_RTSN_UART1_RTSN_INPUTENABLE_MASK                                                (0x00040000U)
#define CTRL_CORE_PAD_UART1_RTSN_UART1_RTSN_PULLTYPESELECT_MASK                                             (0x00020000U)

#define CTRL_CORE_PAD_UART1_RXD                                                                             (0x3e0U)
#define CTRL_CORE_PAD_UART1_TXD                                                                             (0x3e4U)
#define CTRL_CORE_PAD_UART1_CTSN                                                                            (0x3e8U)
#define CTRL_CORE_PAD_UART1_RTSN                                                                            (0x3ecU)

#define SOC_CORE_PAD_IO_REGISTERS_BASE                                          (0x4a003400U)


#define HW_WR_REG32(addr, data)   *(unsigned int*)(addr) =(unsigned int)(data)
char echoPrompt[] = "\INDIAN\n";
char scanPrompt[10] ;
Void uart_test(UArg arg0, UArg arg1)
{
    char input;
    UART_Handle uart = NULL;
    UART_Params uartParams;

    char *buffPointer;
    int size,status;

#if 0
    size = UART_getTotalBufferRequired();
	buffPointer = (char *)Uart_osalMalloc(size);
    uart = UART_init(3,&uartInitCfg[0],buffPointer);
    /* Create a UART with data processing off. */
    UART_start(uart);
    UART_Params_init(&uartParams);
   /* uartParams.writeDataMode = UART_DATA_BINARY;
    uartParams.readDataMode = UART_DATA_BINARY;
    uartParams.readReturnMode = UART_RETURN_FULL;
    uartParams.readEcho = UART_ECHO_OFF;
    uartParams.baudRate = 115200;*/
    status = UART_open(uart, &uartParams);
//    UART_writePolling(uart, echoPrompt, sizeof(echoPrompt));
    UART_write(uart, echoPrompt, sizeof(echoPrompt));
  // CONSOLEUtilsUartScanFmt(buffPointer);
    /* Loop forever echoing */
    while (1) {
    //	UART_writePolling(uart, echoPrompt, sizeof(echoPrompt));
    	//UART_read(uart, &input, 1);
    	Task_sleep(10);
    	UART_write(uart, echoPrompt, sizeof(echoPrompt));
    	UART_read(uart,  scanPrompt, sizeof(scanPrompt));
    }
#else
    UARTStdioInit(0);
    while(1) {
      UARTPuts(echoPrompt, sizeof(echoPrompt));
      UARTGets(scanPrompt, sizeof(scanPrompt));
    }
#endif
}

/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions */
   // while(1);
	Board_initGeneral();
    Board_initUART();

    /* Start BIOS */
    BIOS_start();
    return (0);
}

void Board_initUART(void) {

	      HW_WR_REG32((SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_UART1_RXD),
	        (CTRL_CORE_PAD_UART1_RXD_UART1_RXD_INPUTENABLE_MASK |
	         CTRL_CORE_PAD_UART1_RXD_UART1_RXD_SLEWCONTROL_MASK |
	         CTRL_CORE_PAD_UART1_RXD_UART1_RXD_PULLTYPESELECT_MASK));

	    /* TXD */
	    HW_WR_REG32((SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_UART1_TXD),
	        (CTRL_CORE_PAD_UART1_TXD_UART1_TXD_INPUTENABLE_MASK |
	         CTRL_CORE_PAD_UART1_TXD_UART1_TXD_SLEWCONTROL_MASK |
	         CTRL_CORE_PAD_UART1_TXD_UART1_TXD_PULLTYPESELECT_MASK));

	    /* RTSN */
	    HW_WR_REG32((SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_UART1_RTSN),
	        (CTRL_CORE_PAD_UART1_RTSN_UART1_RTSN_INPUTENABLE_MASK |
	         CTRL_CORE_PAD_UART1_RTSN_UART1_RTSN_PULLTYPESELECT_MASK));

	    /* CTSN */
	    HW_WR_REG32((SOC_CORE_PAD_IO_REGISTERS_BASE + CTRL_CORE_PAD_UART1_CTSN),
	        (CTRL_CORE_PAD_UART1_CTSN_UART1_CTSN_INPUTENABLE_MASK |
	         CTRL_CORE_PAD_UART1_CTSN_UART1_CTSN_PULLTYPESELECT_MASK));
}

void Board_initGeneral(void) {


}
