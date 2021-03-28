/**
 *  \file   nand_lib.c
 *
 *  \brief  This file contains the NAND protocol abstraction layer
 *          macro definitions and function definitions.
 *
 */

/**
 *  \copyright Copyright (C) 2013 Texas Instruments Incorporated -
 *             http://www.ti.com/
 */

/*
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

/* ========================================================================== */
/*                           Include files                                    */
/* ========================================================================== */
#include "types.h"
#include "nand_lib.h"
#include "nand_lib_gpmc.h"
#include "console_utils.h"
#include "delay_utils.h"

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */

/** \brief Macro defining the maxmimum number of devices that can be interfaced
           by the library. */
#define NAND_LIB_MAX_DEVICE                               (4U)

/** \brief Macro defining the timeout value to be used for the NAND Library. */
#define NAND_LIB_TIMEOUT_VAL                             (0xFFFFU)

/** @{ */
/** \name Macros defining the basic commands for NAND flash devices.  */

/** \brief  Macro defining the Flash Read command for NAND device. */
#define NAND_LIB_FLASH_CMD_READ                           (0x00U)
/** \brief  Macro defining the Flash Read Cycle2 command for NAND device. */
#define NAND_LIB_FLASH_CMD_READ_CYC2                      (0x30U)
/** \brief  Macro defining the Flash ReadId command for NAND device. */
#define NAND_LIB_FLASH_CMD_READID                         (0x90U)
/** \brief  Macro defining the Flash Reset command for NAND device. */
#define NAND_LIB_FLASH_CMD_RESET                          (0xFFU)
/** \brief  Macro defining the Flash Command Program command for NAND device. */
#define NAND_LIB_FLASH_CMD_PROGRAM                        (0x80U)
/** \brief  Macro defining the Flash Command Program Cycle2 command for NAND
            device. */
#define NAND_LIB_FLASH_CMD_PROGRAM_CYC2                   (0x10U)
/** \brief  Macro defining the Flash Erase Command for NAND device. */
#define NAND_LIB_FLASH_CMD_ERASE                          (0x60U)
/** \brief  Macro defining the Flash Erase Cycle2 command for NAND device. */
#define NAND_LIB_FLASH_CMD_ERASE_CYC2                     (0xD0U)
/** \brief  Macro defining the Flash Status command for NAND device. */
#define NAND_LIB_FLASH_CMD_READ_STATUS                    (0x70U)
/** \brief  Macro defining the Flash Read Random command for NAND device. */
#define NAND_LIB_FLASH_CMD_READ_RANDOM                    (0x05U)
/** \brief  Macro defining the Flash Read Random Cycle2 command for NAND
            device. */
#define NAND_LIB_FLASH_CMD_READ_RANDOM_CYC2               (0xE0U)
/** \brief  Macro defining the Flash Input Random Read command for NAND
            device. */
#define NAND_LIB_FLASH_CMD_INPUT_RANDOM                   (0x85U)
/** \brief  Macro defining the Flash Read Cache command for NAND device. */
#define NAND_LIB_FLASH_CMD_READ_CACHE                     (0x31U)
/** \brief  Macro defining the Flash Read Cache Last command for NAND device. */
#define NAND_LIB_FLASH_CMD_READ_CACHE_LAST                (0x3FU)
/** @{ */

/** \brief Macro to define the Read DMA transfer */
#define NAND_LIB_DMA_READ                                 (0U)

/** \brief Macro to define the Read DMA transfer */
#define NAND_LIB_DMA_WRITE                                (1U)

/** \brief Macro to specify the number of bytes per transaction. */
#define NAND_LIB_BYTES_PER_XFER                           (512U)

/** \name Macro specifying the Bad Block Markers  */

/** @{ */
/** \brief Macro to specify the Block as good. */
#define NAND_LIB_BLK_GOOD_MARK                            (0xFFU)

/** \brief Macro to specify the Block as bad. */
#define NAND_LIB_BLK_BAD_MARK                             (0x0U)
/** @} */

/** \name NAND command status mask  definitions.  */

/** @{ */
/** \brief  NAND Library Status Command Pass/Failure Mask. */
#define NAND_LIB_CMD_STATUS_FAIL_MASK                     (0x01)

/** \brief  NAND Library Status Command Device Ready Mask. */
#define NAND_LIB_CMD_STATUS_DEVREADY_MASK                 (0x20)

/** \brief  NAND Library Status Command Write Protected Mask. */
#define NAND_LIB_CMD_STATUS_WRPROTECT_MASK                (0x80)
/** @} */

/* ========================================================================== */
/*                            Structures and Enums                            */
/* ========================================================================== */

/** \brief Structure defining the NAND device object holding information like
           Device specific data, Memory Controller information. */
