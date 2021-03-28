/**
 * \file       qspi_lib.h
 *
 * \brief      This file contains the function prototypes, structures
 *             and enums for QSPI flash required to communicate with
 *             QSPI flash device.
 */

/**
 * \copyright  Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/**
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *    Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 *    Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the
 *    distribution.
 *
 *    Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 *  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 *  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 *  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 *  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 *  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */
#ifndef QSPI_LIB_H_
#define QSPI_LIB_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                          Macros and typedefs                               */
/* ========================================================================== */

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */


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
    QSPI_LIB_CMD_FULL_ERASE = 0x60U,
    /**< Completely erase flash data */
    QSPI_LIB_CMD_ENTER_4_BYTE_ADDR = 0xB7U,
    /**< Command to enter 4 byte addressing mode */
    QSPI_LIB_CMD_EXIT_4_BYTE_ADDR = 0xE9U
    /**< Command to exit 4 byte addressing mode */
}qspiLibCmd_t;


/**
 * \brief  This enumerates the data transfer mode
 *         for qspi flash device i.e. config mode
 *         using configuration registers or memory mapped mode
 */
typedef enum qspiLibTxMode
{
    QSPI_LIB_TX_MODE_CONFIG_MODE = 0x0U,
    /**< QSPI data transfer in config mode */
    QSPI_LIB_TX_MODE_MEMORY_MAPPED = 0x1U
    /**< QSPI data transfer in memory mapped mode */
}qspiLibTxMode_t;


/**
 * \brief This enumnerates the read type for a
 *        qspi flash device i.e. single, dual or quad
 *        read.
 */
typedef enum qspiLibReadType
{
    QSPI_LIB_READ_TYPE_SINGLE = 0x0U,
    /**< Single read mode*/
    QSPI_LIB_READ_TYPE_DUAL = 0x1U,
    /**< Dual read mode*/
    QSPI_LIB_READ_TYPE_QUAD = 0x2U,
    /**< Quad read mode*/
}qspiLibReadType_t;

/**
 * \brief  This structure defined the QSPI controller information.
 *         This information has to be entered by the user from
 *         the application.
 */
typedef struct qspiLibCtrlInfo
{
    uint32_t chipSelect;
    /**< Chip select on which the device is interfaced */
    uint32_t memMapBaseAddr;
    /**< QSPI memory mapped base address */
    uint32_t cfgBaseAddr;
    /**< QSPI configuration registers base address */
    qspiLibReadType_t qspiLibReadType;
    /**< Read type for read from flash device i.e. single, dual or quad */
    qspiLibTxMode_t qspiLibTxMode;
    /**< Transfer mode i.e. memory mapped mode or config mode */
} qspiLibCtrlInfo_t;

/**
 * \brief This structure defines the QSPI flash related information.
 */
typedef struct qspiLibFlashInfo
{
    uint32_t deviceSize;
    /**< Size of the flash device */
    uint32_t flashDevId;
    /**< Device ID of the QSPI flash device */
    uint32_t flashMfgId;
    /**< Manufacturer ID of the flash device */
    uint32_t sectorSize;
    /**< Size of the each sector of flash */
    uint32_t blockSize;
    /**< Size of each block of flash */
}qspiLibFlashInfo_t;

/**
 * \brief  This structure defines the QSPI controller and flash device info.
 */
typedef struct qspiLibInfo
{
    qspiLibCtrlInfo_t qspiLibCtrlInfo;
    /**< This contains details about QSPI controller */
    qspiLibFlashInfo_t qspiLibFlashInfo;
    /**< this contains details about QSPI flash device */
}qspiLibInfo_t;
/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief This API initializes the QSPI controller for
 *        read/ write and erase in desired mode.
 *
 * \param  pQspiLibInfo       Pointer to structure containing QSPI controller and
 *                            Flash device Info.
 *
 */
void QSPILibInit(qspiLibInfo_t *pQspiLibInfo);

/**
 * \brief  This API erases a block of QSPI flash device
 *         by sending the command through QSPI controller.
 *
 * \param  pQspiLibInfo       Pointer to structure containing QSPI controller and
 *                            Flash device Info.
 * \param  blockNumber     The block number from where erase has to start.
 */
void QSPILibBlockErase(qspiLibInfo_t *pQspiLibInfo, uint32_t blockNumber);

/**
 * \brief  This API sends chip erase command using QSPI
 *         to erase whole QSPI flash memory.
 *
 * \param  pQspiLibInfo       Pointer to structure containing QSPI controller and
 *                            Flash device Info.
 */
void QSPILibChipErase(qspiLibInfo_t *pQspiLibInfo);

/**
 * \brief  This API reads the device ID and manufacturer ID
 *         from QSPI flash device and display the result on the
 *         console.
 *
 * \param  pQspiLibInfo       Pointer to structure containing QSPI controller and
 *                            Flash device Info.
 */
void QSPILibPrintId(qspiLibInfo_t *pQspiLibInfo);

/**
 * \brief  This API is used to read data from the QSPI flash device.
 *         The number of bytes to be read is passed as function parameter.
 *
 * \param  pQspiLibInfo       Pointer to structure containing QSPI controller and
 *                            Flash device Info.
 * \param srcOffsetAddr    Source Offset address
 * \param dstAddr          destination address
 * \param length           length of data to be read
 *
 * \retval S_PASS          Read successful
 * \retval E_FAIL          Read failed
 *
 */
int32_t QSPILibRead(qspiLibInfo_t *pQspiLibInfo,
                 uint32_t srcOffsetAddr,
                 uint32_t dstAddr,
                 uint32_t length);

/**
 * \brief  This API writes data to flash device
 *         using QSPI controller.
 *
 * \param  pQspiLibInfo       Pointer to structure containing QSPI controller and
 *                            Flash device Info.
 * \param dstOffsetAddr       Destination offset address
 * \param srcAddr             Source address
 * \param length              Length of data to be written
 *
 * \retval S_PASS             Write Successful
 * \retval E_FAIL             Write failed
 */
int32_t QSPILibWrite(qspiLibInfo_t *pQspiLibInfo,
                  uint32_t dstOffsetAddr,
                  uint32_t srcAddr,
                  uint32_t length);

/**
 * \brief This API enables the quad enable bit in the flash device
 *
 * \param  pQspiLibInfo       Pointer to structure containing QSPI controller and
 *                            Flash device Info.
 * \param qspiFlashDeviceData      qspi flash specific data required to enable the quad
 *                                 quad enable bit.
 */
void QSPILibQuadEnable(qspiLibInfo_t *pQspiLibInfo,
                       qspiFlashDeviceData_t *qspiFlashDeviceData);

#ifdef __cplusplus
}
#endif

#endif /* #ifndef QSPI_LIB_H */
