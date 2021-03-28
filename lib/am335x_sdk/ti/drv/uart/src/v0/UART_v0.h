/*
 * Copyright (c) 2015 - 2019, Texas Instruments Incorporated
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
/** ============================================================================
 *  @file       UART_v0.h
 *
 *  @brief      UART driver implementation for IP V0 UART controller
 *
 *
 *  ============================================================================
 */

#ifndef ti_drivers_uart_UARTv0__include
#define ti_drivers_uart_UARTv0__include

#include <stdbool.h>
#include <ti/drv/uart/UART.h>

#ifdef __cplusplus
extern "C" {
#endif

/* UART function table pointer */

extern const UART_FxnTable UART_FxnTable_v0;

/**<
 *  @brief      UART_V0_Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UART_V0_Object_s
{
    /* UART control variables */
    UART_Params          params;           /* Configured UART parameters */

    /* UART SYS/BIOS objects */
    void*                hwi;              /* Hwi object */
    void*                writeSem;         /* UART write semaphore*/
    void*                readSem;          /* UART read semaphore */
    /* UART write variables */
    const void          *writeBuf;         /* Buffer data pointer */
    size_t               writeCount;       /* Number of Chars sent */
    size_t               writeSize;        /* Chars remaining in buffer */
    uint32_t             writeCR;          /* Write a return character */

    /* UART receive variables */
    void                *readBuf;          /* Buffer data pointer */
    size_t               readCount;        /* Number of Chars read */
    size_t               readSize;         /* Chars remaining in buffer */

    uint32_t             isOpen;           /* flag to indicate module is open */

    uint32_t             edmaLinkChPhyAddr;/* not used for non-DMA lib */
    uint32_t             edmaLinkChId;     /* not used for non-DMA lib */
    uint32_t             txTcc;            /* not used for non-DMA lib */
    uint32_t             rxTcc;            /* not used for non-DMA lib */

    UART_Transaction    *readTrans;        /* Pointer to the current
                                              read transaction */
    UART_Transaction    *writeTrans;       /* Pointer to the current
                                              write transaction */
    uint32_t             rxTimeoutCnt;     /* Receive timeout error count */

    uint32_t             txDataSent;       /* flag to indicate all the data are
                                              written to the TX FIFO */
    UART_Transaction     rdTrans;          /* read transaction data used for old read API */
    UART_Transaction     wrTrans;          /* write transaction data used for old write API */

 }UART_V0_Object, *UART_V0_Handle;

 /**
  *
  * \brief   UART RX Trigger Level Param
  * IMP: The enum values should not be changed since it represents the
  *      actual register configuration values used to configure the UART in
  *      this SoC by the UART driver
  */
 typedef enum
 {
     UART_RXTRIGLVL_1 = 1,
     /**< Trigger Level 1    */
     UART_RXTRIGLVL_4 = 4,
     /**< Trigger Level 4   */
     UART_RXTRIGLVL_8 = 8,
     /**< Trigger Level 8   */
     UART_RXTRIGLVL_14 = 14
     /**< Trigger Level 14   */
 } UART_RxTrigLvl;

typedef struct UART_HWAttrs
{
    /* UART Peripheral's base address */
    uint32_t          baseAddr;
    /* DSP: int vector number; ARM: GIC int number (peripheral event ID + 32) */
    uint32_t          intNum;
    /* CorePac specific Event ID, input to CorePac interrupt controller */
    uint32_t          eventId;
    /* intc mux number, Keystone inc mux is Chip Interrupt Controller
       if assigned -1, system resource manager will decide the mux num */
    int32_t           intcMuxNum;
    /* intc mux input event ID, for Keystone, it is the input event to CIC
       if assigned -1, system resource manager will decide the mux input event ID */
    int32_t           intcMuxInEvent;
    /* intc mux output event ID, for Keystone, it is the Host interrupt num
       if assigned -1, system resource manager will decide the mux output event ID */
    int32_t           intcMuxOutEvent;

    /* EDMA related Hardware configuration details, not used for non-DMA lib */
    /* EDMA event number of Receiver*/
    uint32_t          rxDmaEventNumber;
    /* EDMA event number of Transmitter*/
    uint32_t          txDmaEventNumber;
    /* EDMA Transfer Controller No.of TX channel*/
    uint32_t          edmaTxTCC;
    /* EDMA Transfer Controller No.of Rx channel*/
    uint32_t          edmaRxTCC;
    /* EDMA Transfer Controller No.of TX channel*/
    uint32_t          edmaTxTC;
    /* EDMA Transfer Controller No.of Rx channel*/
    uint32_t          edmaRxTC;

    /* For KS2, the UART module frequency depends on the SoC/UART input
       clock which is a board configuration rather than a SoC configuration.
       The initial frequency value is set to the the SoC input clock,
       the UART module frequency is calculated in UART_init_v0() */
    uint32_t          frequency;
    uint32_t          version;

    /**< edma handle */
    void*             edmaHandle;
    /**< flag to indicate in DMA mode, not used for non-DMA lib  */
    uint32_t          dmaMode;
    /**< flag to indicate in loopback mode */
    uint32_t          loopback;
    /**< flag to enable interrupt */
    uint32_t          enableInterrupt;
    /**< refer #UART_RxTrigLvl for valid values        */
    UART_RxTrigLvl    rxTrigLvl;
    /**< TX FIFO trigger level in bytes (1 - 16)        */
    uint32_t          txTrigLvl;
    /**< UART operation mode */
    uint32_t          operMode;

} UART_HwAttrs;

#define UART_INVALID_INTC_MUX_NUM      ((uint32_t)0xffff)
/**< Invalid Intc Mux number, intc Mux not used if assigned UART_INVALID_INTC_MUX_NUM */

extern void UART_v0_callback(UART_Handle handle, bool readTrans);

#ifdef UART_DMA_ENABLE
extern void UART_receiveDMA(UART_Handle handle, const void *buffer, size_t size);
extern void UART_transmitDMA(UART_Handle handle, const void *buffer, size_t size);
extern int32_t  UART_configDMA(UART_Handle handle);
extern void UART_disableDmaChannel(UART_Handle handle, bool txCha);
extern void UART_freeDmaChannel(UART_Handle handle);
#endif

#ifdef __cplusplus
}
#endif

#endif /* ti_drivers_uart_UARTv0__include */