typedef struct nandLibObj
{
    uint32_t            pageSize;
    /**< Size of the Page in Bytes. */
    uint32_t            blockSize;
    /**< Size of the Block in bytes(without spare area). */
    uint32_t            pagesPerBlk;
    /**< The number of Pages per block. */
    uint32_t            dataBytesPerPage;
    /**< The number of data bytes per Page. */
    uint32_t            spareBytesPerPage;
    /**< The number of spare bytes per Page. */
    uint32_t            eccOffset;
    /**< Offset of the page where the ECC info is to be stored. */
    uint32_t            eccByteCount;
    /**< Total number of ECC bytes. */
    int32_t (*pFnCtrlInit)(nandLibInfo_t *pNandLibInfo);
    /**< Function to initialize the memory controller to access the NAND. */
    uint32_t (*pFnWaitPinStatus)(nandLibInfo_t *pNandLibInfo);
    /**< Function to get the Waitpin status. */
    uint32_t (*pFnFifoStatus)(nandLibInfo_t *pNandLibInfo);
    /**< Function to get the Fifo Status. */
    uint32_t  (*pFnGetData)(nandLibInfo_t *pNandLibInfo);
    /**< Function to get the data from NAND. */
    void (*pFnSetData)(nandLibInfo_t *pNandLibInfo, uint32_t data);
    /**< Function to set the data to the NAND. */
    void (*pFnSetCommand)(nandLibInfo_t *pNandLibInfo, uint32_t command);
    /**<Function to set the command to the NAND device. */
    void (*pFnSetAddress)(nandLibInfo_t *pNandLibInfo, uint32_t addr);
    /**<Function to set the address to the NAND device. */
    int32_t (*pFnEccInit)(nandLibInfo_t *pNandLibInfo);
    /**< Function to initialize the controller for ECC scheme. */
    void (*pFnEccEnable)(nandLibInfo_t *pNandLibInfo);
    /**< Function to enable the ECC scheme. */
    void (*pFnEccDisable)(nandLibInfo_t *pNandLibInfo);
    /**< Function to disable the ECC scheme. */
    void (*pFnEccWriteSet)(nandLibInfo_t *pNandLibInfo);
    /**< Function to set the ECC for Write Operation. */
    void (*pFnEccReadSet)(nandLibInfo_t *pNandLibInfo);
    /**< Function to Set the ECC for Read operation. */
    void (*pFnEccCalculate)(nandLibInfo_t *pNandLibInfo, uint8_t *pEccData);
    /**< Function to Calculate the ECC. */
    int32_t (*pFnEccCorrect)(nandLibInfo_t *pNandLibInfo,
        uint8_t *eccRead,
        uint8_t *data);
    /**< Function to correct the ECC errors found during a Page Read/Write
         Operation. */
}nandLibObj_t;

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */

/** \brief NAND Library Object array for maximum number of devices that can be
           interfaced. */
static nandLibObj_t gNandLibObj[NAND_LIB_MAX_DEVICE];

/* ========================================================================== */
/*                          Function Declarations                             */
/* ========================================================================== */

/**
 * \brief     Delay function for NAND Library interface.
 *
 * \details   This function provides a delay functionality for the NAND device
 *            interface module. The parameter specified as delay is not related
 *            to any time. It is just a count to execute a dummy loop.
 *
 * \param  delay   Number of cycles in the delay loop.
 */
static void NandLibDelay(uint32_t delay);

/**
 *  \brief    This Function issues the NAND command to the command register of
 *            the associated memory controller.
 *
 *  \param    pNandLibInfo   Pointer to the structure containing NAND device
 *                           controller and flash device Info.
 *  \param    command        Command to be issued for the NAND device.
 *
 */
static void NandLibSetCommand(nandLibInfo_t *pNandLibInfo, uint32_t command);

/**
 *  \brief    This Function sets the address for which the Read/Write operation
 *            of the device is to be carried out.
 *
 *  \param    pNandLibInfo   Pointer to the structure containing NAND device
 *                           controller and flash device Info.
 *  \param    addr           Address to be written for the NAND device.
 *
 */
static void NandLibSetAddr(nandLibInfo_t *pNandLibInfo, uint32_t addr);

/**
 *  \brief    This function writes the required number of bytes as specified
 *            into the data register.
 *
 *  \param    pNandLibInfo   Pointer to the structure containing NAND device
 *                           controller and flash device Info.
 *  \param    pTxData        Pointer to the data to be written to the data
 *                           register.
 *  \param    size           The size of the data in bytes to be written.
 */
static void NandLibWriteData(nandLibInfo_t *pNandLibInfo,
                             uint8_t *pTxData,
                             uint32_t size);

/**
 *  \brief    This function reads the required number of bytes as specified
 *            from the data register.
 *
 *  \param    pNandLibInfo   Pointer to the structure containing NAND device
 *                           controller and flash device Info.
 *  \param    pRxData        Pointer to the data buffer where the read data is
 *                           to be stored.
 *  \param    size           The size of the data to be read.
 */
static void NandLibReadData(nandLibInfo_t *pNandLibInfo,
                            volatile uint8_t *pRxData,
                            uint32_t size);

/**
 *  \brief    This Function monitors the Ready/Busy pin of the NAND device and
 *            waits until the timeout period for the pin to toggle to the device
 *            ready state.
 *
 *  \param    pNandLibInfo   Pointer to the #nandLibInfo_t structure containing
 *                           the flash device and controller information.
 *  \param    time           The timeout period till which the status is to be
 *                           monitored.
 *
 *  \retval   NAND_LIB_PASS    If the device is ready within the specified time
 *  \retval   NAND_LIB_TIMEOUT If a timeout occurs before the pin toggles to device
 *                             Ready state.
 */
