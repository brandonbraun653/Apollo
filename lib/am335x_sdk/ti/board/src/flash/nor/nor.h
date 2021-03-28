/*
 * Copyright (c) 2016 - 2019, Texas Instruments Incorporated
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
 *
 */

/**
 *
 * \file  nor.h
 *
 * \brief This file contains structure, typedefs, functions and
 *        prototypes used for NOR flash.
 *
 *****************************************************************************/
#ifndef NOR_H_
#define NOR_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

/**
 *  @brief 	This type defines the handle returned to a NOR flash interface that is opened.
 *  		The handle must be used in all subsequent operations.
 *
 */
typedef uintptr_t NOR_HANDLE;

/** NOR function return status */
#define NOR_STATUS                       int32_t

/** NOR return type macros */
/** \brief On Success. */
#define NOR_PASS                         (0U)

/** \brief On Failure. */
#define NOR_FAIL                         (-1U)

/** \brief Error code for Timeout. */
#define NOR_TIMEOUT                      (-2U)

/** \brief Error code to indicate invalid parameter. */
#define NOR_INVALID_PARAM                (-3U)

/*
* \breif NOR device size (bus width) in bits
* @{
*/
#define NOR_BUSWIDTH_8BITS               (0U)
#define NOR_BUSWIDTH_16BITS              (1U)
#define NOR_BUSWIDTH_32BITS              (2U)


/** Modes for Write and Read operation */
/**
 *  @brief 	Modes for QSPI NOR Write and Read operation.
 *
 */
/** Modes for Write and Read operation */
#define QSPI_FLASH_SINGLE_READ           (0U)
#define QSPI_FLASH_DUAL_READ             (1U)
#define QSPI_FLASH_QUAD_READ             (2U)

#define QSPI_FLASH_SINGLE_PAGE_PROG      (0U)
#define QSPI_FLASH_QUAD_PAGE_PROG        (2U)

/**
 *  @brief  Modes for OSPI NOR Write and Read operation.
 *
 */
/** Modes for Write and Read operation */
#define OSPI_FLASH_SINGLE_READ           (0U)
#define OSPI_FLASH_OCTAL_READ            (1U)

#define OSPI_FLASH_SINGLE_PAGE_PROG      (0U)
#define OSPI_FLASH_OCTAL_PAGE_PROG       (1U)

/**
 *  @brief This structure contains information about the NOR flash device
 *
 */
typedef struct
{
    /*! NOR HW interface handle */
    uintptr_t hwHandle;
    /*! manufacturer ID*/
    uint32_t manufacturerId;
    /*! Manufacturers device ID */
    uint32_t deviceId;
    /*! bus width in bits */
    uint32_t busWidth;
    /*! Total blocks. First block starts at 0. */
    uint32_t blockCnt;
    /*! Page count per block*/
    uint32_t pageCnt;
    /*! Number of bytes in a page */
    uint32_t pageSize;
    /*! NOR flash base address */
    uintptr_t baseAddr;
    /*! Number of bytes in a sector */
    uint32_t sectorSize;

} NOR_Info;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              NOR_open().
 */
typedef NOR_HANDLE (*NOR_OpenFxn)(uint32_t  norIntf, uint32_t portNum, void *params);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              NOR_CloseFxn().
 */
