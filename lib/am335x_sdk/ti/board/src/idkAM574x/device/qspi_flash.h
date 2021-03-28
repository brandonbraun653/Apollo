/**
 *  \file   S25FL.h
 *
 *  \brief  Header file for S25FL QSPI Nor Flash driver.
 *
 */

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

#ifndef __S25FL_H
#define __S25FL_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/* TI-RTOS Header files */
#include <ti/drv/spi/SPI.h>

/*!
 *  @brief Flash device size in bytes.
 */
#define S25FL_FLASH_DEVICE_SIZE        (32 * 1024 *1024)

/*!
 *  @brief Flash block size in bytes.
 */
#define S25FL_FLASH_BLOCK_SIZE         (64 * 1024)

/*!
 *  @brief Flash sector size in bytes.
 */
#define S25FL_FLASH_SECTOR_SIZE        (4 * 1024)

/*!
 *  @brief Flash device ID.
 */
#define S25FL_FLASH_DEVICE_ID          (0x18)

/*!
 *  @brief Macro to enable quad mode.
 */
#define QSPI_FLASH_QUAD_ENABLE_VALUE (0x1)

/*!
 *  @brief Macro indicating the bit position of quad enable bit.
 */
#define QSPI_FLASH_QUAD_ENABLE_BIT   (0x01U)


/**
 * \brief  This enumerates the commands of qspi flash
 *         for communication with the flash device.
 */
typedef enum qspiLibCmd
{
    QSPI_LIB_CMD_READ_SINGLE = 0x3U,
    /**< Single read from qspi flash device */
    QSPI_LIB_CMD_READ_DUAL = 0x3BU,
    /**< Dual Read from QSPI flash device */
    QSPI_LIB_CMD_READ_QUAD = 0x6B,
    /**< Quad read commnad from QSPI flash */
    QSPI_LIB_CMD_WRITE_ENABLE = 0x6U,
    /**< QSPI flash write enable command */
    QSPI_LIB_CMD_READ_STATUS_REG = 0x5U,
    /**< Read status register */
    QSPI_LIB_CMD_READ_STATUS_REG2 = 0x7U,
    /**< Read status register 2 */
    QSPI_LIB_CMD_READ_CONF_REG = 0x35U,
    /**< Read configuration register */
    QSPI_LIB_CMD_WRITE_STATUS_REG = 0x1U,
    /**< Write status register */
    QSPI_LIB_CMD_READ_SFDP = 0x5AU,
    /**< Command to read SFDP header and parameter table */
    QSPI_LIB_CMD_PAGE_PRG = 0x2U,
    /**< Command to write to serial nor flash */
    QSPI_LIB_CMD_FAST_READ = 0x0BU,
    /**< Fast single read command */
    QSPI_LIB_CMD_READ_MFG_ID = 0x90U,
    /**< Read manufacturer and device ID */
    QSPI_LIB_CMD_BLOCK_ERASE = 0xD8U,
    /**< QSPI flash block erase command */
    QSPI_LIB_CMD_SECTOR_ERASE = 0x20U,
    /**< QSPI flash sector erase command */
    QSPI_LIB_CMD_FULL_ERASE = 0x60U,
    /**< Completely erase flash data */
    QSPI_LIB_CMD_ENTER_4_BYTE_ADDR = 0xB7U,
    /**< Command to enter 4 byte addressing mode */
    QSPI_LIB_CMD_EXIT_4_BYTE_ADDR = 0xE9U,
    /**< Command to exit 4 byte addressing mode */
    QSPI_LIB_CMD_QUAD_RD_CMD_REG   = 0x35U,
    /**< command to read the register where the quad enable bit has to be set */
    QSPI_LIB_CMD_QUAD_WR_CMD_REG   = 0x01U
    /**< command to read the register where the quad enable bit has to be set */
}qspiLibCmd_t;


/*!
 *  @brief Flash object containing flash attributes.
 */
typedef struct S25FL_Object {
    SPI_Handle       spiHandle;     /* Handle for SPI object */
    unsigned int     boardSPI;      /* Board SPI in Board.h */
    unsigned int     sectorSize;    /* Indicates sector size of the flash */
    unsigned int     blockSize;     /* block size of the flash in bytes */
    unsigned int     deviceSize;    /* Size of the flash device */
    unsigned int     flashDeviceId; /* Flash device id */
}S25FL_Object;