static int32_t NandLibWaitPinStatus(nandLibInfo_t *pNandInfo, uint32_t time);

/**
 *  \brief    This Function returns the device status after issuing the STATUS
 *            command.
 *
 *  \param    pNandLibInfo   Pointer to the structure containing NAND device
 *                           controller and flash device Info.
 *
 *  \retval   NAND_LIB_PASS         If the previous issued command passed.
 *  \retval   NAND_LIB_FAIL         If the previous issued command failed.
 *  \retval   NAND_LIB_DEV_BUSY If the device is busy.
 *  \retval   NAND_LIB_DEV_PROTECTED  If the device is write protected.
 */
static int32_t NandLibDeviceStatus(nandLibInfo_t *pNandLibInfo);

/**
 *  \brief      Function to start the page write command sequence.
 *
 *  \details    This function forms the address, based on  the block, page and
 *              column. Then the command for Page write is sent along with the
 *              address.
 *
 *  \param      pNandLibInfo   Pointer to the structure containing NAND device
 *                             controller and flash device Info.
 *  \param      blockNum       The Block number of the device.
 *  \param      pageNum        The Page Number of the device.
 *  \param      columnAddr     Column Address of the device.
 */
static void NandLibStartPageWriteCmd(nandLibInfo_t *pNandLibInfo,
                                     uint32_t blockNum,
                                     uint32_t pageNum,
                                     uint32_t columnAddr);

/**
 *  \brief      Function to end the page write command sequence.
 *
 *  \details    This function forms the address, based on  the block, page and
 *              column. Then the command for ending the Page Write sequence is
 *              sent along with the address.
 *
 *  \param      pNandLibInfo   Pointer to the structure containing NAND device
 *                             controller and flash device Info.
 *  \param      blockNum       The Block number of the device.
 *  \param      pageNum        The Page Number of the device.
 *  \param      columnAddr      Column Address of the device.
 *
 *  \retval     NAND_LIB_PASS         If the write command passed.
 *  \retval     NAND_LIB_TIMEOUT      If a timeout error occurs.
 */
static int32_t NandLibEndPageWriteCmd(nandLibInfo_t *pNandLibInfo);

/**
 *  \brief      Function to start the page read command sequence.
 *
 *  \details    This function forms the address, based on  the block, page and
 *              column. Then the command for Page Read sequence is sent along
 *              with the address.
 *
 *  \param      pNandLibInfo   Pointer to the structure containing NAND device
 *                             controller and flash device Info.
 *  \param      blockNum       The Block number of the device.
 *  \param      pageNum        The Page Number of the device.
 *  \param      columnAddr     Column Address of the device.
 *
 *  \retval   NAND_LIB_PASS         If the write command passed.
 *  \retval   NAND_LIB_FAIL         If the write command failed.
 *  \retval   NAND_LIB_TIMEOUT      If a timeout error occurs.
 *  \retval   NAND_LIB_DEV_BUSY     If the device is busy.
 *  \retval   NAND_LIB_DEV_PROTECTED  If the device is write protected.
 */
static int32_t NandLibSendPageReadCmd(nandLibInfo_t *pNandLibInfo,
                                      uint32_t blockNum,
                                      uint32_t pageNum,
                                      uint32_t columnAddr);


/* ========================================================================== */
/*                           Function Definitions                             */
/* ========================================================================== */

int32_t NANDLibInit(nandLibInfo_t *pNandLibInfo)
{
    int32_t status = NAND_LIB_PASS;
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;

    if(NAND_LIB_MEM_CTRLR_GPMC == pNandLibInfo->nandLibCtrlInfo.memCtrlr)
    {
        /* Initialize the set of function pointers. */
        gNandLibObj[chipSel].pFnCtrlInit = NANDLibGpmcInit;
        gNandLibObj[chipSel].pFnWaitPinStatus = NANDLibGpmcWaitPinStatus;
        gNandLibObj[chipSel].pFnFifoStatus = NANDLibGpmcFifoStatus;
        gNandLibObj[chipSel].pFnSetCommand = NANDLibGpmcSetCommand;
        gNandLibObj[chipSel].pFnGetData = NANDLibGpmcGetData;
        gNandLibObj[chipSel].pFnSetData = NANDLibGpmcSetData;
        gNandLibObj[chipSel].pFnSetAddress = NANDLibGpmcSetAddr;
        gNandLibObj[chipSel].pFnEccInit = NANDLibGpmcEccInit;
        gNandLibObj[chipSel].pFnEccEnable = NANDLibGpmcEccEnable;
        gNandLibObj[chipSel].pFnEccDisable = NANDLibGpmcEccDisable;
        gNandLibObj[chipSel].pFnEccWriteSet = NANDLibGpmcEccWriteSet;
        gNandLibObj[chipSel].pFnEccReadSet = NANDLibGpmcEccReadSet;
        gNandLibObj[chipSel].pFnEccCalculate = NANDLibGpmcEccCalculate;
        gNandLibObj[chipSel].pFnEccCorrect = NANDLibGpmcEccCheckAndCorrect;
    }

    if(NAND_LIB_PASS == status)
    {
        /* Initialize the Memory Controller to interface with the NAND device.*/
        status = gNandLibObj[chipSel].pFnCtrlInit(pNandLibInfo);

        if(NAND_LIB_PASS == status)
        {
            status = NANDLibReset(pNandLibInfo);

            status = NANDLibReadId(pNandLibInfo);
            {
                if(NAND_LIB_PASS == status)
                {
                    if(NAND_LIB_ECC_ALGO_BCH_8BIT ==
                        pNandLibInfo->nandLibCtrlInfo.eccAlgo)
                    {
                        gNandLibObj[chipSel].eccOffset =
                            gNandLibObj[chipSel].pageSize +
                            NAND_LIB_ECC_BCH_8BIT_OOB_OFFSET;
                            gNandLibObj[chipSel].eccByteCount =
                            NAND_LIB_ECC_BCH_8BIT_BYTECNT;
                    }
                    else if(NAND_LIB_ECC_ALGO_HAMMING_1BIT ==
                        pNandLibInfo->nandLibCtrlInfo.eccAlgo)
                    {
                        gNandLibObj[chipSel].eccOffset =
                            gNandLibObj[chipSel].pageSize +
                            NAND_LIB_ECC_1BIT_HAMMINGCODE_OOB_OFFSET;
                            gNandLibObj[chipSel].eccByteCount =
                            NAND_LIB_ECC_1BIT_HAMMINGCODE_BYTECNT;
                    }
                    else
                    {
                        status = NAND_LIB_INVALID_PARAM;
                    }
                }
            }
        }
    }

    return status;
}

