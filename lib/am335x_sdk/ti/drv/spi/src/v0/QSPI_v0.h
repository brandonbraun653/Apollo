/*
 * Copyright (C) 2016 - 2019 Texas Instruments Incorporated - http://www.ti.com/
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
/** ============================================================================
 *  @file       QSPI_v0.h
 *
 *  @brief      QSPI driver implementation for QSPI IP V0 controller
 *
 *  The SPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/spi/SPI.h>
 *  #include <ti/drv/spi/soc/QSPI_v0.h>
 *  @endcode
 *
 *  This QSPI driver implementation is designed to operate on IP V0 QSPI controller
 *
 *
 *  ============================================================================
 */

#ifndef QSPI_V0_H
#define QSPI_V0_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drv/spi/SPI.h>
#include <ti/csl/src/ip/qspi/V0/qspi.h>

/*
 *  \brief  Set SPI controller into CONFIG Mode
 *
 *  Command code used with SPI_control()
 */
#define SPI_V0_CMD_SETCONFIGMODE        (SPI_CMD_RESERVED + 0U)


/*
 *  \brief  Set SPI controller into Indirect Transfer Mode
 *
 *  Command code used with SPI_control()
 */
#define SPI_V0_CMD_SETINDXFERMODE       (SPI_CMD_RESERVED + 1U)

/*
 *  \brief  Set direction of data flow when in memory mapped mode.
 *
 *  Conventional SPI_transfer() calls no not require a read or write direction
 *  as SPI operates a in full duplex mode. This function is only used in
 *  combination with memory mapped mode where a read or write direction is
 *  required with SPI flash memory.
 */
#define SPI_V0_CMD_TRANSFERMODE_RW      (SPI_CMD_RESERVED + 2U)

/*
 *  \brief  Set flash specific command when in indirect transfer mode.
 *
 */
#define SPI_V0_CMD_IND_TRANSFER_CMD     (SPI_CMD_RESERVED + 3U)

/*
 *  \brief  Set number of lines configured for RX/TX operation.
 *
 */
#define SPI_V0_CMD_SETXFERLINES         (SPI_CMD_RESERVED + 4U)

/*
 *  \brief  Set number of dummy clock cycles for read operation.
 *
 */
#define SPI_V0_CMD_RD_DUMMY_CLKS        (SPI_CMD_RESERVED + 5U)

/* SPI function table pointer */
extern const SPI_FxnTable QSPI_FxnTable_v0;

/*!
 *  @brief      Type of the SPI transaction.
 */
typedef enum SPI_TransactionType_e {
    SPI_TRANSACTION_TYPE_READ = 0,  /*!< Read transaction */
    SPI_TRANSACTION_TYPE_WRITE      /*!< Write transaction */
} SPI_TransactionType;

/*!
 *  @brief  QSPI controller modes.
 */
typedef enum QSPI_OperMode_e {
    QSPI_OPER_MODE_CFG = 0U,    /*! QSPI controller is in config mode */
    QSPI_OPER_MODE_IND_XFER     /*! QSPI controller is in indirect transfer mode */
} QSPI_OperMode;


/*!
 *  @brief  Number of lines used for QSPI read/write transaction
 */
typedef enum QSPI_xferLines_e {
    QSPI_XFER_LINES_SINGLE = 0U,  /*! Single line is used */
    QSPI_XFER_LINES_DUAL,         /*! Two lines are used */
    QSPI_XFER_LINES_QUAD          /*! Four lines are used */
} QSPI_xferLines;


/*!
 *  @brief  QSPI IP V0 Hardware attributes
 */
typedef struct QSPI_v0_HwAttrs_s {
    /*! QSPI IP V0 Peripheral base address. */
    uint32_t baseAddr;
    /*! QSPI Indirect AHB Trigger address */
    uint32_t indTrigAddr;
    /*! QSPI IP V0 functional clock */
    uint32_t funcClk;
    /*! QSPI IP V0 Peripheral CorePac interrupt vector */
    uint32_t intrNum;
    /*! QSPI IP V0 Peripheral CorePac intc event ID */
    uint32_t eventId;
    /*! intc mux number, Keystone inc mux is Chip Interrupt Controller
        if assigned -1, system resource manager will decide the mux num */
    int32_t intcMuxNum;
    /*! intc mux input event ID, for Keystone, it is the input event to CIC
        if assigned -1, system resource manager will decide the mux input event ID */
    int32_t intcMuxInEvent;
    /*! intc mux output event ID, for Keystone, it is the Host interrupt num
        if assigned -1, system resource manager will decide the mux output event ID */
    int32_t intcMuxOutEvent;
    /*! QSPI controller mode */
    QSPI_OperMode operMode;
    /*! QSPI chip select number */
    uint32_t chipSelect;
    /*! QSPI frame format */
    qspiClkMode_t frmFmt;
    /*! QSPI device delays (CSSOT, CSEOT, CSDADS and CSDA delays) */
    uint32_t devDelays[4];
    /*! QSPI device page size in bytes */
    uint32_t pageSize;
    /*! QSPI device block size is 2 ^ blkSize (bytes) */
    uint32_t blkSize;
    /*! Number of lines used for QSPI reading/writing */
    QSPI_xferLines xferLines;
    /*! Enable interrupts. */
    bool     intrEnable;
    /*! QSPI clock divider */
    uint32_t clkDiv;

} QSPI_v0_HwAttrs;

/*!
 *  @brief  QSPI IP V0 driver object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct QSPI_v0_Object_s {
    void             *mutex;            /* instance lock */
    void             *transferComplete; /* Transfer complete lock */
    void             *hwi;              /* Hardware interrupt object */
    uint32_t          waitTimeout;      /* Wait time out */

    SPI_Params        qspiParams;       /* input parameters */

    uint32_t          transactionType;  /* Read or Write Transaction */
    uint32_t          transferCmd;      /* Transfer command */
    uint32_t          qspiMode;         /* Config or Memory map mode */
    uint32_t          xferLines;        /* Number of transfer Lines */
    uint32_t          rdDummyClks;      /* Number of dummy clock cycles for read op */
    uint32_t          intrPollMode;     /* Interrupt or polling mode */

    SPI_TransferMode  transferMode;     /* Transfer mode */
    SPI_Transaction   transaction;      /* Transaction structure */

    uint8_t          *writeBufIdx;      /* Internal inc. writeBuf index */
    uint32_t          writeCountIdx;    /* Internal dec. writeCounter */
    uint8_t          *readBufIdx;       /* Internal inc. readBuf index */
    uint32_t          readCountIdx;     /* Internal dec. readCounter */

    bool              isOpen;           /* flag to indicate module is open */
} QSPI_v0_Object;

#define INVALID_INTC_MUX_NUM      0xffff

#ifdef __cplusplus
}
#endif

#endif /* _QSPI_V0_H */
