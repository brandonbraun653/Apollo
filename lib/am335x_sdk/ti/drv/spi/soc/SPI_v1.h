/*
 * Copyright (c) 2014-2018, Texas Instruments Incorporated
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
 *  @file       SPI_v1.h
 *
 *  @brief      SPI driver implementation for a AM57x MCSPI controller.
 *
 *  The SPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/spi/SPI.h>
 *  #include <ti/drv/spi/soc/SPI_v1.h>
 *  @endcode
 *
 *  This SPI driver implementation is designed to operate on a AM57x SPI
 *
 *  ## SPI data frames #
 *
 *  SPI data frames can be any size from 4-bits to 16-bits. If the dataSize in
 *  ::SPI_Params is greater that 8-bits, then the SPI_v1 driver
 *  implementation will assume that the ::SPI_Transaction txBuf and rxBuf
 *  point to an array of 16-bit uint16_t elements.
 *
 *  dataSize  | buffer element size |
 *  --------  | ------------------- |
 *  4-8 bits  | uint8_t             |
 *  9-16 bits | uint16_t            |
 *
 *  ============================================================================
 */

#ifndef SPI_V1_H
#define SPI_V1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drv/spi/MCSPI.h>
#include <ti/csl/src/ip/mcspi/V0/mcspi.h>

/* SPI function table pointer */
extern const SPI_FxnTable SPI_FxnTable_v1;

/* MCSPI function table pointer */
extern const MCSPI_FxnTable MCSPI_FxnTable_v1;

extern MCSPI_config_list MCSPI_config;

/* McSPI FIFO sizes */
#define MCSPI_FULL_FIFO_SIZE          (64U)
#define MCSPI_RX_TX_FIFO_SIZE         (32U)

/*!
 *  @brief
 *  SPI_v1 data frame size is used to determine how to configure the
 *  DMA data transfers. This field is to be only used internally.
 *
 *  SPI_v1_8bit:  txBuf and rxBuf are arrays of uint8_t elements
 *  SPI_v1_16bit: txBuf and rxBuf are arrays of uint16_t elements
 */
typedef enum SPI_v1_FrameSize_s {
    SPI_v1_8bit  = 8,
    SPI_v1_16bit = 16
} SPI_v1_FrameSize;


/*!
 *  @brief  SPI_v1 Hardware attributes
 */
typedef enum SPI_PinMode_s {
    SPI_PINMODE_3_PIN = 0,
    SPI_PINMODE_4_PIN
} SPI_PinMode;


/*!
 *  @brief  SPI_v1 Hardware attributes
 */
typedef enum spiOperMode_s {
    SPI_OPER_MODE_BLOCKING,
    SPI_OPER_MODE_POLLING,
    SPI_OPER_MODE_CALLBACK
} spiOperMode;

/*!
 *  @brief  SPI_v1 channel configurations
 */
typedef struct SPI_v1_ChnCfg_s {
    /*! Polarity of the chip select signal */
    uint32_t csPolarity;
    /*! data lines mode : which lines are used for tx */
    uint32_t dataLineCommMode;
    /*! SPI_v1 chip-select time control */
    uint32_t tcs;
    /*! channel transmit/receive mode */
    uint32_t trMode;

} SPI_v1_ChnCfg;

/*!
 *  @brief  SPI UDMA info structure
 */
typedef struct SPI_dmaInfo_s {
    /*! UDMA TX channel handle */
    void            *txChHandle;
    /*! UDMA RX channel handle */
    void            *rxChHandle;
    /*! UDMA TX ring memory pointers */
    void            *txRingMem;
    /*! UDMA TX completion queue ring memory pointer */
    void            *cqTxRingMem;
    /*! UDMA RX ring memory pointers */
    void            *rxRingMem;
    /*! UDMA RX completion queue ring memory pointer */
    void            *cqRxRingMem;
    /*! UDMA TX PD memory pointers */
    void            *txHpdMem;
    /*! UDMA RX PD memory pointers */
    void            *rxHpdMem;
    /*! UDMA TX event handle */
    void            *txEventHandle;
    /*! UDMA RX event handles */
    void            *rxEventHandle;

} SPI_dmaInfo;

/*!
 *  @brief  SPI_v1 Hardware attributes
 */
