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
 *  @file       SPI_v0.h
 *
 *  @brief      SPI driver implementation for SPI IP V0 controller.
 *
 *  The SPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/spi/SPI.h>
 *  #include <ti/drv/spi/src/v0/SPI_v0.h>
 *  @endcode
 *
 *  This SPI driver implementation is designed to operate on a AM57x SPI
 *
 *  ## SPI data frames #
 *
 *  SPI data frames can be any size from 4-bits to 16-bits. If the dataSize in
 *  ::SPI_Params is greater that 8-bits, then the SPI_v0 driver
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

#ifndef SPI_V0_H
#define SPI_V0_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drv/spi/SPI.h>

/* SPI function table pointer */
extern const SPI_FxnTable SPI_FxnTable_v0;

/*!
 *  @brief
 *  SPI_v0 data frame size is used to determine how to configure the
 *  DMA data transfers. This field is to be only used internally.
 *
 *  SPI_v0_8bit:  txBuf and rxBuf are arrays of uint8_t elements
 *  SPI_v0_16bit: txBuf and rxBuf are arrays of uint16_t elements
 */
typedef enum SPI_v0_FrameSize_e {
    SPI_v0_8bit  = 8,
    SPI_v0_16bit = 16
} SPI_v0_FrameSize;


/*!
 *  @brief  SPI_v0 pin mode
 */
typedef enum SPI_PinMode_e {
    SPI_PINMODE_3_PIN = 0,
    SPI_PINMODE_4_PIN
} SPI_PinMode;


/*!
 *  @brief  SPI_v0 operation mode
 */
typedef enum spiOperMode_e {
    SPI_OPER_MODE_BLOCKING,
    SPI_OPER_MODE_POLLING,
    SPI_OPER_MODE_CALLBACK
} spiOperMode;

/*!
 *  @brief  SPI_v0 transfer error code
 */
typedef enum spiXferErr_e {
    SPI_XFER_ERR_NONE,   /* No transfer error */
    SPI_XFER_ERR_RXOR,   /* Receiver overrun error */
    SPI_XFER_ERR_BE,     /* Bit error */
    SPI_XFER_ERR_TIMEOUT /* Transfer timeout error */
} spiXferErr;

/*!
 *  @brief  SPI control commands
 */

/*
 *  \brief  Activate SPI transfer
 *
 *  Command code used with SPI_control(). arg is a pointer to an uint32_t
 *  that contains the enable/disable value to be placed into the SPI register.
 *
 *  Command argument 0: (1: enable, 0: disable)
 */
#define SPI_V0_CMD_XFER_ACTIVATE   (SPI_CMD_RESERVED + 0U)

/*
 *  \brief  Set internal loopback test mode
 *
 *  Command code used with SPI_control(). arg is a pointer to an uint32_t
 *  that contains the enable/disable value to be placed into the SPI register.
 *
 *  Command argument 0: (1: enable, 0: disable)
 */
#define SPI_V0_CMD_LOOPBACK        (SPI_CMD_RESERVED + 1U)


/*
 *  \brief  Set power down mode
 *
 *  Command code used with SPI_control(). arg is a pointer to an uint32_t
 *  that contains the enable/disable value to be placed into the SPI register.
 *
 *  Command argument 0: (1: enable, 0: disable)
 */
#define SPI_V0_CMD_PWRDOWN         (SPI_CMD_RESERVED + 2U)

/*
 *  \brief  Configure SPI chip select delays
 *
 *  Command code used with SPI_control(). arg is a pointer to an uint32_t
 *  array that contains the delay values to be placed into the SPI register.
 *
 *  Command argument 0: Chip-select-active-to-transmit-start delay
 *  Command argument 1: Transmit-end-to-chip-select-inactive delay
 */
#define SPI_V0_CMD_DELAY           (SPI_CMD_RESERVED + 3U)

/*
 *  \brief  Set bit shift direction
 *
 *  Command code used with SPI_control(). arg is a pointer to an uint32_t
 *  that contains the shift value to be placed into the SPI register.
 *
 *  Command argument 0: 0: MSB shift out first, 1: LSB shift out first
 */
#define SPI_V0_CMD_SHIFT_DIR       (SPI_CMD_RESERVED + 4U)

/*
 *  @brief  Get transfer error code
 *
 *  Command code used with SPI_control(). arg is a pointer to an uint32_t
 *  that returns the error code for the last failed transfer.
 *
 *  Command argument 0: 0: MSB shift out first, 1: LSB shift out first
 */
#define SPI_V0_CMD_GET_XFER_ERR    (SPI_CMD_RESERVED + 5U)

