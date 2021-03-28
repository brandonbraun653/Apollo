/**
 *  \file   nand_lib.h
 *
 *  \brief  Definitions used for NAND Abstracting Library.
 *
 *   This file contains the macros, structures, function prototypes used by
 *   nand application, abstraction layer, and platform specific layer.
 */

/**
 * \copyright  Copyright (C) 2013 - 2018 Texas Instruments Incorporated -
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


#ifndef NAND_LIB_H_
#define NAND_LIB_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "nand_device.h"

#ifdef __cplusplus
extern "C"
{
#endif

/* ========================================================================== */
/*                          Macros and typedefs                               */
/* ========================================================================== */

/** \name NAND Library specific Status and error codes.  */

/** @{ */

/** \brief On Success. */
#define NAND_LIB_PASS                         (0)

/** \brief On Failure. */
#define NAND_LIB_FAIL                         (-1)

/** \brief Error code for Timeout. */
#define NAND_LIB_TIMEOUT                      (-2)

/** \brief Error code to indicate mode not supported. */
#define NAND_LIB_MODE_NOT_SUPP                (-3)

/** \brief Error code to indicate invalid parameter. */
#define NAND_LIB_INVALID_PARAM                (-4)

/** \brief Error code to indicate DMA operation failure. */
#define NAND_LIB_DMA_FAIL                   (-5)

/** \brief Error code to indicate NAND device is Busy. */
#define NAND_LIB_DEV_BUSY                     (-6)

/** \brief Error code to indicate NAND device is Write Protected. */
#define NAND_LIB_DEV_PROTECTED                (-7)

/** \brief Error code to indicate ECC error for the last access. */
#define NAND_LIB_ECC_ERR                      (-8)

/** \brief Error code to indicate ECC error is corrected. */
#define NAND_LIB_ECC_ERR_CORRECTED            (-9)

/** \brief Error code to indicate Uncorrectable ecc errrors. */
#define NAND_LIB_ECC_UNCORRECTABLE            (-10)

/** \brief Error code to indicate Block is good to read/write. */
#define NAND_LIB_BLOCK_GOOD                   (-11)

/** \brief Error code to indicate Block is marked as Bad. */
#define NAND_LIB_BLOCK_BAD                    (-12)

/** \brief Error code to indicate failure in reading the spare area of the
           page. */
#define NAND_LIB_SPARE_AREA_READ_FAIL         (-13)
/** @} */

/** \brief Enumerates the different Bus width of the NAND device. */
typedef enum nandLibBusWidth
{
    NAND_LIB_BUS_WIDTH_MIN = 0U,
    /**< Minimum supported bus width of the NAND device. */
    NAND_LIB_BUS_WIDTH_8BIT = NAND_LIB_BUS_WIDTH_MIN,
    /**< 8 bit bus width of the NAND device. */
    NAND_LIB_BUS_WIDTH_16BIT,
    /**< 16 bit bus width of the NAND device. */
    NAND_LIB_BUS_WIDTH_MAX = NAND_LIB_BUS_WIDTH_16BIT
    /**< Maximum supported bus width of the NAND device. */
}nandLibBusWidth_t;

/** \brief Enumerates the different memory controller used to interface the NAND
           device. */
typedef enum nandLibMemCtrlr
{
    NAND_LIB_MEM_CTRLR_MIN = 0U,
    /**< Minimum value to represent the memory controller used to interface.*/
    NAND_LIB_MEM_CTRLR_GPMC = NAND_LIB_MEM_CTRLR_MIN,
    /**< Macro to represent General Purpose Memory Controller(GPMC) to interface
         NAND device. */
    NAND_LIB_MEM_CTRLR_MAX = NAND_LIB_MEM_CTRLR_GPMC
    /**< Maximum value to represent the memory controller used to interface.*/
}nandLibMemCtrlr_t;

/** \brief Enumerates the different ECC algorithms used for Error Correction. */
typedef enum nandLibEccAlgo
{
    NAND_LIB_ECC_ALGO_MIN = 0U,
    /**< Minimum value to represent the different ECC schemes supported by
         NAND library. */
    NAND_LIB_ECC_ALGO_NONE = NAND_LIB_ECC_ALGO_MIN,
    /**< Value to denote no usage of ECC for Read/Write. */
    NAND_LIB_ECC_ALGO_HAMMING_1BIT,
    /**< Value to represent the Hamming Code ECC algorithm to correct up to
         one bit error in a block. */
    NAND_LIB_ECC_ALGO_BCH_4BIT,
    /**< Value to represent the BCH ECC algorithm to correct up to 4 bits of
         errors in a block.*/
    NAND_LIB_ECC_ALGO_BCH_8BIT,
    /**< Value to represent the BCH ECC algorithm to correct up to 8 bits of
         errors in a block.*/
    NAND_LIB_ECC_ALGO_BCH_16BIT,
    /**< Value to represent the BCH ECC algorithm to correct up to 8 bits of
         errors in a block.*/
    NAND_LIB_ECC_ALGO_MAX = NAND_LIB_ECC_ALGO_BCH_16BIT
    /**< Maximum value to represent the different ECC schemes supported by
         NAND library. */
}nandLibEccAlgo_t;

