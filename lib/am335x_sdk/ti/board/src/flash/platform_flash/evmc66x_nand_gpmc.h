/*
 * Copyright (c) 2015-2017, Texas Instruments Incorporated
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
 * \file	evmc66x_nand_gpmc.h
 *
 * \brief   This file contains the NAND GPMC controller specific struct
 *          definition, macros and function prototypes.
 *
 ******************************************************************************/

#ifndef _EVMC66X_NAND_GPMC_H_
#define _EVMC66X_NAND_GPMC_H_

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************/
/*
** Macros which defines the number of NAND devices can be connected to system
*/
#define NAND_MAX_CHIP_SELECTS                         (4)

/*****************************************************************************/
/*
** Macros which defines the ECC offset in OOB areaa, ecc byte count(size)
** of diffrent ECC schemes.
**
*/
#define NAND_ECC_1BIT_HAMMINGCODE_OOB_OFFSET          (1)
#define NAND_ECC_1BIT_HAMMINGCODE_BYTECNT             (3)

#define NAND_ECC_RS_4BIT_OOB_OFFSET                   (0)
#define NAND_ECC_RS_4BIT_UNUSED_BYTECNT               (6)
#define NAND_ECC_RS_4BIT_BYTECNT                      (10)

#define NAND_ECC_BCH_8BIT_OOB_OFFSET                  (2)
#define NAND_ECC_BCH_8BIT_BYTECNT                     (14)
#define NAND_ECC_BCH_8BIT_UNUSED_BYTECNT              (2)
#define NAND_ECC_BCH_8BIT_NIBBLECNT                   (26)

/*****************************************************************************/
/*
** Macros which defines the last data and ecc bit in diffrent ECC schemes.
**
*/
/* 512 bytes of data plus 13 bytes ECC */
#define NAND_ECC_BCH_8BIT_LASTDATABIT                 ((512 + 13) * 8)
/* 13 bytes of ECC data plus 1 byte of ECC for ECC data */
#define NAND_ECC_BCH_8BIT_LASTECCBIT                  ((13 + 1) * 8)

/*****************************************************************************/
/*
** Macro which defines the number of bytes sent/received per transfer.
**
*/
#define NAND_BYTES_PER_TRNFS                          (512)
#define NAND_MAX_ECC_BYTES_PER_TRNFS                  (16)


/*****************************************************************************/
/*
** Macro which defines the values stored in OOB as bad block info.
**
*/
#define NAND_BLK_GOOD_MARK                            (0xFF)
#define NAND_BLK_BAD_MARK                             (0)

/*
** Macro which defines the shift value for chip select base address.
*/
#define NAND_BASE_ADDR_SHIFT                    (24)


/*****************************************************************************/
/*
** NandStatus typedef - returned from most NandLib APIs
**
*/
typedef enum _NAND_STATUS_
{
    NAND_STATUS_PASSED                          =  (0x001),
    NAND_STATUS_FAILED                          =  (0x002),
    NAND_STATUS_NOT_FOUND                       =  (0x004),
    NAND_STATUS_DEVBUSY                         =  (0x008),
    NAND_STATUS_DEVWRPROTECT                    =  (0x010),
    NAND_STATUS_WAITTIMEOUT                     =  (0x020),
    NAND_STATUS_READWRITE_DMA_FAIL              =  (0x040),
    NAND_STATUS_ECC_UNSUPPORTED                 =  (0x080),
    NAND_STATUS_READ_ECC_ERROR_CORRECTED        =  (0x100),
    NAND_STATUS_READ_ECC_UNCORRECTABLE_ERROR    =  (0x200)
} NandStatus_t;

/*****************************************************************************/
/*
** Nand ECC alogorithm typedef
**
*/
typedef enum _NAND_ECC_ALGO_
{
    NAND_ECC_ALGO_NONE          =   (0x00),
    NAND_ECC_ALGO_HAMMING_1BIT  =   (0x01),
    NAND_ECC_ALGO_RS_4BIT       =   (0x02),
    NAND_ECC_ALGO_BCH_4BIT      =   (0x04),
    NAND_ECC_ALGO_BCH_8BIT      =   (0x08),
    NAND_ECC_ALGO_BCH_16BIT     =   (0x10)
} NandEccAlgo_t;

