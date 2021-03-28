/*
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
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
 * \file  nand.h
 *
 * \brief This file contains structure, typedefs, functions and
 *        prototypes used for NAND flash.
 *
 *****************************************************************************/
#ifndef NAND_H_
#define NAND_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

/**
 *  @brief 	This type defines the handle returned to a NAND flash interface that is opened.
 *  		The handle must be used in all subsequent operations.
 *
 */
typedef uint32_t NAND_HANDLE;

/** NAND function return status */
#define NAND_STATUS                     int32_t

/** NAND return type macros */
/** \brief On Success. */
#define NAND_PASS                         (0U)

/** \brief On Failure. */
#define NAND_FAIL                         (-1U)

/** \brief Error code for Timeout. */
#define NAND_TIMEOUT                      (-2U)

/** \brief Error code to indicate mode not supported. */
#define NAND_MODE_NOT_SUPP                (-3U)

/** \brief Error code to indicate invalid parameter. */
#define NAND_INVALID_PARAM                (-4U)

/** \brief Error code to indicate DMA operation failure. */
#define NAND_DMA_FAIL                     (-5U)

/** \brief Error code to indicate NAND device is Busy. */
#define NAND_DEV_BUSY                     (-6U)

/** \brief Error code to indicate NAND device is Write Protected. */
#define NAND_DEV_PROTECTED                (-7U)

/** \brief Error code to indicate ECC error for the last access. */
#define NAND_ECC_ERR                      (-8U)

/** \brief Error code to indicate ECC error is corrected. */
#define NAND_ECC_ERR_CORRECTED            (-9U)

/** \brief Error code to indicate Uncorrectable ecc errrors. */
#define NAND_ECC_UNCORRECTABLE            (-10U)

/** \brief Error code to indicate Block is good to read/write. */
#define NAND_BLOCK_GOOD                   (-11U)

/** \brief Error code to indicate Block is marked as Bad. */
#define NAND_BLOCK_BAD                    (-12U)

/** \brief Error code to indicate failure in reading the spare area of the
           page. */
#define NAND_SPARE_AREA_READ_FAIL         (-13U)

/*
* \breif NAND device size (bus width) in bits
* @{
*/
#define NAND_BUSWIDTH_8BITS               (0U)
#define NAND_BUSWIDTH_16BITS              (1U)
#define NAND_BUSWIDTH_32BITS              (2U)

/*
* \breif NAND bad block flags
*/
#define NAND_BAD_BLOCK                    (1U)
#define NAND_GOOD_BLOCK                   (0U)

/** \brief Enumerates the different ECC algorithms used for Error Correction. */
typedef enum NAND_EccAlgo
{
    NAND_ECC_ALGO_NONE = 0U,
    /**< Value to denote no usage of ECC for Read/Write. */
    NAND_ECC_ALGO_HAMMING_1BIT,
    /**< Value to represent the Hamming Code ECC algorithm to correct up to
         one bit error in a block. */
    NAND_ECC_ALGO_BCH_4BIT,
    /**< Value to represent the BCH ECC algorithm to correct up to 4 bits of
         errors in a block.*/
    NAND_ECC_ALGO_BCH_8BIT,
    /**< Value to represent the BCH ECC algorithm to correct up to 8 bits of
         errors in a block.*/
    NAND_ECC_ALGO_BCH_16BIT
    /**< Value to represent the BCH ECC algorithm to correct up to 8 bits of
         errors in a block.*/

}NAND_EccAlgo;

/**
 *  @brief This structure contains information about the NAND flash device
 *
 */
typedef struct
{
    /*! NAND HW interface handle */
    uint32_t hwHandle;
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
    /*! Number of bytes in a page including spare area */
    uint32_t pageSize;
    /*! Spare area size in bytes*/
    uint32_t spareSize;
    /*! Offset into spare area to check for a bad block */
    uint32_t bbOffset;
    /*! Bad Block list or NULL if device does not support one  */
    uint8_t *bbList;
    /*! ECC algorithm supported */
    uint32_t eccAlgo;
    /*! ECC Offset value in OOB  */
    uint32_t eccOffset;
    /*! ECC byte count value in OOB  */
    uint32_t eccByteCount;

} NAND_Info;

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              NAND_open().
 */
typedef NAND_HANDLE (*NAND_OpenFxn)(uint32_t nandIntf, uint32_t portNum, void *params);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              NAND_CloseFxn().
 */