/** \brief Enumerates the different Transfer modes used to interface with the
           NAND flash device. */
typedef enum nandLibXferMode
{
    NAND_LIB_XFER_MODE_MIN = 0U,
    /**< Minimum Transfer mode value. */
    NAND_LIB_XFER_MODE_POLLING = NAND_LIB_XFER_MODE_MIN,
    /**< Polling Transfer mode. */
    NAND_LIB_XFER_MODE_INTR,
    /**< Interrupt Transfer mode. */
    NAND_LIB_XFER_MODE_DMA,
    /**< DMA Transfer mode. */
    NAND_LIB_XFER_MODE_MAX = NAND_LIB_XFER_MODE_DMA
    /**< Maximum Transfer mode value. */
}nandLibXferMode_t;

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

/** \brief This Structure defines the NAND Device controller related
           information. */
typedef struct nandLibCtrlInfo
{
    nandLibMemCtrlr_t    memCtrlr;
    /**< The Memory Controller used to interface the NAND device. */
    uint32_t             baseAddr;
    /**< Base Address of the Memory Controller. */
    uint32_t             elmAddr;
    /**< ELM Base Address for ECC computation. */
    nandLibEccAlgo_t     eccAlgo;
    /**< ECC Scheme supported by the controller */
    nandLibXferMode_t    xferMode;
    /**< The Transfer mode to be used to interface with the NAND device. */
    uint32_t             chipSel;
    /**< Current Active chip select in use by the memory controller. */
}nandLibCtrlInfo_t;

/** \brief This Structure defines the NAND Flash related information. */
typedef struct nandLibFlashInfo
{
    uint8_t             flashMfgId;
    /**< Manufacturer ID of the NAND device. */
    uint8_t             flashDevId;
    /**< Device ID of the NAND device. */
    nandLibBusWidth_t   busWidth;
    /**< Bus Width of the NAND device(8-bit or 16-bit device). */
    uint32_t            waitPinNum;
    /**< Wait pin Number to which the Ready/Busy pin is connected. */
    uint32_t            waitPinPol;
    /**< Wait pin polarity  */
    uint32_t            writeProtectPinLvl;
    /**< Write protect pin polarity */
    nandTimingParams_t     timingParams;
    /**< Structure holding the timing parameters for the device. */
}nandLibFlashInfo_t;

/** \brief  This structure defines the NAND controller and flash device info. */
typedef struct nandLibInfo
{
    nandLibCtrlInfo_t   nandLibCtrlInfo;
    /**< This contains details about the NAND controller. */
    nandLibFlashInfo_t  nandLibFlashInfo;
    /**< This contains details about the NAND flash device. */
}nandLibInfo_t;

/* ========================================================================== */
/*                         Global Variables Declarations                      */
/* ========================================================================== */

/* None */

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 *  \brief    This API initializes the NAND and the associated memory
 *            controller. It calls the registered memory controller
 *            initialization function.
 *
 *  \param    pNandLibInfo   Pointer to the #nandLibInfo_t structure containing
 *                           NAND device controller and flash device Info.
 *
 *  \retval   NAND_LIB_PASS       If the memory controller is initialized successfully.
 *  \retval   NAND_LIB_FAIL       If the memory controller initialization fails.
 *  \retval   NAND_LIB_TIMEOUT    If a timeout occurs during initialization sequence.
 */
int32_t NANDLibInit(nandLibInfo_t *pNandLibInfo);

/**
 *  \brief   This API reads the NAND device parameters and updates the flash
 *           information in the NANDLib structure.
 *
 *  \param   pNandLibInfo   Pointer to the #nandLibInfo_t structure containing
 *                          the flash device information.
 *
 *  \retval  NAND_LIB_PASS  If the device parameters are successfully read from flash.
 *  \retval  NAND_LIB_FAIL  If the device is not found.
 */
int32_t NANDLibReadId(nandLibInfo_t *pNandLibInfo);

/**
 *  \brief   This API resets the NAND device by issuing the RESET command to it.
 *           It then waits till the reset process is complete.
 *
 *  \param   pNandLibInfo   Pointer to the #nandLibInfo_t structure containing
 *                          the flash device and controller information.
 *
 *  \retval  NAND_LIB_PASS  If the device reset is successful.
 *  \retval  NAND_LIB_FAIL  If the device is not successful.
 *  \retval  NAND_LIB_TIMEOUT If a timeout error occurs.
 */
int32_t NANDLibReset(nandLibInfo_t *pNandLibInfo);