int32_t NANDLibReadId(nandLibInfo_t *pNandLibInfo)
{
    int32_t status = NAND_LIB_PASS;
    uint32_t count = 0U;
    uint8_t  devId[4] = {0, 0, 0, 0};
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;

    NandLibSetCommand(pNandLibInfo, NAND_LIB_FLASH_CMD_READID);

    NandLibSetAddr(pNandLibInfo, 0x00U);

    NandLibDelay(1U);

    /* Check the Wait Pin Status. */
    status = NandLibWaitPinStatus(pNandLibInfo, NAND_LIB_TIMEOUT_VAL);

    if(NAND_LIB_PASS == status)
    {
        for(count = 0U; count < 4U; count++)
        {
            NandLibReadData(pNandLibInfo, &devId[count], 1U);
        }

        pNandLibInfo->nandLibFlashInfo.flashMfgId = devId[0];
        pNandLibInfo->nandLibFlashInfo.flashDevId = devId[1];
        gNandLibObj[chipSel].pageSize = (1024 << (devId[3] & 0x03));
        gNandLibObj[chipSel].blockSize =
            ((64 << (devId[3] >> 4 & 0x03)) * 1024);
        gNandLibObj[chipSel].dataBytesPerPage =  1024 << (devId[3] &0x3);
        gNandLibObj[chipSel].spareBytesPerPage =  32 << ((devId[3] &0xF) >> 2);
        gNandLibObj[chipSel].pagesPerBlk =
            (gNandLibObj[chipSel].blockSize /
            gNandLibObj[chipSel].dataBytesPerPage);

        if((devId[3] >> 6) & 0x1)
        {
            pNandLibInfo->nandLibFlashInfo.busWidth = NAND_LIB_BUS_WIDTH_16BIT;
        }
        else
        {
            pNandLibInfo->nandLibFlashInfo.busWidth = NAND_LIB_BUS_WIDTH_8BIT;
        }
    }

    CONSOLEUtilsPrintf("\r\n**** Nand Device Info ****\r\n");
    CONSOLEUtilsPrintf("Manufacturer Id is %x \r\n",
        pNandLibInfo->nandLibFlashInfo.flashMfgId);
    CONSOLEUtilsPrintf("Device Id is       %x \r\n",
        pNandLibInfo->nandLibFlashInfo.flashDevId);
    CONSOLEUtilsPrintf("Page size is       %d bytes\r\n",
        gNandLibObj[chipSel].pageSize);
    CONSOLEUtilsPrintf("Block Size is      %d bytes\r\n",
        gNandLibObj[chipSel].blockSize);
    CONSOLEUtilsPrintf("Pages per Block is %d\r\n",
        gNandLibObj[chipSel].pagesPerBlk);
    CONSOLEUtilsPrintf("*************************\r\n");

    return status;
}

int32_t NandLibWaitPinStatus(nandLibInfo_t *pNandLibInfo, uint32_t timeout)
{
    uint32_t status = NAND_LIB_PASS;
    uint32_t waitPinStatus = 0U;
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;

    /*
    ** This function is called immediatly after issuing commands
    ** to the NAND flash. Since the NAND flash takes sometime to
    ** pull the R/B line low,it would be safe to introduce a delay
    ** before checking the ready/busy status.
    */
    NandLibDelay(1U);

    while(timeout > 0U)
    {
        /* Check the Ready/Busy status. */
        waitPinStatus = gNandLibObj[chipSel].pFnWaitPinStatus(pNandLibInfo);

        if(waitPinStatus != 0U)
        {
            break;
        }
        timeout--;
    }

    if(0U == timeout)
    {
        status = NAND_LIB_TIMEOUT;
    }

    return status;
}