typedef void (*NAND_CloseFxn)(NAND_HANDLE handle);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              NAND_ReadFxn().
 */
typedef NAND_STATUS (*NAND_ReadFxn)(NAND_HANDLE handle,
                                    uint32_t addr,
                                    uint32_t len,
                                    uint8_t *buf);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              NAND_WriteFxn().
 */
typedef NAND_STATUS (*NAND_WriteFxn)(NAND_HANDLE handle,
                                     uint32_t addr,
                                     uint32_t len,
                                     uint8_t *buf);

/*!
 *  @brief      A function pointer to a driver specific implementation of
 *              NAND_EraseFxn().
 */
typedef NAND_STATUS (*NAND_EraseFxn)(NAND_HANDLE handle,
                                     int32_t blk);


typedef struct NAND_FxnTable_s {
    /*! Function to initialize the given data object */
    NAND_OpenFxn            openFxn;
    /*! Function to close the specified peripheral */
    NAND_CloseFxn           closeFxn;
    /*! Function to read from the specified peripheral */
    NAND_ReadFxn            readFxn;
    /*! Function to write from the specified peripheral */
    NAND_WriteFxn           writeFxn;
    /*! Function to erase blocks from the specified peripheral */
    NAND_EraseFxn           eraseFxn;

} NAND_FxnTable;


/*! @brief NAND Global configuration */
typedef struct NAND_Config_s {
    /*! Pointer to a table of a driver-specific implementation of NAND functions */
    const NAND_FxnTable *fxnTablePtr;

} NAND_Config;


/*!
 *  @brief  Function to open the NAND peripheral
 *
 *  @param  nandIntf NAND peripheral interface ID
 *  @param  portNum  port number of a peripheral interface connecting to the NAND device
 *  @param  params   pointer to the configuration parameters of the peripheral
 *
 *  @pre    The NAND_config structure must exist and be persistent before this
 *          function can be called. This function must also be called before
 *          any other NAND driver APIs.
 *
 *  @return A NAND_HANDLE on success or a NULL on an error or if it has been
 *          already initialized
 */
extern NAND_HANDLE NAND_open(uint32_t nandIntf, uint32_t portNum, void *params);

/*!
 *  @brief  Function to close the NAND peripheral specified by the nand
 *  handle.
 *
 *  @pre    NAND_open() had to be called first.
 *
 *  @param  handle  A NAND_HANDLE returned from NAND_open
 *
 *  @return NAND_STATUS.
 *
 *  @sa     NAND_open
 */
extern void NAND_close(NAND_HANDLE handle);


/*!
 *  @brief  Function that read data from NAND
 *
 *  This function initiates an operation to read data from NAND.
 *
 *
 *  @param  handle      A NAND_HANDLE
 *  @param  addr        data address of the NAND flash device to read
 *  @param  len         The number of bytes to read
 *  @param  buffer      A pointer to an empty buffer in which read data should be
 *                      written to
 *
 *  @return NAND_STATUS.
 */
extern NAND_STATUS NAND_read(NAND_HANDLE handle, uint32_t addr, uint32_t len, uint8_t *buf);

/*!
 *  @brief  Function that writes data to the NAND
 *
 *  This function initiates an operation to write data to the NAND.
 *
 *  @param  handle      A NAND_HANDLE
 *  @param  addr        data address of the NAND flash device to write
 *  @param  len         The number of bytes to write
 *  @param  buffer      A pointer to buffer containing data to be written to NAND
 *
 *  @return NAND_STATUS.
 */
extern NAND_STATUS NAND_write(NAND_HANDLE handle, uint32_t addr, uint32_t len, uint8_t *buf);

/*!
 *  @brief  Function that erase a NAND block or NAND chip
 *
 *  This function initiates an operation to erase NAND block or chip.
 *
 *  NAND_write will not return until all the data was written to the NAND.
 *
 *  @param  handle      A NAND_HANDLE
 *  @param  blk         NAND flash block number to erase
 *
 *  @return NAND_STATUS.
 */
extern NAND_STATUS NAND_erase(NAND_HANDLE handle, int32_t blk);

extern const NAND_FxnTable Nand_gpmcFxnTable;

#ifdef __cplusplus
}
#endif

#endif /* NAND_H_ */

/* Nothing past this point */