/**
 *  \brief   This API reads a Page from the NAND device.
 *
 *  \param   pNandLibInfo   Pointer to the #nandLibInfo_t structure containing
 *                          the flash device and controller information.
 *  \param   blockNum    Block number from where the Page is to be read.
 *  \param   pageNum     The Page number within the block from where to read.
 *  \param   pRxData     Pointer to the data where the data from the Page is to
 *                       be placed.
 *
 *  \retval  NAND_LIB_PASS     If the device reset is successful.
 *  \retval  NAND_LIB_FAIL     If the device is not successful.
 *  \retval  NAND_LIB_TIMEOUT  If a timeout error occurs.
 *  \retval  NAND_LIB_ECC_ERR  If an ECC error occurs during the Read
 *  \retval  NAND_LIB_ECC_ERR_CORRECTED If an ECC error occurs during the Page
 *                                     Read and it is corrected.
 *  \retval  NAND_LIB_DMA_FAIL If an DMA transaction fails during the Page Read
 *                              Operation.
 */
int32_t NANDLibPageRead(nandLibInfo_t *pNandLibInfo,
                        uint32_t blockNum,
                        uint32_t pageNum,
                        uint8_t *pRxData);

/**
 *  \brief   This API writes a Page to the NAND device.
 *
 *  \param   pNandLibInfo   Pointer to the #nandLibInfo_t structure containing
 *                          the flash device and controller information.
 *  \param   blockNum    Block number to which the Page belongs.
 *  \param   pageNum     The Page number within the block which is to be written.
 *  \param   pTxData     Pointer to the data which is to be written to the
 *                       NAND Page.
 *
 *  \retval  NAND_LIB_PASS     If the device reset is successful.
 *  \retval  NAND_LIB_FAIL     If the device is not successful.
 *  \retval  NAND_LIB_TIMEOUT  If a timeout error occurs.
 *  \retval  NAND_LIB_ECC_ERR  If an ECC error occurs during the Read
 *  \retval  NAND_LIB_ECC_ERR_CORRECTED If an ECC error occurs during the
 *                                     Page Read and it is corrected.
 *  \retval  NAND_LIB_DMA_FAIL If an DMA transaction fails during the Page Read
 *                              Operation.
 */
int32_t NANDLibPageWrite(nandLibInfo_t *pNandLibInfo,
                         uint32_t blockNum,
                         uint32_t pageNum,
                         uint8_t *pTxData);

/**
 *  \brief   This API Erases a block within the NAND device.
 *
 *  \param   pNandLibInfo   Pointer to the #nandLibInfo_t structure containing the
 *                       flash device and controller information.
 *  \param   blockNum    Block number to which the Page belongs.
 *
 *  \retval  NAND_LIB_PASS     If the block erase is successful.
 *  \retval  NAND_LIB_FAIL     If the block erase is not successful.
 *  \retval  NAND_LIB_TIMEOUT  If a timeout error occurs while monitoring the Device
 *                      status.
 *  \retval  NAND_LIB_DEV_BUSY If the device is Busy.
 *  \retval  NAND_LIB_DEV_PROTECT If the device is Write Protected.
 */
int32_t NANDLibBlockErase(nandLibInfo_t *pNandLibInfo, uint32_t blockNum);

/**
 *  \brief    This API checks whether the block is Bad or not.
 *
 *  \param    pNandLibInfo   Pointer to the #nandLibInfo_t structure containing the
 *                           flash device and controller information.
 *  \param    blockNum       Block number which is to be checked.
 *
 *  \retval   NAND_LIB_BLOCK_GOOD      If the Block is good.
 *  \retval   NAND_LIB_BLOCK_BAD      If the Block is bad.
 *  \retval   NAND_LIB_SPARE_AREA_READ_FAIL If the Spare Area Read fails.
 */
int32_t NANDLibBadBlockCheck(nandLibInfo_t *pNandLibInfo, uint32_t blockNum);

/**
 *  \brief    This API marks the block number passed by the user as Bad Block.
 *
 *  \param    pNandLibInfo   Pointer to the #nandLibInfo_t structure containing
 *                           the flash device and controller information.
 *  \param    blockNum    Block number which is to be marked as bad.
 *
 *  \retval  NAND_LIB_PASS     On Success.
 *  \retval  NAND_LIB_FAIL     On failure to execute the command.
 *  \retval  NAND_LIB_TIMEOUT  If a timeout error occurs while monitoring the
                               Device status.
 *  \retval  NAND_LIB_DEV_BUSY If the device is Busy.
 *  \retval  NAND_LIB_DEV_PROTECT If the device is Write Protected.
 */
int32_t NANDLibMarkBlockAsBad(nandLibInfo_t *pNandLibInfo, uint32_t blockNum);

#ifdef __cplusplus
}
#endif

#endif /* NAND_LIB_H_ */
