/*
 * Copyright (C) 2014-2019 Texas Instruments Incorporated - http://www.ti.com/
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
 *  @file       QSPI_v1.h
 *
 *  @brief      QSPI driver implementation for a AM572x QSPIcontroller
 *
 *  The SPI header file should be included in an application as follows:
 *  @code
 *  #include <ti/drv/spi/SPI.h>
 *  #include <ti/drv/spi/soc/QSPI_v1.h>
 *  @endcode
 *
 *  This QSPI driver implementation is designed to operate on a AM572x QSPI
 *
 *
 *  ============================================================================
 */

#ifndef QSPI_V1_H
#define QSPI_V1_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <ti/drv/spi/SPI.h>
#include <ti/csl/src/ip/qspi/V1/qspi.h>

#include <ti/osal/osal.h>
/*
 *  \brief  Set SPI controller into CONFIG Mode
 *
 *  Command code used with SPI_control()
 */
#define SPI_V1_CMD_SETCONFIGMODE        (SPI_CMD_RESERVED + 0U)


/*
 *  \brief  Set SPI controller into MEMORY MAP Mode
 *
 *  Command code used with SPI_control()
 */
#define SPI_V1_CMD_SETMEMMORYMAPMODE    (SPI_CMD_RESERVED + 1U)

/*
 *  \brief  Set "FRAMELENTH" when in memory mapped mode.
 *
 *  Conventional SPI_transfer() calls no not require the frame length to be set.
 *  This function is only used in combination with the series of specific SPI
 *  payload (e.g.flash control cmd + internal flash addressing + flash data)
 *
 *  Command code used with SPI_control(). arg is a pointer to an uint32_t
 *  that contains the frame length value to be placed into the SPI register.
 */
#define SPI_V1_CMD_SETFRAMELENGTH       (SPI_CMD_RESERVED + 2U)

/*
 *  \brief  Set direction of data flow when in memory mapped mode.
 *
 *  Conventional SPI_transfer() calls no not require a read or write direction
 *  as SPI operates a in full duplex mode. This function is only used in
 *  combination with memory mapped mode where a read or write direction is
 *  required with SPI flash memory.
 */
#define SPI_V1_CMD_TRANSFERMODE_RW          (SPI_CMD_RESERVED + 3U)

/*
 *  \brief  Set flash specific command when in memory mapped mode.
 *
 */
#define SPI_V1_CMD_MMAP_TRANSFER_CMD        (SPI_CMD_RESERVED + 4U)

/*
 *  \brief  Set number of lines configured for receive operation.
 *
 */
#define SPI_V1_CMD_SETRXLINES               (SPI_CMD_RESERVED + 5U)


/* SPI function table pointer */
extern const SPI_FxnTable QSPI_FxnTable_v1;

/*!
 *  @brief      Type of the SPI transaction.
 */
typedef enum SPI_TransactionType_s {
    SPI_TRANSACTION_TYPE_READ = 0,  /*!< Read transaction */
    SPI_TRANSACTION_TYPE_WRITE      /*!< Write transaction */
} SPI_TransactionType;

/*!
 *  @brief  QSPI Am572x controller modes.
 */
typedef enum QSPI_OperMode_s {
    QSPI_OPER_MODE_CFG = 0U,    /*! QSPI controller is in config mode */
    QSPI_OPER_MODE_MMAP         /*! QSPI controller is in memory map mode */
} QSPI_OperMode;


/*!
 *  @brief  Number of lines used for QSPI read transaction
 */
typedef enum QSPI_rxLines_s {
    QSPI_RX_LINES_SINGLE = 0U,  /*! Single line is used */
    QSPI_RX_LINES_DUAL,         /*! Two lines are used */
    QSPI_RX_LINES_QUAD          /*! Four lines are used */
} QSPI_rxLines;


/*!
 *  @brief  QSPI Am572x Hardware attributes
 */
typedef struct QSPI_HwAttrs_s {
    /*! QSPI Am572x Peripheral base address. */
    uintptr_t baseAddr;
    /*! QSPI Am572x memory mapped mode base address */
    uintptr_t memMappedBaseAddr;
    /*! QSPI Am572x functional clock */
    uint32_t funcClk;
    /*! QSPI Am572x interrupt number */
    uint32_t intrNum;
    /*! QSPI Am572x interrupt id */
    uint32_t eventId;
    /*! QSPI controller mode */
    QSPI_OperMode operMode;
    /*! QSPI chip select number */
    uint32_t chipSelect;
    /*! QSPI CS polarity */
    qspiCsPol_t  csPol;
    /*! QSPI frame format */
    qspiClkMode_t frmFmt;
    /*! QSPI data delay */
    qspiDataDelay_t dataDelay;
    /*! Number of rx Lines used for QSPI reading . */
    QSPI_rxLines rxLines;
    /*! Enable interrupts. */
    bool     intrEnable;
    /*! Enable DMEA */
    bool     dmaEnable;
    /*! EDMA3 handle */
    void    *edmaHandle;
    /*! EDMA3 TCC */
    uint32_t edmaTcc;
    /*! EDMA3 channel ID */
    uint32_t edmaChId;
    /*! QSPI clock divider */
    uint32_t clkDiv;

} QSPI_HwAttrs;


/*!
 *  @brief  QSPI Am572x driver object
 *
 *  The application must not access any member variables of this structure!
 */
typedef struct QSPI_v1_Object_s {
    void *      mutex;                    /* instance lock */
    void *      transferComplete;         /* Transfer complete lock */
    void *      hwi;                      /* Hardware interrupt object */
    uint32_t waitTimeout;             /* Wait time out */

    SPI_Params            qspiParams;     /* input parameters */
    uint32_t    txCmd;          /* config mode command */

    uint32_t          frmLength;       /* Frame length of total transfer */
    uint32_t          transactionType; /* Read or Write Transaction */
    uint8_t         transferCmd;     /* Transfer command */
    uint32_t          qspiMode;        /* Config or Memory map mode */
    uint32_t          rxLines;         /* Number of receive Lines */
    uint32_t          intrPollMode;    /* Interrupt or polling mode */

    SPI_TransferMode      transferMode;   /* Transfer mode */

    uint8_t              *writeBufIdx;    /* Internal inc. writeBuf index */
    uint32_t              writeCountIdx;  /* Internal dec. writeCounter */
    uint8_t              *readBufIdx;     /* Internal inc. readBuf index */
    uint32_t              readCountIdx;   /* Internal dec. readCounter */

    bool                  isOpen;         /* flag to indicate module is open */

    SPI_Transaction      *transaction;    /* transacation pointer */

} QSPI_v1_Object;

#ifdef SPI_DMA_ENABLE
extern int32_t QSPI_dmaConfig(SPI_Handle handle);
extern int32_t QSPI_dmaTransfer(SPI_Handle handle, const SPI_Transaction *transaction);
extern int32_t QSPI_dmaFreeChannel(SPI_Handle handle);
#endif


#ifdef __cplusplus
}
#endif

#endif /* _QSPI_V1_H */