int32_t NANDLibReset(nandLibInfo_t *pNandLibInfo)
{
    int32_t status = NAND_LIB_PASS;
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;

    gNandLibObj[chipSel].pFnSetCommand(pNandLibInfo, NAND_LIB_FLASH_CMD_RESET);

    status = NandLibWaitPinStatus(pNandLibInfo, NAND_LIB_TIMEOUT_VAL);

    return status;
}

int32_t NANDLibPageRead(nandLibInfo_t *pNandLibInfo,
                        uint32_t blockNum,
                        uint32_t pageNum,
                        uint8_t *pRxData)
{
    int32_t status = NAND_LIB_PASS;
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;
    uint32_t columnAddr = 0U;
    uint8_t eccData[256];
    uint32_t xferCount = 0U;
    uint8_t *pEccData = eccData;
    uint32_t eccCorFlag = 0U;

    /* Disable the ECC engine. */
    gNandLibObj[chipSel].pFnEccDisable(pNandLibInfo);

    status = NandLibSendPageReadCmd(pNandLibInfo, blockNum, pageNum, columnAddr);

    if(NAND_LIB_PASS == status)
    {
        if(NAND_LIB_ECC_ALGO_NONE != pNandLibInfo->nandLibCtrlInfo.eccAlgo)
        {
            gNandLibObj[chipSel].pFnEccReadSet(pNandLibInfo);
            gNandLibObj[chipSel].pFnEccDisable(pNandLibInfo);
        }

        for(xferCount = 0; xferCount < ((gNandLibObj[chipSel].pageSize)/
            NAND_LIB_BYTES_PER_XFER); xferCount++)
        {
            if(NAND_LIB_ECC_ALGO_NONE != pNandLibInfo->nandLibCtrlInfo.eccAlgo)
            {
                gNandLibObj[chipSel].pFnEccEnable(pNandLibInfo);
            }
            /* Read the Sub-Page from the data area. */
            if(NAND_LIB_XFER_MODE_POLLING ==
                pNandLibInfo->nandLibCtrlInfo.xferMode)
            {
                NandLibReadData(pNandLibInfo, pRxData, NAND_LIB_BYTES_PER_XFER);
            }
            else if(NAND_LIB_XFER_MODE_DMA ==
                pNandLibInfo->nandLibCtrlInfo.xferMode)
            {
                 status = NAND_LIB_MODE_NOT_SUPP;
            }
            else if(NAND_LIB_XFER_MODE_INTR ==
                pNandLibInfo->nandLibCtrlInfo.xferMode)
            {
                status = NAND_LIB_MODE_NOT_SUPP;
            }
            else
            {
                status = NAND_LIB_INVALID_PARAM;
            }

            if(NAND_LIB_ECC_ALGO_NONE != pNandLibInfo->nandLibCtrlInfo.eccAlgo)
            {
                if(NAND_LIB_ECC_ALGO_BCH_8BIT ==
                    pNandLibInfo->nandLibCtrlInfo.eccAlgo)
                {
                    /* Read the ECC data, as BCH algorithm requires this for
                       syndrome calculation. */
                    columnAddr = (gNandLibObj[chipSel].eccOffset) +
                         (xferCount * gNandLibObj[chipSel].eccByteCount);
                    if(pNandLibInfo->nandLibFlashInfo.busWidth ==
                        NAND_LIB_BUS_WIDTH_16BIT)
                    {
                        columnAddr = columnAddr/2;
                    }

                    NandLibSetCommand(pNandLibInfo,
                        NAND_LIB_FLASH_CMD_READ_RANDOM);

                    NandLibSetAddr(pNandLibInfo, (uint8_t) (columnAddr & 0xFF));

                    NandLibSetAddr(pNandLibInfo,
                        (uint8_t) ((columnAddr >> 8) & 0xFF));

                    NandLibSetCommand(pNandLibInfo,
                        NAND_LIB_FLASH_CMD_READ_RANDOM_CYC2);

                    status = NandLibWaitPinStatus(pNandLibInfo,
                            NAND_LIB_TIMEOUT_VAL);
               }
                if(NAND_LIB_PASS == status)
                {
                    /* Read ECC data from the Spare area. */
                    NandLibReadData(pNandLibInfo, pEccData,
                            gNandLibObj[chipSel].eccByteCount - 1);
                    status = gNandLibObj[chipSel].pFnEccCorrect(pNandLibInfo,
                        pEccData, pRxData);
                    gNandLibObj[chipSel].pFnEccDisable(pNandLibInfo);

                    if(status & NAND_LIB_ECC_ERR_CORRECTED)
                    {
                        eccCorFlag = 1U;
                    }
                    else if(status & NAND_LIB_ECC_UNCORRECTABLE)
                    {
                        break;
                    }
                    else
                    {

                    }
                }
                if(NAND_LIB_ECC_ALGO_BCH_8BIT ==
                    pNandLibInfo->nandLibCtrlInfo.eccAlgo)
                {
                    /* Reset the column pointer to appropriate position.  */
                    columnAddr = ((xferCount + 1) * (NAND_LIB_BYTES_PER_XFER));
                    if(pNandLibInfo->nandLibFlashInfo.busWidth ==
                        NAND_LIB_BUS_WIDTH_16BIT)
                    {
                        columnAddr = columnAddr/2;
                    }
                    if(xferCount != (((gNandLibObj[chipSel].pageSize)/
                        NAND_LIB_BYTES_PER_XFER) - 1))
                    {
                        NandLibSetCommand(pNandLibInfo,
                            NAND_LIB_FLASH_CMD_READ_RANDOM);
                        NandLibSetAddr(pNandLibInfo,
                            (uint8_t) (columnAddr & 0xFF));

                        NandLibSetAddr(pNandLibInfo,
                            (uint8_t) ((columnAddr >> 8) & 0xFF));

                        NandLibSetCommand(pNandLibInfo,
                            NAND_LIB_FLASH_CMD_READ_RANDOM_CYC2);

                        status = NandLibWaitPinStatus(pNandLibInfo,
                            NAND_LIB_TIMEOUT_VAL);
                    }
                }
                pEccData += gNandLibObj[chipSel].eccByteCount;
            }
            pRxData += NAND_LIB_BYTES_PER_XFER;
        }
        if(eccCorFlag && (!(status & NAND_LIB_ECC_UNCORRECTABLE)))
        {
            status = NAND_LIB_ECC_ERR_CORRECTED;
        }
    }
    return status;
}

