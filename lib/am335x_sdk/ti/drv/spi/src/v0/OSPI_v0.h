/*
 * Copyright (C) 2017 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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
 *  @file       OSPI_v0.h
 *
 *  @brief      OSPI driver implementation for OSPI IP V0 controller
 *
 *  The SPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/spi/SPI.h>
 *  #include <ti/drv/spi/soc/OSPI_v0.h>
 *  @endcode
 *
 *  This OSPI driver implementation is designed to operate on IP V0 OSPI controller
 *
 *
 *  ============================================================================
 */

#ifndef OSPI_V0_H
#define OSPI_V0_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drv/spi/SPI.h>
#include <ti/csl/src/ip/ospi/V0/cslr_ospi.h>
#include <ti/csl/src/ip/ospi/V0/csl_ospi.h>

/*
 *  \brief  Set SPI controller into CONFIG Mode
 *
 *  Command code used with SPI_control()
 */
#define SPI_V0_CMD_SET_CFG_MODE        (SPI_CMD_RESERVED + 0U)


/*
 *  \brief  Set SPI controller into Transfer Mode
 *
 *  Command code used with SPI_control()
 */
#define SPI_V0_CMD_SET_XFER_MODE       (SPI_CMD_RESERVED + 1U)

/*
 *  \brief  Set direction of data flow when in memory mapped mode.
 *
 *  Conventional SPI_transfer() calls no not require a read or write direction
 *  as SPI operates a in full duplex mode. This function is only used in
 *  combination with memory mapped mode where a read or write direction is
 *  required with SPI flash memory.
 */
#define SPI_V0_CMD_XFER_MODE_RW        (SPI_CMD_RESERVED + 2U)

/*
 *  \brief  Set flash specific command when in indirect transfer mode.
 *
 */
#define SPI_V0_CMD_XFER_OPCODE         (SPI_CMD_RESERVED + 3U)

/*
 *  \brief  Set number of lines configured for RX/TX operation.
 *
 */
#define SPI_V0_CMD_SET_XFER_LINES      (SPI_CMD_RESERVED + 4U)

/*
 *  \brief  Set number of dummy clock cycles for read operation.
 *
 */
#define SPI_V0_CMD_RD_DUMMY_CLKS       (SPI_CMD_RESERVED + 5U)

/*
 *  \brief  Set command to configure phy.
 *
 */
#define SPI_V0_CMD_CFG_PHY             (SPI_CMD_RESERVED + 6U)

/*
 *  \brief  Set command to enable DDR mode
 *
 */
#define SPI_V0_CMD_ENABLE_DDR          (SPI_CMD_RESERVED + 7U)

/*
 *  \brief  Set command to enable XIP mode
 *
 */
#define SPI_V0_CMD_CFG_XIP             (SPI_CMD_RESERVED + 8U)

/*
 *  \brief  Set command to disable DDR mode
 *
 */
#define SPI_V0_CMD_ENABLE_SDR          (SPI_CMD_RESERVED + 9U)

/* SPI function table pointer */
extern const SPI_FxnTable OSPI_FxnTable_v0;

/*!
 *  @brief      Type of the SPI transaction.
 */
typedef enum SPI_TransactionType_e {
    SPI_TRANSACTION_TYPE_READ = 0,  /*!< Read transaction */
    SPI_TRANSACTION_TYPE_WRITE      /*!< Write transaction */
} SPI_TransactionType;

/*!
 *  @brief  OSPI controller modes.
 */
typedef enum OSPI_OperMode_e {
    OSPI_OPER_MODE_CFG = 0U,    /*! OSPI controller is in config mode */
    OSPI_OPER_MODE_IND_XFER,    /*! OSPI controller is in indirect transfer mode */
    OSPI_OPER_MODE_DAC_XFER,    /*! OSPI controller is in direct transfer mode */
} OSPI_OperMode;


/*!
 *  @brief  Number of lines used for OSPI read/write transaction
 */
typedef enum OSPI_xferLines_e {
    OSPI_XFER_LINES_SINGLE = 0U,  /*! Single line is used */
    OSPI_XFER_LINES_DUAL,         /*! Two lines are used */
    OSPI_XFER_LINES_QUAD,         /*! Four lines are used */
    OSPI_XFER_LINES_OCTAL         /*! Four lines are used */
} OSPI_xferLines;

/*!
 *  @brief  OSPI UDMA info structure
 */
