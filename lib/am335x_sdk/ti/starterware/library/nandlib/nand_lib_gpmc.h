/**
 *  \file   nand_lib_gpmc.h
 *
 *  \brief  This file contains the GPMC controller specific structure
 *          definition, macros and function prototypes for NAND device access.
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


#ifndef NAND_LIB_GPMC_H_
#define NAND_LIB_GPMC_H_

#include "gpmc.h"
#include "elm.h"
#include "nand_lib.h"

#ifdef __cplusplus
extern "C" {
#endif

/* ========================================================================== */
/*                                     Macros                                 */
/* ========================================================================== */

/** \brief Macro defining the Hamming Code ECC Offset value. */
#define NAND_LIB_ECC_1BIT_HAMMINGCODE_OOB_OFFSET          (1U)

/** \brief Macro defining the Hamming Code ECC Byte Count value. */
#define NAND_LIB_ECC_1BIT_HAMMINGCODE_BYTECNT             (3U)

/** \brief Macro defining the 4-bit Reed-Solomon ECC Offset value. */
#define NAND_LIB_ECC_RS_4BIT_OOB_OFFSET                   (0U)

/** \brief Macro defining the 4-bit Reed-Solomon ECC Byte Count value. */
#define NAND_LIB_ECC_RS_4BIT_UNUSED_BYTECNT               (6U)

/** \brief Macro defining the 4-bit Reed-Solomon ECC Byte Count value. */
#define NAND_LIB_ECC_RS_4BIT_BYTECNT                      (10U)

/** \brief Macro defining the 8-bit BCH ECC Offset value. */
#define NAND_LIB_ECC_BCH_8BIT_OOB_OFFSET                  (2U)

/** \brief Macro defining the 8-bit BCH ECC Byte Count value. */
#define NAND_LIB_ECC_BCH_8BIT_BYTECNT                     (14U)

/** \brief Macro defining the 8-bit BCH ECC Unused Byte Count value. */
#define NAND_LIB_ECC_BCH_8BIT_UNUSED_BYTECNT              (2U)

/** \brief Macro defining the 8-bit BCH ECC Nibble Count value. */
#define NAND_LIB_ECC_BCH_8BIT_NIBBLECNT                   (26U)

/** \brief Macro defining the Last Data bit for 8-bit BCH ECC scheme. */
#define NAND_LIB_ECC_BCH_8BIT_LASTDATABIT                 ((512 + 13) * 8)

/** \brief Macro defining the Last ECC bit for 8-bit BCH ECC scheme. */
#define NAND_LIB_ECC_BCH_8BIT_LASTECCBIT                  ((13 + 1) * 8)

/** \brief Macro defining the Number of Bytes per Transfer. */
#define NAND_LIB_BYTES_PER_TRNFS                          (512)

/** \brief Macro defining the Number of ECC bytes per Transfer. */
#define NAND_LIB_MAX_ECC_BYTES_PER_TRNFS                  (16)

/** \brief Macro to define the Read DMA transfer */
#define NAND_LIB_DMA_READ                                 (0U)

/** \brief Macro to define the Read DMA transfer */
#define NAND_LIB_DMA_WRITE                                (1U)

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief Enumerates the different DMA transfer types. */
typedef enum nandLibDmaXferType
{
    NAND_LIB_DMA_XFER_TYPE_READ = 0U,
    /**< Macro to denote DMA Write Operation. */
    NAND_LIB_DMA_XFER_TYPE_WRITE = 1U
    /**< Macro to denote DMA Read Operation. */
}nandLibDmaXferType_t;

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief    Function to initialize the NAND controller.
 *
 * \param    pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                       flash device information.
 *
 * \retval   NAND_LIB_PASS      On successful initialization of GPMC.
 * \retval   NAND_LIB_TIMEOUT   On a timeout error.
 */
int32_t NANDLibGpmcInit(nandLibInfo_t *pNandInfo);

/**
 *  \brief   Function to get the wait pin status.
 *
 * \param    pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                       flash device information.
 *
 * \retval   status      The Wait pin status can be one of the values from the
 *                       following enum gpmcWaitPinSts_t
 */
uint32_t NANDLibGpmcWaitPinStatus(nandLibInfo_t *pNandInfo);