/*****************************************************************************/
/*
** NandPageSize typedef
**
*/
typedef enum _NAND_PAGE_SIZE_
{
    NAND_PAGESIZE_INVALID   =   ((0)*(512)),
    NAND_PAGESIZE_512BYTES  =   ((1)*(512)),
    NAND_PAGESIZE_2048BYTES =   ((4)*(512)),
    NAND_PAGESIZE_4096BYTES =   ((8)*(512)),
    NAND_PAGESIZE_8192BYTES =   ((16)*(512))
} NandPageSize_t;

/*****************************************************************************/
/*
** NandBlockSize typedef
**
*/
typedef enum _NAND_BLOCK_SIZE_
{
    NAND_BLOCKSIZE_INVALID   =   ((0)*(1024)),
    NAND_BLOCKSIZE_64KB      =   ((64)*(1024)),
    NAND_BLOCKSIZE_128KB     =   ((128)*(1024)),
    NAND_BLOCKSIZE_256KB     =   ((256)*(1024)),
    NAND_BLOCKSIZE_512KB     =   ((512)*(1024))
} NandBlockSize_t;

/*
** Macros which can be used as 'busWidth' in NANDDevInfo structure.
**
*/
typedef enum _NAND_BUSWIDTH_
{
    NAND_BUSWIDTH_INVALID   = (0xFF),
    NAND_BUSWIDTH_8BIT      = (0x00),
    NAND_BUSWIDTH_16BIT     = (0x01)

} NandBusWidth_t;

/*******************************************************************************
*                           STRUCTURES DECLARION
*******************************************************************************/

/*
** Contains the timing params and base address info for the GPMC NAND access.
*/
typedef struct _NAND_TIMING_INFO_
{
    unsigned int CSWrOffTime;
    unsigned int CSRdOffTime;
    unsigned int CSExtDelayFlag;
    unsigned int CSOnTime;

    unsigned int ADVAADMuxWrOffTime;
    unsigned int ADVAADMuxRdOffTime;
    unsigned int ADVWrOffTime;
    unsigned int ADVRdOffTime;
    unsigned int ADVExtDelayFlag;
    unsigned int ADVAADMuxOnTime;
    unsigned int ADVOnTime;

    unsigned int WEOffTime;
    unsigned int WEExtDelayFlag;
    unsigned int WEOnTime;
    unsigned int OEAADMuxOffTime;
    unsigned int OEOffTime;
    unsigned int OEExtDelayFlag;
    unsigned int OEAADMuxOnTime;
    unsigned int OEOnTime;

    unsigned int rdCycleTime;
    unsigned int wrCycleTime;
    unsigned int rdAccessTime;
    unsigned int pageBurstAccessTime;

    unsigned int cycle2CycleDelay;
    unsigned int cycle2CycleDelaySameCSCfg;
    unsigned int cycle2CycleDelayDiffCSCfg;
    unsigned int busTAtime;

    unsigned int wrAccessTime;
    unsigned int wrDataOnADMux;

} NandTimingInfo_t;

/* A consolidated structure which is the main object instantiated by the user.
** This contains all the other information for a NAND device/controller
** transaction. It contains the info like --
**      1)NAND Device information that is connected.
**      2)NAND Controller information that is being used.
**      3)Function pointers for control/config/transfer.
**
*/
typedef struct _NAND_INFO_
{
    /* Array of memory controller chip selects in use */
    int chipSelects[NAND_MAX_CHIP_SELECTS];

    /* ECC algorithm required by the NAND device */
    NandEccAlgo_t eccType;

    /* Count of chip selects the nand device uses */
    int chipSelectCnt;
    /* NAND die cnt - how many die in package */
    int dieCnt;
    /* Bus width of the device. i,e 8 bit or 16 bit */
    NandBusWidth_t busWidth;
    /* Page size of the device */
    NandPageSize_t pageSize;
    /* Blk size (with out spare area) of the device */
    NandBlockSize_t blkSize;
    /* Pages per block */
    unsigned int pagesPerBlk;

    /* Pointer to Memory Controller Structure */
    struct _NAND_CTRL_INFO_ *hNandCtrlInfo;
    /* Pointer to ECC Structure */
    struct _NAND_ECC_INFO_ *hNandEccInfo;

} NandInfo_t;