int32_t NANDLibPageWrite(nandLibInfo_t *pNandLibInfo,
                         uint32_t blockNum,
                         uint32_t pageNum,
                         uint8_t *pTxData)
{
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;
    int32_t status = NAND_LIB_PASS;
    uint32_t columnAddr = 0U;
    uint8_t eccData[256];
    uint8_t *pEccData = eccData;
    uint32_t xferCount = 0U;
    uint32_t pageSize = gNandLibObj[chipSel].pageSize;

    NandLibStartPageWriteCmd(pNandLibInfo, blockNum, pageNum, columnAddr);

    if(NAND_LIB_ECC_ALGO_NONE != pNandLibInfo->nandLibCtrlInfo.eccAlgo)
    {
        gNandLibObj[chipSel].pFnEccWriteSet(pNandLibInfo);
        gNandLibObj[chipSel].pFnEccDisable(pNandLibInfo);
    }
    for(xferCount = 0U; xferCount < (pageSize/NAND_LIB_BYTES_PER_XFER);
        xferCount++)
    {
        if(NAND_LIB_ECC_ALGO_NONE != pNandLibInfo->nandLibCtrlInfo.eccAlgo)
        {
            gNandLibObj[chipSel].pFnEccEnable(pNandLibInfo);
        }

        if(NAND_LIB_XFER_MODE_POLLING == pNandLibInfo->nandLibCtrlInfo.xferMode)
        {
            NandLibWriteData(pNandLibInfo, pTxData, NAND_LIB_BYTES_PER_XFER);
        }
        else if(NAND_LIB_XFER_MODE_DMA == pNandLibInfo->nandLibCtrlInfo.xferMode)
        {
             status = NAND_LIB_MODE_NOT_SUPP;
        }
        else if(NAND_LIB_XFER_MODE_INTR ==
            pNandLibInfo->nandLibCtrlInfo.xferMode)
        {
            status = NAND_LIB_MODE_NOT_SUPP;
        }
        else
        {
            status = NAND_LIB_INVALID_PARAM;
        }
        if(NAND_LIB_ECC_ALGO_NONE != pNandLibInfo->nandLibCtrlInfo.eccAlgo)
        {
            gNandLibObj[chipSel].pFnEccDisable(pNandLibInfo);
            gNandLibObj[chipSel].pFnEccCalculate(pNandLibInfo, pEccData);
            pEccData += gNandLibObj[chipSel].eccByteCount;
        }
        pTxData += NAND_LIB_BYTES_PER_XFER;
    }
    if(NAND_LIB_PASS == status)
    {
        if(NAND_LIB_ECC_ALGO_NONE != pNandLibInfo->nandLibCtrlInfo.eccAlgo)
        {
            if(status == NAND_LIB_PASS)
            {
                columnAddr = gNandLibObj[chipSel].eccOffset;
                if(pNandLibInfo->nandLibFlashInfo.busWidth ==
                    NAND_LIB_BUS_WIDTH_16BIT)
                {
                    columnAddr = columnAddr/2;
                }
                NandLibSetCommand(pNandLibInfo,
                    NAND_LIB_FLASH_CMD_INPUT_RANDOM);
                /* Write 2 bytes of column address. */
                NandLibSetAddr(pNandLibInfo, (uint8_t) (columnAddr & 0xFF));

                NandLibSetAddr(pNandLibInfo,
                    (uint8_t)((columnAddr >> 8) & 0xFF));

                NandLibWriteData(pNandLibInfo, &eccData[0],
                    ((gNandLibObj[chipSel].eccByteCount) *
                    (pageSize/NAND_LIB_BYTES_PER_XFER)));
            }
        }
        status = NandLibEndPageWriteCmd(pNandLibInfo);
    }

    return status;
}

