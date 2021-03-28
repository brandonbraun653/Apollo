/*
 * Copyright (c) 2014-2019, Texas Instruments Incorporated
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
 *  @file       UART_v1.h
 *
 *  @brief      UART DMA and non-DMA driver implementation for IP V1 UART controller
 *
 *
 *  ============================================================================
 */

#ifndef ti_drivers_uart_UARTv1__include
#define ti_drivers_uart_UARTv1__include

#include <stdbool.h>
#include <ti/drv/uart/UART.h>

#ifdef __cplusplus
extern "C" {
#endif



/* UART function table pointer */
extern const UART_FxnTable UART_FxnTable_v1;

/*!
 *  @brief Function to set interrupt path
 *
 *  This function will configure the interrupt path to the destination CPU
*   using DMSC firmware via sciclient. if setIntrPath is set to TRUE,
*   a path is set, else the interrupt path is released
 */
typedef int32_t (*UART_socCfgIntrPathFxn)(const void *pHwAttrs, bool setIntrPath);


/*!
 *  @brief      UART_V1 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct UART_V1_Object_s
{
    /* UART control variables */
    UART_Params          params;           /* Configured UART parameters */

    /* UART SYS/BIOS objects */
    void*               hwi; /* Hwi object */
    void*               writeSem;         /* UART write semaphore*/
    void*               readSem;          /* UART read semaphore */
    /* UART write variables */
    const void          *writeBuf;         /* Buffer data pointer */
    size_t               writeCount;       /* Number of Chars sent */
    size_t               writeSize;        /* Chars remaining in buffer */
    uint32_t         writeCR;          /* Write a return character */

    /* UART receive variables */
    void                *readBuf;          /* Buffer data pointer */
    size_t               readCount;        /* Number of Chars read */
    size_t               readSize;         /* Chars remaining in buffer */

    uint32_t         isOpen;           /* flag to indicate module is open */

    uint32_t             edmaLinkChPhyAddr;
    uint32_t             edmaLinkChId;
    uint32_t             txTcc;
    uint32_t             rxTcc;
    UART_Transaction    *readTrans;    /* Pointer to the current read transaction */
    UART_Transaction    *writeTrans;   /* Pointer to the current write transaction */
    uint32_t             rxTimeoutCnt; /* Receive timeout error count */
    uint32_t             txDataSent;   /* flag to indicate all the data are
                                          written to the TX FIFO */

    uint32_t             readDmaSize;   /* read operation DMA size in bytes */

    UART_Transaction     rdTrans;       /* read transaction data used for old read API */
    UART_Transaction     wrTrans;       /* write transaction data used for old write API */

}UART_V1_Object, *UART_V1_Handle;

/**
 *
 * \brief   UART Rx Trigger Level Param
 * IMP: The enum values should not be changed since it represents the
 *          actual register configuration values used to configure the UART in
 *          this SoC by the UART driver
 */
typedef enum
{
    UART_RXTRIGLVL_8 = 8,
    /**< Trigger Level 8    */
    UART_RXTRIGLVL_16 = 16,
    /**< Trigger Level 16   */
    UART_RXTRIGLVL_56 = 56,
    /**< Trigger Level 56   */
    UART_RXTRIGLVL_60 = 60
                        /**< Trigger Level 60   */
} UART_RxTrigLvl;

/**
 *
 * \brief   UART Tx Trigger Level Param
 * IMP: The enum values should not be changed since it represents the
 *      actual register configuration values used to configure the UART in
 *      this SoC by the UART driver
 */
typedef enum
{
    UART_TXTRIGLVL_8 = 8,
    /**< Trigger Level 8    */
    UART_TXTRIGLVL_16 = 16,
    /**< Trigger Level 16   */
    UART_TXTRIGLVL_32 = 32,
    /**< Trigger Level 32   */
    UART_TXTRIGLVL_56 = 56
                        /**< Trigger Level 56   */
} UART_TxTrigLvl;

/*!
 *  @brief  UART UDMA info structure
 */
typedef struct UART_dmaInfo_s {
    /*! UDMA TX channel handle */
    void            *txChHandle;
    /*! UDMA RX channel handle */
    void            *rxChHandle;
    /*! UDMA TX ring memory pointers */
    void            *txRingMem;
    /*! UDMA TX completion queue ring memory pointer */
    void            *cqTxRingMem;
    /*! UDMA TX tear down completion queue ring memory pointer */
    void            *tdCqTxRingMem;
    /*! UDMA RX ring memory pointers */
    void            *rxRingMem;
    /*! UDMA RX completion queue ring memory pointer */
    void            *cqRxRingMem;
    /*! UDMA RX tear down completion queue ring memory pointer */
    void            *tdCqRxRingMem;
    /*! UDMA TX PD memory pointers */
    void            *txHpdMem;
    /*! UDMA RX PD memory pointers */
    void            *rxHpdMem;
    /*! UDMA TX event handle */
    void            *txEventHandle;
    /*! UDMA RX event handles */
    void            *rxEventHandle;

} UART_dmaInfo;

typedef struct UART_HWAttrs {
    /*UART Peripheral's base address */
    uint32_t      baseAddr;
    /*UART Interrupt number */
    uint32_t      intNum;
    /*UART EventID */
    uint32_t      eventId;
    /*UART Input frequency */
    uint32_t      frequency;

    /*EDMA related Hardware configuration details*/
    uint32_t      rxDmaEventNumber;
    /**< edma3: EDMA event number of Receiver, udma: RX PDMA thread # */
    uint32_t      txDmaEventNumber;
    /**< edma3: EDMA event number of Transmitter, udma: TX PDMA thread # */
    uint32_t      edmaTxTCC;
    /**< EDMA Transfer Controller No.of TX channel*/
    uint32_t      edmaRxTCC;
    /**< EDMA Transfer Controller No.of Rx channel*/
    uint32_t      edmaTxTC;
    /**< EDMA Transfer Controller No.of TX channel*/
    uint32_t      edmaRxTC;
    /**< EDMA Transfer Controller No.of Rx channel*/
    uint32_t      version;
    void*         edmaHandle;
    /**< edma3: EDMA handle, udma: udma driver handle */
    UART_RxTrigLvl  rxTrigLvl;
    /**< refer #UART_RxTrigLvl for valid values        */
    UART_TxTrigLvl  txTrigLvl;
    /**< refer #UART_TxTrigLvl for valid values        */
    uint32_t      dmaMode;
    /**< flag to indicate in DMA mode */
    uint32_t      loopback;
    /**< flag to indicate in loopback mode */

    /**< flag to enable interrupt */
    uint32_t      enableInterrupt;

    /**< UART operation mode */
    uint32_t      operMode;

    /*! UDMA configuration info */
    UART_dmaInfo *dmaInfo;

    /*! Function pointer to set interrupt router path */
    UART_socCfgIntrPathFxn configSocIntrPath;

} UART_HwAttrs;

extern void UART_v1_callback(UART_Handle uartHnd, bool readTrans);

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

#endif /* ti_drivers_uart_UARTv1__include */