/*!
 *  @brief  SPI_v0 Hardware attributes
 */
typedef struct SPI_v0_HWAttrs_s {
    /*! SPI_v0 Peripheral base address */
    uint32_t baseAddr;
    /*! SPI_v0 Peripheral CorePac interrupt vector */
    uint32_t intNum;
    /*! SPI_v0 Peripheral CorePac intc event ID */
    uint32_t eventId;
    /* intc mux number, Keystone inc mux is Chip Interrupt Controller
       if assigned -1, system resource manager will decide the mux num */
    int32_t intcMuxNum;
    /* intc mux input event ID, for Keystone, it is the input event to CIC
       if assigned -1, system resource manager will decide the mux input event ID */
    int32_t intcMuxInEvent;
    /* intc mux output event ID, for Keystone, it is the Host interrupt num
       if assigned -1, system resource manager will decide the mux output event ID */
    int32_t intcMuxOutEvent;

    /*! pin mode 3 or 4 pin mode */
    uint32_t pinMode;
    /*! Chip select number */
    uint32_t csNum;
    /*! Channel mode: Single channel or multi channel */
    bool     enableIntr;
    /*! Module input clock frequency */
    uint32_t inputClkFreq;
    /*! Interrupt line mapping configuration.
        SPI_INTR_LINE_INT0 - Interrupt line configured to INT0
        SPI_INTR_LINE_INT1 - Interrupt line configured to INT1
     */
    uint32_t intrLine;

    /* EDMA related Hardware configuration details */
    /*! EDMA event number of Receiver*/
    uint32_t rxDmaEventNumber;
    /*! EDMA event number of Transmitter*/
    uint32_t txDmaEventNumber;
    /*! EDMA Transfer Controller No.of TX channel*/
    uint32_t edmaTxTCC;
    /*! EDMA Transfer Controller No.of Rx channel*/
    uint32_t edmaRxTCC;
    /*! EDMA Transfer Controller No.of TX channel*/
    uint32_t edmaTxTC;
    /*! EDMA Transfer Controller No.of Rx channel*/
    uint32_t edmaRxTC;
    /*! EDMA handle */
    void    *edmaHandle;
    /*! flag to indicate in DMA mode, not used for non-DMA lib  */
    bool     dmaMode;
    /*! flag to indicate in loopback mode, 0: loopback off, 1: loopback on */
    uint32_t loopback;

} SPI_v0_HWAttrs;

/*!
 *  @brief  SPI_v0 Object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct SPI_v0_Object_s {
    void *                mutex;
    void                 *transferComplete;    /* Notify SPI_v0 transfer end */
    void                 *hwi;                 /* Hwi object */
    uint32_t              waitTimeout;        /* Time out */

    SPI_TransferMode      transferMode;        /* Transfer mode */
    SPI_CallbackFxn       transferCallbackFxn; /* Callback mode function */
    SPI_v0_FrameSize      frameSize;           /* Data frame size */

    uint32_t              clockMode;           /* Clock Mode */
    uint32_t              operMode;            /* interrupt or polling mode */

    SPI_Transaction      *transaction;         /* Pointer to the current transaction */

    uint8_t              *writeBufIdx;         /* Internal inc. writeBuf index */
    uint32_t              writeCountIdx;       /* Internal dec. writeCounter */

    uint8_t              *readBufIdx;          /* Internal inc. readBuf index */
    uint32_t              readCountIdx;        /* Internal dec. readCounter */

    bool                  isOpen;              /* flag to indicate module is open */

    SPI_Mode              spiMode;             /* master or slave mode */
    spiXferErr            transferErr;         /* Transfer error code */

    uint32_t              edmaCbCheck;
    uint32_t              edmaLinkChId;        /* edma3 Link channel ID */

} SPI_v0_Object, *SPI_v0_Handle;

/* Invalid Intc Mux number, intc Mux not used if assigned INVALID_INTC_MUX_NUM */
#define INVALID_INTC_MUX_NUM      0xffff

/*
** Values used to determine the chip select number used for SPI communication.
*/
#define SPI_CS(x)         (x)

#ifdef SPI_DMA_ENABLE
extern int32_t SPI_dmaConfig(SPI_Handle handle);
extern void SPI_dmaTransfer(SPI_Handle handle,SPI_Transaction *transaction);
extern void SPI_dmaDisableChannel(SPI_Handle handle, bool txCha);
extern void SPI_dmaFreeChannel(SPI_Handle handle);
#endif



#ifdef __cplusplus
}
#endif

#endif /* SPI_V0_H */