int32_t NANDLibBlockErase(nandLibInfo_t *pNandLibInfo, uint32_t blockNum)
{
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;
    uint32_t firstPageAddr = 0U;
    uint32_t count = 0U;
    int32_t status = NAND_LIB_PASS;

    NandLibSetCommand(pNandLibInfo, NAND_LIB_FLASH_CMD_ERASE);

    /* Calculate linear page number of the first page of the block. */
    firstPageAddr = (blockNum * gNandLibObj[chipSel].pagesPerBlk);
    /* Write the Row address. */
    for(count = 0; count < 3; count++)
    {
        NandLibSetAddr(pNandLibInfo, (uint8_t) firstPageAddr);
        firstPageAddr = firstPageAddr >> 8U;
    }

    NandLibSetCommand(pNandLibInfo, NAND_LIB_FLASH_CMD_ERASE_CYC2);

    status = NandLibWaitPinStatus(pNandLibInfo, NAND_LIB_TIMEOUT_VAL);
    if(NAND_LIB_TIMEOUT != status)
    {
        status = NandLibDeviceStatus(pNandLibInfo);
    }

    return status;
}

int32_t NANDLibBadBlockCheck(nandLibInfo_t *pNandLibInfo, uint32_t blockNum)
{
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;
    int32_t status = NAND_LIB_BLOCK_GOOD;
    uint8_t badBlkMark[2];
    uint32_t columnAddr = gNandLibObj[chipSel].pageSize;
    uint32_t pageNum = 0U;

    /* Adjust column address for 16 bit address. */
    if(NAND_LIB_BUS_WIDTH_16BIT == pNandLibInfo->nandLibFlashInfo.busWidth)
    {
        columnAddr = columnAddr/2;
    }

    /* Read the spare area of 1st, 2nd and last page of the block. */
    for(pageNum = 0; pageNum < 3; pageNum++)
    {
        if(2U == pageNum)
        {
            pageNum = (gNandLibObj[chipSel].pagesPerBlk - 1U);
        }

        if(NAND_LIB_TIMEOUT == NandLibSendPageReadCmd(pNandLibInfo, blockNum,
             pageNum, columnAddr))
        {
            status = NAND_LIB_SPARE_AREA_READ_FAIL;
            break;
        }

        /* Read the ECC Data from the spare area */
        NandLibReadData(pNandLibInfo, &badBlkMark[0], 2);

        /* Check for Bad Block Marker */
        if(badBlkMark[0] != NAND_LIB_BLK_GOOD_MARK)
        {
            status = NAND_LIB_BLOCK_BAD;
            break;
        }
    }

    return status;
}

int32_t NANDLibMarkBlockAsBad(nandLibInfo_t *pNandLibInfo, uint32_t blockNum)
{
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;
    uint32_t pageNum = 0U;
    uint32_t columnAddr = 0U;
    uint8_t badBlkMark[2];
    int32_t status = NAND_LIB_PASS;

    columnAddr = gNandLibObj[chipSel].pageSize;

    /* Adjust Column address for 16 bit devices. */
    if(pNandLibInfo->nandLibFlashInfo.busWidth == NAND_LIB_BUS_WIDTH_16BIT)
    {
        columnAddr = columnAddr/2;
    }

    /*
    ** First erase the block before marking it as bad. The result of
    ** marking this as bad can be ignored.
    */
    NANDLibBlockErase(pNandLibInfo, blockNum);

    /* Read the spare area of 1st, 2nd and last page of the block */
    for(pageNum = 0; pageNum < 3; pageNum++)
    {
        /* Last page number of the block */
        if(pageNum == 2)
        {
            pageNum = gNandLibObj[chipSel].pagesPerBlk - 1U;
        }
        badBlkMark[0] = NAND_LIB_BLK_BAD_MARK;
        NandLibStartPageWriteCmd(pNandLibInfo, blockNum, pageNum, columnAddr);
        NandLibWriteData(pNandLibInfo, badBlkMark, 2);
        status = NandLibEndPageWriteCmd(pNandLibInfo);
        if(NAND_LIB_PASS != status)
        {
            break;
        }
    }

    return status;
}

/* ========================================================================== */
/*                  Internal Function Definitions                             */
/* ========================================================================== */

static void NandLibDelay(uint32_t delay)
{
    DELAYUsec(delay);
}

static void NandLibSetCommand(nandLibInfo_t *pNandLibInfo, uint32_t command)
{
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;

    gNandLibObj[chipSel].pFnSetCommand(pNandLibInfo, command);
}

static void NandLibSetAddr(nandLibInfo_t *pNandLibInfo, uint32_t addr)
{
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;

    gNandLibObj[chipSel].pFnSetAddress(pNandLibInfo, addr);
}

static void NandLibWriteData(nandLibInfo_t *pNandLibInfo,
                             uint8_t *pTxData,
                             uint32_t size)
{
    uint32_t bufStatus = 0U;
    uint16_t *pData = (uint16_t *) pTxData;
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;

    if(pNandLibInfo->nandLibFlashInfo.busWidth == NAND_LIB_BUS_WIDTH_16BIT)
    {
        while(size > 0U)
        {
            do
            {
                /* Check the status of the buffer. */
                bufStatus = gNandLibObj[chipSel].pFnFifoStatus(pNandLibInfo);
            }while(1U != bufStatus);
            gNandLibObj[chipSel].pFnSetData(pNandLibInfo, *pData);
            pTxData++;
            size = size - 2U;
        }
    }
    else if(pNandLibInfo->nandLibFlashInfo.busWidth == NAND_LIB_BUS_WIDTH_8BIT)
    {
        while(size > 0U)
        {
            do
            {
                /* Check the status of the buffer. */
                bufStatus = gNandLibObj[chipSel].pFnFifoStatus(pNandLibInfo);
            }while(1U != bufStatus);
            gNandLibObj[chipSel].pFnSetData(pNandLibInfo, *pTxData);
            pTxData++;
            size--;
        }
    }
    else
    {

    }
}