typedef struct SPI_v1_HWAttrs_s {
    /*! SPI_v1 Peripheral base address */
    uint32_t      baseAddr;
    /*! SPI_v1 Peripheral interrupt vector */
    uint32_t      intNum;
    /*! SPI_v1 Peripheral interrupt vector */
    uint32_t      eventId;
    /*! pin mode 3 or 4 pin mode */
    uint32_t      pinMode;
    /*! default channel number, only the default
        channel can use the FIFO mode */
    uint32_t      chNum;
    /*! Channel mode: Single channel or multi channel */
    uint32_t      chMode;
    bool          enableIntr;
    /*! Module input clock frequency */
    uint32_t      inputClkFreq;
    /*! SPI_v1 Initial SPI delay for first transfer */
    uint32_t      initDelay;
    /*! receive FIFO trigger level in bytes (1 - 256),
        if 0, RX FIFO is disabled, when RX FIFO is enabled in DMA mode,
        the transfer count should be set to multiple of rxTrigLvl */
    uint32_t      rxTrigLvl;
    /*! transmit FIFO trigger level in bytes (1 - 256),
        if 0, TX FIFO is disabled , when TX FIFO is enabled in DMA mode,
        the transfer count should be set to multiple of rxTrigLvl*/
    uint32_t      txTrigLvl;
    /*! default channel configurations in multi channel mode */
    SPI_v1_ChnCfg chnCfg[MCSPI_MAX_NUM_CHANNELS];

    /* EDMA related Hardware configuration details */
    /*! edma3: EDMA event number of Receiver, udma: RX PDMA thread # */
    uint32_t      rxDmaEventNumber;
    /*! edma3: EDMA event number of Transmitter, udma: TX PDMA thread # */
    uint32_t      txDmaEventNumber;
    /*! EDMA Transfer Controller No.of TX channel*/
    uint32_t      edmaTxTCC;
    /*! EDMA Transfer Controller No.of Rx channel*/
    uint32_t      edmaRxTCC;
    /*! EDMA Transfer Controller No.of TX channel*/
    uint32_t      edmaTxTC;
    /*! EDMA Transfer Controller No.of Rx channel*/
    uint32_t      edmaRxTC;
    /*! edma3: EDMA handle, udma: udma driver handle */
    void         *edmaHandle;
    /*! flag to indicate in DMA mode, not used for non-DMA lib  */
    bool          dmaMode;
    /*! DMA configuration info */
    SPI_dmaInfo  *dmaInfo;

} SPI_v1_HWAttrs;

/*!
 *  @brief  SPI_v1 chObject
 *
 *  channel specific variables
 */
typedef struct SPI_v1_chObject_s {
    SPI_TransferMode   transferMode;        /* blocking or callback transfer mode */
    MCSPI_Params       spiParams;           /* Stores MCSPI params*/
    uint32_t           clockMode;           /* Clock Mode */
    uint32_t           operMode;            /* interrupt or polling mode */
    SPI_Transaction   *transaction;         /* Pointer to the current transaction */
    void              *writeBufIdx;         /* Internal inc. writeBuf index */
    uint32_t           writeCountIdx;       /* Internal dec. writeCounter */
    void              *readBufIdx;          /* Internal inc. readBuf index */
    uint32_t           readCountIdx;        /* Internal dec. readCounter */
    bool               isOpen;              /* flag to indicate module is open */
    uint32_t           wordLenShift;        /* word length shift bits
                                               0: 1 byte per SPI transfer word
                                               1: 2 bytes per SPI transfer word
                                               2: 4 bytes per SPI transfer word */
    uint32_t           dmaCbCheck;          /* dma callback flag */
    uint32_t           navssHandle;         /* NAVSS handle for K3 DMA driver */

} SPI_v1_chObject;


/*!
 *  @brief  SPI_v1 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct SPI_v1_Object_s {
    void            *mutex;               /* trasnfer semaphore */
    void            *transferComplete;    /* transfer complete semaphore */
    void            *hwi;                 /* Hwi object */

    SPI_CallbackFxn  transferCallbackFxn; /* Callback mode function for single channel mode */

    uint32_t         fifoSize;            /* TX/RX FIFO size, if 0, FIFO mode is disabled */
    uint32_t         txTrigLvl;           /* TX FIFO almost empty level */
    uint32_t         rxTrigLvl;           /* RX FIFO almost full level */

    MCSPI_Handle     mcHandle;            /* multi-channel handle of the opened channel 
                                             per instance for backward compatibility */
    uint32_t         chOpenedCnt;         /* Opened channel count */
    SPI_Mode         mode;                /* saved SPI master/slave mode for the instance opened */

    SPI_v1_chObject  chObject[MCSPI_MAX_NUM_CHANNELS]; /* channel specific object */

    uint32_t         edmaLinkChPhyAddrRx[2];
    uint32_t         edmaLinkChPhyAddrTx[2];
    uint32_t         edmaLinkChId;

} SPI_v1_Object, *SPI_v1_Handle;

extern void MCSPI_transferCallback_v1(MCSPI_Handle mcHandle,
                                      SPI_Transaction *spiTrans);
extern void MCSPI_xferSetup_v1(MCSPI_Handle mcHandle, SPI_Transaction *spiTrans);
extern void MCSPI_clearIntStatus(MCSPI_Handle mcHandle);
extern void MCSPI_clearIntErrStatus(MCSPI_Handle mcHandle, uint32_t intStatus);

#ifdef SPI_DMA_ENABLE
extern int32_t MCSPI_dmaConfig(MCSPI_Handle mcHandle);
extern void MCSPI_dmaTransfer(MCSPI_Handle mcHandle, SPI_Transaction *spiTrans);
extern void MCSPI_dmaFreeChannel(MCSPI_Handle handle);
#endif

#ifdef __cplusplus
}
#endif

#endif /* _SPI_V1_H */