typedef struct OSPI_dmaInfo_s {
    /*! UDMA driver handle */
    void            *drvHandle;
    /*! UDMA channel handle */
    void            *chHandle;
    /*! UDMA ring memory pointers */
    void            *ringMem;
    /*! UDMA complete queue ring memory pointers */
    void            *cqRingMem;
    /*! UDMA tear down complete queue ring memory pointers */
    void            *tdCqRingMem;
    /*! UDMA TR PD memory pointers */
    void            *tprdMem;
    /*! UDMA event handles */
    void            *eventHandle;

} OSPI_dmaInfo;

/*!
 *  @brief  OSPI IP V0 Hardware attributes
 */
typedef struct OSPI_v0_HwAttrs_s {
    /*! OSPI IP V0 Peripheral base address. */
    uintptr_t        baseAddr;
    /*! OSPI Data base address */
    uintptr_t       dataAddr;
    /*! OSPI IP V0 functional clock */
    uint32_t        funcClk;
    /*! OSPI IP V0 Peripheral CorePac interrupt vector */
    uint32_t        intrNum;
    /*! OSPI IP V0 Peripheral CorePac intc event ID */
    uint32_t        eventId;
    /*! OSPI controller mode */
    OSPI_OperMode   operMode;
    /*! OSPI chip select number */
    uint32_t        chipSelect;
    /*! OSPI frame format */
    CSL_OspiClkMode frmFmt;
    /*! OSPI device delays (CSSOT, CSEOT, CSDADS and CSDA delays) */
    uint32_t        devDelays[4];
    /*! OSPI device page size in bytes */
    uint32_t        pageSize;
    /*! OSPI device block size is 2 ^ blkSize (bytes) */
    uint32_t        blkSize;
    /*! Number of lines used for OSPI reading/writing */
    OSPI_xferLines  xferLines;
    /*! Enable interrupts. */
    bool            intrEnable;
    /*! Direct Access Controller Enable */
    bool            dacEnable;
    /*! Enable DMA */
    bool            dmaEnable;
    /*! UDMA configuration info */
    OSPI_dmaInfo   *dmaInfo;
    /*! Enable PHY */
    bool            phyEnable;
    /*! Read data capture delay in # of ref_clk cycles */
    uint32_t        rdDataCapDelay;
    /*! Enable DTR protocol */
    bool            dtrEnable;
    /*! XIP Enable */
    bool            xipEnable;
    /*! Chip Select Start of Transfer delay in # of ref_clk cycles */
    uint32_t        csSotDelay;

} OSPI_v0_HwAttrs;

/*!
 *  @brief  OSPI IP V0 driver object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct OSPI_v0_Object_s {
    void             *mutex;            /* instance lock */
    void             *transferComplete; /* Transfer complete lock */
    void             *hwi;              /* Hardware interrupt object */
    uint32_t          waitTimeout;      /* Wait time out */

    SPI_Params        ospiParams;       /* input parameters */

    uint32_t          transactionType;  /* Read or Write Transaction */
    uint32_t          transferCmd;      /* Transfer command */
    uint32_t          ospiMode;         /* Config or Memory map mode */
    uint32_t          xferLines;        /* Number of transfer Lines */
    uint32_t          rdDummyClks;      /* Number of dummy clock cycles for read op */
    uint32_t          intrPollMode;     /* Interrupt or polling mode */

    SPI_TransferMode  transferMode;     /* Transfer mode */
    SPI_Transaction  *transaction;      /* Transaction structure */

    uint8_t          *writeBufIdx;      /* Internal inc. writeBuf index */
    uint32_t          writeCountIdx;    /* Internal dec. writeCounter */
    uint8_t          *readBufIdx;       /* Internal inc. readBuf index */
    uint32_t          readCountIdx;     /* Internal dec. readCounter */

    bool              isOpen;           /* flag to indicate module is open */

    uint32_t          rdStatusCmd;      /* flash command to read status register */

} OSPI_v0_Object;

#ifdef SPI_DMA_ENABLE
extern int32_t OSPI_dmaConfig(SPI_Handle handle);
extern void OSPI_dmaTransfer(SPI_Handle handle, const SPI_Transaction *spiTrans);
extern void OSPI_dmaDisableChannel(SPI_Handle handle, bool txCha);
extern void OSPI_dmaFreeChannel(SPI_Handle handle);
#endif

extern uint32_t OSPI_getReadDataCapDelay(SPI_Handle handle);

#ifdef __cplusplus
}
#endif

#endif /* _OSPI_V0_H */