static void NandLibReadData(nandLibInfo_t *pNandLibInfo,
                            volatile uint8_t *pRxData,
                            uint32_t size)
{
    uint16_t *pData;
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;

    if(pNandLibInfo->nandLibFlashInfo.busWidth == NAND_LIB_BUS_WIDTH_16BIT)
    {
        pData = (uint16_t *) pRxData;
        while(size > 0U)
        {
            *pData = gNandLibObj[chipSel].pFnGetData(pNandLibInfo);
            pData++;
            size = size -2;
        }
    }
    else if(pNandLibInfo->nandLibFlashInfo.busWidth == NAND_LIB_BUS_WIDTH_8BIT)
    {
        while(size > 0U)
        {
            *pRxData = gNandLibObj[chipSel].pFnGetData(pNandLibInfo);
            pRxData++;
            size--;
        }
    }
    else
    {

    }
}

static int32_t NandLibDeviceStatus(nandLibInfo_t *pNandLibInfo)
{
    int32_t status = NAND_LIB_PASS;
    uint8_t nandDevStatus = 0;

    NandLibSetCommand(pNandLibInfo, NAND_LIB_FLASH_CMD_READ_STATUS);

    NandLibDelay(10U);

    NandLibReadData(pNandLibInfo, &nandDevStatus, 1U);

    if(nandDevStatus & NAND_LIB_CMD_STATUS_FAIL_MASK)
    {
        status = NAND_LIB_FAIL;
    }
    if(!(nandDevStatus & NAND_LIB_CMD_STATUS_DEVREADY_MASK))
    {
        status = NAND_LIB_DEV_BUSY;
    }
    if(!(nandDevStatus & NAND_LIB_CMD_STATUS_WRPROTECT_MASK))
    {
        status = NAND_LIB_DEV_PROTECTED;
    }

    return status;
}

static void NandLibStartPageWriteCmd(nandLibInfo_t *pNandLibInfo,
                                        uint32_t blockNum,
                                        uint32_t pageNum,
                                        uint32_t columnAddr)
{
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;
    uint32_t pageAddr = 0U;
    uint32_t count = 0U;

    NandLibSetCommand(pNandLibInfo, NAND_LIB_FLASH_CMD_PROGRAM);
    /* Write 2 Bytes of column Address. */
    NandLibSetAddr(pNandLibInfo, (uint8_t)(columnAddr & 0xFF));

    NandLibSetAddr(pNandLibInfo, (uint8_t)((columnAddr >> 8) & 0xFF));

    pageAddr = ((blockNum * (gNandLibObj[chipSel].blockSize/
        gNandLibObj[chipSel].pageSize)) + pageNum);

    /* Write the Row Address. */
    for(count = 0; count < 3; count++)
    {
        NandLibSetAddr(pNandLibInfo, (uint8_t) pageAddr);
        pageAddr = pageAddr >> 8U;
    }
}

static int32_t NandLibEndPageWriteCmd(nandLibInfo_t *pNandLibInfo)
{
    int32_t status = NAND_LIB_PASS;

    NandLibSetCommand(pNandLibInfo, NAND_LIB_FLASH_CMD_PROGRAM_CYC2);

    status = NandLibWaitPinStatus(pNandLibInfo, NAND_LIB_TIMEOUT_VAL);
    if(NAND_LIB_TIMEOUT == status)
    {
        status = NandLibDeviceStatus(pNandLibInfo);
    }

    return status;
}

static int32_t NandLibSendPageReadCmd(nandLibInfo_t *pNandLibInfo,
                                      uint32_t blockNum,
                                      uint32_t pageNum,
                                      uint32_t columnAddr)
{
    int32_t status = NAND_LIB_PASS;
    uint32_t pageAddr = 0U;
    uint32_t chipSel = pNandLibInfo->nandLibCtrlInfo.chipSel;
    uint32_t count = 0U;

    NandLibSetCommand(pNandLibInfo, NAND_LIB_FLASH_CMD_READ);

    /* Write 2 Bytes of column address. */
    NandLibSetAddr(pNandLibInfo, (uint8_t)(columnAddr & 0xFF));

    NandLibSetAddr(pNandLibInfo, (uint8_t)((columnAddr >> 8) & 0xFF));

    pageAddr = ((blockNum *
        (gNandLibObj[chipSel].blockSize/gNandLibObj[chipSel].pageSize)) +
            pageNum);
    /* Write the row address. */
    for(count = 0; count < 3; count++)
    {
        NandLibSetAddr(pNandLibInfo, (uint8_t) pageAddr);
        pageAddr = pageAddr >> 8U;
    }

    NandLibSetCommand(pNandLibInfo, NAND_LIB_FLASH_CMD_READ_CYC2);
    status = NandLibWaitPinStatus(pNandLibInfo, NAND_LIB_TIMEOUT_VAL);

    return status;
}