/**
 * \brief    Function to get the GPMC FIFO status.
 *
 * \param    pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                       flash device information.
 *
 * \retval   TRUE    If the FIFO is Empty.
 * \retval   FALSE   IF the FIFO is Full.
 */
uint32_t NANDLibGpmcFifoStatus(nandLibInfo_t *pNandInfo);

/**
 * \brief   Function to read a byte of data from GPMC.
 *
 * \param   pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                      flash device information.
 *
 * \retval  data        The byte read from the device attached to the GPMC.
 */
uint32_t NANDLibGpmcGetData(nandLibInfo_t *pNandInfo);

/**
 * \brief   Function to write the data to the GPMC data register.
 *
 * \param   pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                      flash device information.
 * \param   data        the data to be written to the data register.
 */
void NANDLibGpmcSetData(nandLibInfo_t *pNandInfo, uint32_t data);

/**
 * \brief   Function to issue a NAND command to the device connected to the
 *          GPMC.
 *
 * \param   pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                      flash device information.
 * \param   command     The command to be written to the GPMC before interfacing
 *                      the connected device.
 */
void NANDLibGpmcSetCommand(nandLibInfo_t *pNandInfo, uint32_t command);

/**
 * \brief   Function to issue a NAND command to the device connected to the
 *          GPMC.
 *
 * \param   pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                      flash device information.
 * \param   addr        The address to be written to the GPMC connected device
 *                      before interfacing the connected device.
 */
void NANDLibGpmcSetAddr(nandLibInfo_t *pNandInfo, uint32_t addr);

/**
 *  \brief    This function does the ECC related initializes to the NAND
 *            controller depending on the ecc type.
 *
 *  \param    pNandInfo  Pointer to the nandLibInfo_t structure containing the
 *                       flash device information.
 *
 *  \retval   NAND_LIB_PASS    On Successful initialization.
 *  \retval   NAND_LIB_FAIL    On GPMC ECC initialization failure.
 */
int32_t NANDLibGpmcEccInit(nandLibInfo_t *pNandInfo);

/**
 *  \brief    This function enable the ECC scheme for the GPMC access to the
 *             device connected.
 *
 *  \param    pNandInfo  Pointer to the nandLibInfo_t structure containing the
 *                       flash device information.
 */
void NANDLibGpmcEccEnable(nandLibInfo_t *pNandInfo);

/**
 *  \brief    This function disable the ECC  the ECC scheme for the GPMC access
 *            to the device connected.
 *
 *  \param    pNandInfo  Pointer to the nandLibInfo_t structure containing the
 *                       flash device information.
 */
void NANDLibGpmcEccDisable(nandLibInfo_t *pNandInfo);

/**
 *  \brief  This Function configures the ECC setting for Read operation.
 *
 *  \param  pNandInfo     Pointer to the nandLibInfo_t structure containing the
 *                        flash device information.
 */
void NANDLibGpmcEccReadSet(nandLibInfo_t *pNandInfo);

/**
 *  \brief   This Function configures the ECC setting for Write operation
 *
 *  \param   pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                       flash device information.
 */
void NANDLibGpmcEccWriteSet(nandLibInfo_t *pNandInfo);

/**
 *  \brief   This function reads the ECC data.
 *
 *  \param   pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                       flash device information.
 *  \param   pEccData    Pointer where read ECC data has to store.
 */
void NANDLibGpmcEccCalculate(nandLibInfo_t *pNandInfo,
                             uint8_t *pEccData);

/**
 *  \brief    This function checks and corrects ECC errors.
 *
 *  \param    pNandInfo   Pointer to the nandLibInfo_t structure containing the
 *                        flash device information.
 *  \param    pEccRead    Pointer to the ECC data which is read from the spare
 *                        area.
 *  \param    pData       Pointer to the data, where if an ecc error need to
 *                        correct.
 *
 *  \retval   NAND_LIB_PASS      If there are no errors for the Read/Write Operation.
 *  \retval   NAND_STATUS_READ_ECC_ERROR_CORRECTED      : If error are corrected.
 *  \retval   NAND_STATUS_READ_ECC_UNCORRECTABLE_ERROR  : If errors are uncorrectable.
 */
int32_t NANDLibGpmcEccCheckAndCorrect(nandLibInfo_t *pNandInfo,
                                      uint8_t *pEccRead,
                                      uint8_t *pData);


#ifdef __cplusplus
}
#endif
#endif