typedef void (*NOR_CloseFxn)(NOR_HANDLE handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              NOR_ReadFxn().
 */
typedef NOR_STATUS (*NOR_ReadFxn)(NOR_HANDLE handle,
                                  uint32_t addr,
                                  uint32_t len,
                                  uint8_t *buf,
                                  uint32_t mode);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              NOR_WriteFxn().
 */
typedef NOR_STATUS (*NOR_WriteFxn)(NOR_HANDLE handle,
                                   uint32_t addr,
                                   uint32_t len,
                                   uint8_t *buf,
                                   uint32_t mode);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              NOR_EraseFxn().
 */
typedef NOR_STATUS (*NOR_EraseFxn)(NOR_HANDLE handle,
                                   int32_t blk,
								   bool blkErase);


typedef struct NOR_FxnTable_s {
    /*! Function to initialize the given data object */
    NOR_OpenFxn            openFxn;
    /*! Function to close the specified peripheral */
    NOR_CloseFxn           closeFxn;
    /*! Function to read from the specified peripheral */
    NOR_ReadFxn            readFxn;
    /*! Function to write from the specified peripheral */
    NOR_WriteFxn           writeFxn;
    /*! Function to erase blocks from the specified peripheral */
    NOR_EraseFxn           eraseFxn;

} NOR_FxnTable;


/*! @brief NAND Global configuration */
typedef struct NOR_Config_s {
    /*! Pointer to a table of a driver-specific implementation of NOR functions */
    const NOR_FxnTable *fxnTablePtr;
} NOR_Config;

/**************************************************************************
 **                      API function Prototypes
 **************************************************************************/

/**
 *  @brief  Function to open the NOR peripheral
 *
 *  @param  norIntf  NOR peripheral interface ID
 *  @param  portNum  port number of a peripheral interface connecting to the NOR device
 *  @param  params   pointer to the configuration parameters of the peripheral
 *
 *  @pre    The NOR_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other NOR driver APIs.
 *
 *  @return A NOR_HANDLE on success or a NULL on an error or if it has been
 *          already initialized
 *
 **/
NOR_HANDLE NOR_open(uint32_t  norIntf, uint32_t portNum, void *params);

/**
 *  @brief  Function to close the NOR peripheral specified by the nand
 *  handle.
 *
 *  @pre    NOR_open() had to be called first.
 *
 *  @param  handle  A NOR_HANDLE returned from NOR_open
 *
 *  @return NOR_STATUS.
 *
 *  @sa     NOR_open
 *
 **/
void NOR_close(NOR_HANDLE handle);

/**
 * \brief     Reads the data from the NOR FLASH device.
 *
 * \param     handle  [IN]  : NOR flash device handle
 * \param     addr    [IN]  : Address of the NOR flash device in bytes.
 * \param     len     [IN]  : Length of the data to be read in bytes.
 * \param     buf     [IN]  : Pointer to the buffer of read data.
 * \param     mode    [IN]  : Mode of the FLASH device to be operated
 *                            (for QSPI interface only)
 *                            QSPI_FLASH_SINGLE_READ - Single mode.
 *                            QSPI_FLASH_DUAL_READ   - Dual mode.
 *                            QSPI_FLASH_QUAD_READ   - Quad mode.
 *
 * \return    NOR_PASS      : if success.
 *            NOR_FAIL      : if error.
 *
 **/
NOR_STATUS NOR_read(NOR_HANDLE handle, uint32_t addr,
                    uint32_t len, uint8_t *buf, uint32_t mode);

/**
 * \brief     Writes the data into the NOR FLASH device.
 *
 * \param     handle  [IN]  : NOR flash device handle
 * \param     addr    [IN]	: Address of the NOR FLASH device in bytes.
 * \param     len     [IN]	: Length of the data to be written in bytes.
 * \param     buf     [IN]	: Pointer to the buffer of data to be
 *                            written.
 * \param     mode    [IN]	: Mode of the NOR FLASH device to be
 *                            operated. (for QSPI interface only)
 *                            QSPI_FLASH_SINGLE_PAGE_PROG - Single mode.
 *                            QSPI_FLASH_QUAD_PAGE_PROG	  - Quad mode.
 *
 * \return    NOR_PASS      : if success.
 *            NOR_FAIL      : if error.
 *
 **/
NOR_STATUS NOR_write(NOR_HANDLE handle, uint32_t addr,
                     uint32_t len, uint8_t *buf, uint32_t mode);

/**
 * \brief     Erase the NOR FLASH device.
 *
 * This function can perform block (sector) erase or complete device erase
 * of the NOR flash.
 *
 * \param     handle  [IN]      : flash device handle
 * \param     sector  [IN]      : Sector number to be erased
 *                                if -1, device erase
 * \param     blkErase[IN]      : false - Sector erase
 *                                true - Bloack erase
 *
 * \return    NOR_PASS      : if success.
 *            NOR_FAIL      : if error.
 *
 **/
NOR_STATUS NOR_erase(NOR_HANDLE handle, int32_t sector, bool blkErase);

extern const NOR_FxnTable Nor_spiFxnTable;
extern const NOR_FxnTable Nor_qspiFxnTable;
extern const NOR_FxnTable Nor_gpmcFxnTable;
extern const NOR_FxnTable Nor_ospiFxnTable;
extern const NOR_FxnTable Nor_hpfFxnTable;

#ifdef __cplusplus
}
#endif

#endif /* NOR_H_ */

/* Nothing past this point */