/*!
 *  @brief Flash transaction data structure.
 */
typedef struct S25FL_Transaction {
    uint8_t  *data;      /* Transaction data buffer  */
    uint32_t address;    /* Flash address object for transaction */
    uint32_t  dataSize;   /* size of transaction data in bytes */
}S25FL_Transaction;


/*!
 *  @brief A handle that is returned from a S25FL_open() call.
 */
typedef S25FL_Object *S25FL_Handle;


/*!
 *  @brief  Opens the S25FL object. This will internally opens the corresponding
 *          QSPI instance and gets the QSPI instance handle.
 *
 *  @param  index    Flash index.
 *  @param  params   Pointer to the SPI parameters structure.
 */
extern S25FL_Handle SF25FL_open(unsigned int index, SPI_Params *params);


/*!
 *  @brief  Closes the S25FL object.
 *
 *  @param  flashHandle   A S25FL_Handle
 */
extern void SF25FL_close(S25FL_Handle flashHandle);


/*!
 *  @brief  This function writes data to the flash using QSPI interface.
 *
 *  @param  flashHandle       A S25FL_Handle
 *  @param  transaction       A S25FL_Transaction
 *  @return Status            true if successful; else false
 *
 */
extern bool SF25FL_bufferWrite(S25FL_Handle flashHandle,
                               S25FL_Transaction* flashTransaction);

/*!
 *  @brief  This function reads specific number of bytes from the flash using
 *          QSPI interface.
 *
 *  @param  flashHandle       A S25FL_Handle
 *  @param  transaction       A S25FL_Transaction
 *  @return Status            true if successful; else false
 *
 */
extern bool SF25FL_bufferRead(S25FL_Handle flashHandle,
                              S25FL_Transaction* flashTransaction);

/*!
 *  @brief  This function reads the value of flash status register. This status
 *          is required to know whether flash transaction is completed or still
 *          going on.
 *
 *  @param  flashHandle       A S25FL_Handle
 *  @return status            value of the flash status register.
 *
 */
extern uint32_t FlashStatus(S25FL_Handle flashHandle);


/*!
 *  @brief  This function controls the enable/disable of the 4 byte addressing
 *          mode. If the destination flash offset address is greater than
 *          0xFFFFFFU then this mode should be enabled else not required.
 *
 *  @param  flashHandle  A S25FL_Handle
 *  @param  enableFlag   Flag controlling enable/disable of 4 byte address mode.
 *                       TRUE- enable 4 Byte mode; FALSE- disable 4 Byte mode.
 *
 */
extern bool S25FLFlash_Enable4ByteAddrMode(S25FL_Handle flashHandle,
                                           bool enable4ByteMode);


/*!
 *  @brief  This function sends write enable command to the flash device. This
 *          function has to be called first before performing any write to
 *          flash.
 *
 *  @param  flashHandle  A S25FL_Handle
 *  @return status       status of the operation
 *
 */
extern bool S25FLFlash_WriteEnable(S25FL_Handle flashHandle);


/*!
 *  @brief  This API enables the quad enable bit in the flash device. This will
 *          called only if 4-Line(QUAD) transfers through QSPI interface.
 *
 *  @param  flashHandle  A S25FL_Handle
 *  @return status       status of the operation
 *
 */
extern bool S25FLFlash_QuadModeEnable(S25FL_Handle flashHandle);


/*!
 *  @brief  This API erases a sector of QSPI flash device by sending the command
 *          through QSPI controller.

 *  @param  flashHandle  A S25FL_Handle
 *  @return none
 *
 */
extern bool S25FLFlash_SectorErase(S25FL_Handle flashHandle,
                                   unsigned int sectorNumber);


/*!
 *  @brief  This API erases a block of QSPI flash device by sending the command
 *          through QSPI controller.

 *  @param  flashHandle  A S25FL_Handle
 *  @return none
 *
 */
extern bool S25FLFlash_BlockErase(S25FL_Handle flashHandle,
                                  unsigned int blockNumber);


/*!
 *  @brief  This API prints the flash id.

 *  @param  flashHandle  A S25FL_Handle
 *  @return none
 *
 */
extern void FlashPrintId(S25FL_Handle flashHandle);

#ifdef __cplusplus /* If this is a C++ compiler, end C linkage */
}
#endif

#endif /* __S25FL_H */