/* Contains the controller information like ---
**      1) chip select
**      2) Location for data, command and address registers
**      3) ECC supported by the controller and the default ecc to use.
**      4) Wait pin onformation
**      5) DMA related information and so on
*/
typedef struct _NAND_CTRL_INFO_
{
    /* Timing info for the device and the controller */
    void *hNandTimingInfo;
    /* Base address of the controller */
    gpmcHandle hGpmc;
    /* Wait pin where NAND dev R/B pin is connected  */
    unsigned int waitPin;
    /* Wait pin polarity  */
    unsigned int waitPinPol;
    /* Write protect pin polarity  */
    unsigned int wpPinPol;
    /* Chip select base address  */
    unsigned int chipSelectBaseAddr[NAND_MAX_CHIP_SELECTS];
    /* Chip select region size  */
    unsigned int chipSelectRegionSize[NAND_MAX_CHIP_SELECTS];
    /* Curr chip select in use by the memory controller */
    int currChipSelect;

} NandCtrlInfo_t;

typedef struct _NAND_ECC_INFO_
{
    /* Base address of the ECC engine (ELM in GPMC for BCH ECC) */
    elmHandle hElm;
    /* Offset of the page from where ECC has to store.*/
    unsigned int eccOffSet;
    /* Total number of ecc bytes. */
    unsigned int eccByteCnt;

} NandEccInfo_t;


/*******************************************************************************
*                           FUNCTION PROTOTYPE DECLARATION
*******************************************************************************/

/**
* \brief  Function to get the wait pin status.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return Wait pin status.\n
*
*         0 : If the status is active low.\n
*         1 : If the status is active high.\n
*
*/
Uint32 nandWaitPinStatusGet(NandInfo_t *nandInfo);

/**
* \brief  Function to get the GPMC FIFO status.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return GPMC FIFO buffer status.\n
*
*         0 : If the FIFO is full.\n
*         1 : If the FIFO is empty and ready to accept data.\n
*
*/
Uint32 nandWriteBufReady(NandInfo_t *nandInfo);

/**
* \brief  Function to initialize the NAND controller.\n
*
* \param  nandCtrlInfo  : Pointer to structure containing controller info.\n
*
* \return
*
*        NAND_STATUS_PASSED          : On success.\n
*        NAND_STATUS_FAILED          : On failure.\n
*
*/
NandStatus_t nandCtrlInit(NandInfo_t *nandInfo);

/**
* \brief This function does the ECC related initializes to the NAND controller
*        depending on the ecc type.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return
*        NAND_STATUS_PASSED : On success.\n
*        NAND_STATUS_FAILED : On failure.\n
*
*/
NandStatus_t nandECCInit(NandInfo_t *nandInfo);

/**
* \brief This function enables the ECC.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
void nandECCEnable(NandInfo_t *nandInfo);

/**
* \brief This function disables the ECC.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
void nandECCDisable(NandInfo_t *nandInfo);

/**
* \brief  This Function does the ECC setting for write.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
void nandECCWriteSet(NandInfo_t *nandInfo);

/**
* \brief  This Function does the ECC setting for read.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \return none.\n
*
*/
void nandECCReadSet(NandInfo_t *nandInfo);

/**
* \brief This function reads the ecc data.\n
*
* \param  nandInfo      : Pointer to structure containing controller and
*                         device information.\n
*
* \param  ptrEccData    : Pointer where read ECC data has to store.\n
*
* \return none.\n
*
*/
void nandECCCalculate(NandInfo_t *nandInfo, Uint8 *ptrEccData);

/**
* \brief This function checks and corrects ECC errors.\n
*
* \param   nandInfo     : Pointer to structure containing controller and
*                         device information.\n
*
* \param   eccRead      : Pointer to the ECC data which is read from the spare
*                         area.\n
*
* \param   data         : Pointer to the data, where if an ecc error need to
*                         correct.\n
*
* \return ECC correction Status.\n
*    NAND_STATUS_PASSED                        : If no ecc errors.\n
*    NAND_STATUS_READ_ECC_ERROR_CORRECTED      : If error are corrected.\n
*    NAND_STATUS_READ_ECC_UNCORRECTABLE_ERROR  : If errors are uncorrectable.\n
*
*/
NandStatus_t nandECCCheckAndCorrect(NandInfo_t *nandInfo,
                                    Uint8 *eccRead,
                                    Uint8 *data);

#ifdef __cplusplus
}
#endif

#endif  // _EVMC66X_NAND_GPMC_H_
