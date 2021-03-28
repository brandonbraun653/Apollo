/**
 *  \file    sbl_nand.c
 *
 *  \brief   NAND Initialization functions. And a function to copy data from
 *           NAND to the given address.
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
/*                             Include Files                                  */
/* ========================================================================== */
#include <string.h>
#include "types.h"
#include "console_utils.h"
#include "error.h"
#include "sbl_copy.h"
#include "sbl_nand.h"
#include "nand_lib.h"
#include "read_write_app.h"
#include "device.h"
#include "soc.h"
#include "board.h"
#include "pinmux.h"
#include "prcm.h"

/* ========================================================================== */
/*                           Macros & Typedefs                                */
/* ========================================================================== */

/** \brief NAND Flash instance number. */
#define NAND_FLASH_INST_NUM             (0U)

/** \brief NAND Flash device Page Size. */
#define NAND_FLASH_PAGE_SIZE            (PAGE_SIZE)

/** \brief NAND Flash device Block Size. */
#define NAND_FLASH_BLOCK_SIZE           (BLOCK_SIZE)

/** \brief NAND Flash device Pages per Block. */
#define NAND_FLASH_PAGES_PER_BLK        (64U)

/** \brief Macro defining the number of bytes sent/received per frame. */
#define NAND_BYTES_PER_TRNFS            (512U)

/** \brief Macro defining the maximum number of Ecc bytes per transfer. */
#define NAND_MAX_ECC_BYTES_PER_TRNFS    (16U)

/** \brief Macros defining the Read Write Buffer Size. */
#define NAND_ECC_BUFF_SIZE     ((NAND_FLASH_PAGE_SIZE/NAND_BYTES_PER_TRNFS) \
                                * NAND_MAX_ECC_BYTES_PER_TRNFS)

/** \brief The offet from where to read the image. */
#define IMAGE_OFFSET                    (512 * 1024)

/* ========================================================================== */
/*                 Internal Function Declarations                             */
/* ========================================================================== */

/**
 * \brief  This function copies the application image to the DDR by reading the
 *         header info.
 *
 * \param  pEntryPoint  Entry address read from TI image header.
 *
 * \retval S_PASS         Image copy successful.
 * \retval E_FAIL         Image copy failed.
 */
static uint32_t SblNandImageCopy(uint32_t *pEntryPoint);

/**
 * \brief    Reads bytes from NAND.
 *
 * \param    pNandLibInfo Pointer to the nand library structure.
 * \param    flashAddr    NAND Flash address.
 * \param    size         Indicates the total size needs to be read from flash.
 * \param    destAddr     Pointer to Destination address where data needs to be
 *                        copy.
 *
 * \retval  S_PASS     If Flash read is successful.
 * \retval  NAND_LIB_FAIL If Flash read is unsuccessful.
 * \retval  NAND_LIB_BLOCK_BAD  If the Nand Block is Bad.
 **/
static uint32_t SblNandReadFlash(nandAppObj_t *pNandLibInfo,
                                 uint32_t flashAddr,
                                 uint32_t size,
                                 uint8_t *destAddr);

/**
 * \brief  This API gets the board info like instance and chip select.
 *
 * \param  pObj      Pointer to the flash device object
 *
 * \retval  S_PASS     On Success
 * \retval  E_FAIL     On Failure
 */
static int32_t SblNandBoardInfoGet(nandAppObj_t *pObj);

/**
 * \brief   The API updates the NAND device specific parameters from the
 *          device data based on the device detected.
 *
 * \param   pNandObj   Pointer to the NAND object.
 * \param   pDevData   Pointer to the NAND device data.
 */
static void SblNandUpdateDeviceParams(nandAppObj_t *pObj,
                                      nandDeviceData_t *pDevData);

/**
 * \brief  This API gets the soc info - base address of the GPMC instance to
 *         which the NAND flash is connected.
 *
 * \param  pObj     Pointer to the flash device object.
 *
 * \retval  S_PASS     On Success
 * \retval  E_FAIL     On Failure
 */
static int32_t SblNandSocInfoGet(nandAppObj_t *pObj);

/* ========================================================================== */
/*                            Global Variables Declarations                   */
/* ========================================================================== */

/** \brief  Global structure for NAND Device Configuration parameters for
            Read/Write Operations. */
static nandAppObj_t gSblNandObj;

/** \brief Global array to store the received data. */
#if defined(__IAR_SYSTEMS_ICC__)
#pragma data_alignment=4
uint8_t gSblRxData[NAND_FLASH_PAGE_SIZE];
#else
uint8_t __attribute__ ((aligned (4))) gSblRxData[NAND_FLASH_PAGE_SIZE];
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

uint32_t SBLNandCopy(uint32_t *pEntryPoint, uint32_t instNum)
{
    int32_t status = S_PASS;
    nandDeviceData_t *pNandDeviceData;

    /* Get Board Info for NAND */
    status = SblNandBoardInfoGet(&gSblNandObj);
     if(S_PASS == status)
    {
        /* Get SOC info for GPMC to which NAND is connected. */
        status = SblNandSocInfoGet(&gSblNandObj);
        if(S_PASS == status)
        {
            status = PRCMModuleEnable(CHIPDB_MOD_ID_ELM, 0U, FALSE);

            if(S_PASS == status)
            {
                /* Clock configuration for ELM controller*/
                status = PRCMModuleEnable(CHIPDB_MOD_ID_GPMC, 0U, FALSE);

                if(S_PASS == status)
                {
                    /** PinMux for GPMC controller */
                    status = PINMUXModuleConfig(CHIPDB_MOD_ID_GPMC, 0U, NULL);
                }
                else
                {
                    CONSOLEUtilsPrintf("FAILURE!!\n GPMC Pinmux failure\n");
                }
            }
            else
            {
                CONSOLEUtilsPrintf("FAILURE!!\n GPMC Clock failed\n");
            }

            if(S_PASS == status)
            {
                pNandDeviceData = NANDGetDeviceData(gSblNandObj.nandFlashId);

                /* Update the device parameters of the connected NAND device. */
                SblNandUpdateDeviceParams(&gSblNandObj, pNandDeviceData);

                status = NANDLibInit(&gSblNandObj.nandLibInfo);

                if(NAND_LIB_PASS != status)
                {
                    CONSOLEUtilsPrintf("\nFAILURE!!\nNANDLib Init failed\n");
                }
                else
                {
                    status = SblNandImageCopy(pEntryPoint);
                }
            }
        }
    }

    return status;
}

/* -------------------------------------------------------------------------- */
/*                 Internal Function Definitions                              */
/* -------------------------------------------------------------------------- */

static uint32_t SblNandImageCopy(uint32_t *pEntryPoint)
{
    ti_header imageHdr;
    int32_t status = S_PASS;

    /* NAND read function to read the header. */
    SblNandReadFlash(&gSblNandObj, IMAGE_OFFSET, sizeof(imageHdr),
        (uint8_t *) &imageHdr);
    CONSOLEUtilsPrintf("\nCopying Header of the application image ");

    *pEntryPoint = imageHdr.load_addr;

    CONSOLEUtilsPrintf("\nCopying image from flash to DDR\r\n");
    /* Copies application from NAND flash to DDR RAM */
    SblNandReadFlash(&gSblNandObj, IMAGE_OFFSET + sizeof(imageHdr),
        imageHdr.image_size, (uint8_t *)(imageHdr.load_addr));

    return status;
}

static uint32_t SblNandReadFlash(nandAppObj_t *pNandLibInfo,
                                 uint32_t flashAddr,
                                 uint32_t size,
                                 uint8_t *destAddr)
{
    static uint32_t currBlock = 0xFFFFFFFFU;
    static uint32_t currPage  = 0xFFFFFFFFU;
    int32_t status = S_PASS;
    uint32_t pageSize = NAND_FLASH_PAGE_SIZE;
    uint32_t blockSize = NAND_FLASH_BLOCK_SIZE;
    uint32_t memBufferPtr = 0U;
    uint32_t bytesLeftInBuff = 0U;
    uint32_t bytesToCopy = 0U;
    uint32_t blockNum = (flashAddr / blockSize);
    uint32_t pageNum = (flashAddr - (blockNum * blockSize)) / pageSize;
    uint32_t pagesPerBlk = NAND_FLASH_PAGES_PER_BLK;

    /* Check to see if we need to buffer a new page */
    if((blockNum != currBlock) || (pageNum != currPage))
    {
        if(NAND_LIB_BLOCK_GOOD == NANDLibBadBlockCheck(&gSblNandObj.nandLibInfo,
             blockNum))
        {
            currBlock = blockNum;
            currPage = pageNum;
            status = NANDLibPageRead(&gSblNandObj.nandLibInfo, currBlock,
                        currPage, &gSblRxData[0]);
            if(NAND_LIB_PASS == status)
            {
                CONSOLEUtilsPrintf("\r\nReading Image From NAND");
            }
        }
        else
        {
            CONSOLEUtilsPrintf("\r\n NAND Bad Block Check Failed"
                    "...NAND Read Failed.");
        }
    }

    /* Figure out offset in buffered page */
    memBufferPtr = flashAddr - (currBlock * blockSize) - (currPage * pageSize);

    /*
    ** Now we do the actual reading of bytes
    ** If there are bytes in the memory buffer, use them first.
    */
    bytesLeftInBuff = NAND_FLASH_PAGE_SIZE - memBufferPtr;

    if(bytesLeftInBuff > 0U)
    {
        bytesToCopy = (bytesLeftInBuff >= size) ? size : bytesLeftInBuff;

        memcpy((void *)destAddr, (void *) &gSblRxData[memBufferPtr], bytesToCopy);
        destAddr += bytesToCopy;
        size -= bytesToCopy;
        flashAddr += bytesToCopy;

        bytesLeftInBuff -= bytesToCopy;
    }

    /*
    ** If we have one or more full blocks to copy, copy them directly
    ** Any leftover data (partial page) gets copied via the memory buffer
    */
    while (size > 0)
    {
        uint8_t *pTempPtr = NULL;
        currPage += 1;

        /* Check to see if curr page is at end of a block */
        if (currPage >= pagesPerBlk)
        {
            /* If so, increment current block until we are in a good block */
            do
            {
                currBlock += 1;
            }
            while(NANDLibBadBlockCheck(&gSblNandObj.nandLibInfo, currBlock)!=
                 NAND_LIB_BLOCK_GOOD);
            currPage  = 0U;
        }

        /* Read the new current page in the current block to its destination */
        pTempPtr = (uint8_t *)(size >= pageSize) ? destAddr :((uint8_t *)gSblRxData);
        bytesToCopy = (size >= pageSize) ? pageSize : size;

        status = NANDLibPageRead(&gSblNandObj.nandLibInfo, currBlock, currPage,
                     pTempPtr);
        if(NAND_LIB_PASS != status)
        {
            CONSOLEUtilsPrintf("\r\n Reading Image From NAND"
                "...NAND Read Failed.");
        }

        if (pTempPtr != destAddr)
        {
            /*
            ** If the last copy was a partial page, copy byteCnt
            ** bytes from memory buffer pointer to the dest
            */
            memcpy((void *)destAddr, (void *)gSblRxData, bytesToCopy);
        }
        size      -= bytesToCopy;
        destAddr  += bytesToCopy;
        flashAddr += bytesToCopy;
    }

    return status;
}

static int32_t SblNandBoardInfoGet(nandAppObj_t *pObj)
{
    uint32_t *pNandDeviceIdList;
    int32_t status = E_FAIL;
    chipdbModuleID_t modId;
    uint32_t devIndex = 0U;

    /* Check which NAND device is present on this board. */
    pNandDeviceIdList = NANDGetDeviceIdList();

    do {
        if(TRUE == BOARDIsDevicePresent(pNandDeviceIdList[devIndex]))
        {
            /* NAND device found */
            pObj->nandFlashId = pNandDeviceIdList[devIndex];
            break;
        }
        devIndex++;
    } while (DEVICE_ID_INVALID != pNandDeviceIdList[devIndex]);

    if (DEVICE_ID_INVALID == pNandDeviceIdList[devIndex])
    {
        CONSOLEUtilsPrintf("No NAND Flash found \n");
    }
    else
    {
        /* Get the control mod id for the current device */
        modId = BOARDGetDeviceCtrlModId(pObj->nandFlashId, NAND_FLASH_INST_NUM);

        if (CHIPDB_MOD_ID_INVALID == modId)
        {
            CONSOLEUtilsPrintf("NAND Flash is not available on this board!\n");
        }
        else if (CHIPDB_MOD_ID_GPMC == modId)
        {
            CONSOLEUtilsPrintf("NAND flash is connected to GPMC on this board"
                "\n");

            /*
            ** Get the Chip Select of the GPMC to which the Flash is connected.
            */
            pObj->nandLibInfo.nandLibCtrlInfo.chipSel =
                BOARDGetDeviceCtrlModInstNum(pObj->nandFlashId,
                    NAND_FLASH_INST_NUM);

            /*
            ** Get the Wait Pin number connected to the Ready/Busy Pin of
            ** the device.
            */
            pObj->nandLibInfo.nandLibFlashInfo.waitPinNum =
                BOARDGetDeviceCtrlInfo(pObj->nandFlashId, NAND_FLASH_INST_NUM);
            status = S_PASS;
        }
        else
        {
            CONSOLEUtilsPrintf("Device is not connected to GPMC!\n");
        }
    }

    return status;
}

static void SblNandUpdateDeviceParams(nandAppObj_t *pObj,
                                      nandDeviceData_t *pDevData)
{
    /* Update the NAND device specific data. */
    pObj->nandLibInfo.nandLibFlashInfo.busWidth = pDevData->busWidth;
    pObj->nandLibInfo.nandLibFlashInfo.waitPinPol = pDevData->waitPinPol;
    pObj->nandLibInfo.nandLibFlashInfo.writeProtectPinLvl =
        pDevData->writeProtectPinLvl;

    pObj->nandLibInfo.nandLibCtrlInfo.xferMode = NAND_LIB_XFER_MODE_POLLING;
    pObj->nandLibInfo.nandLibCtrlInfo.eccAlgo = NAND_LIB_ECC_ALGO_BCH_8BIT;
    pObj->nandLibInfo.nandLibCtrlInfo.memCtrlr = NAND_LIB_MEM_CTRLR_GPMC;

    /* Update the NAND device timing parameters. */
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.csOnTime =
        pDevData->timingParams.csOnTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.csRdOffTime =
        pDevData->timingParams.csRdOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.csWrOffTime =
        pDevData->timingParams.csWrOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.advOnTime =
        pDevData->timingParams.advOnTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.advRdOffTime =
        pDevData->timingParams.advRdOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.advWrOffTime =
        pDevData->timingParams.advWrOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.weOnTtime =
        pDevData->timingParams.weOnTtime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.weOffTime =
        pDevData->timingParams.weOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.oeOnTime =
        pDevData->timingParams.oeOnTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.oeOffTime =
        pDevData->timingParams.oeOffTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.pageBurstAccess =
        pDevData->timingParams.pageBurstAccess;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.rdAccessTime =
        pDevData->timingParams.rdAccessTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.wrAcessTime =
        pDevData->timingParams.wrAcessTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.rdCycleTime =
        pDevData->timingParams.rdCycleTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.wrCycleTime =
        pDevData->timingParams.wrCycleTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.wrDataOnMuxBusTime =
        pDevData->timingParams.wrDataOnMuxBusTime;
    pObj->nandLibInfo.nandLibFlashInfo.timingParams.cycleDelay =
        pDevData->timingParams.cycleDelay;
}
static int32_t SblNandSocInfoGet(nandAppObj_t *pObj)
{
    int32_t status = S_PASS;

    if(TRUE == CHIPDBIsResourcePresent(CHIPDB_MOD_ID_GPMC, 0U))
    {
        /* Update the base address of GPMC and ELM module. */
        pObj->nandLibInfo.nandLibCtrlInfo.baseAddr =
            CHIPDBBaseAddress(CHIPDB_MOD_ID_GPMC, 0U);

        pObj->nandLibInfo.nandLibCtrlInfo.elmAddr =
            CHIPDBBaseAddress(CHIPDB_MOD_ID_ELM, 0U);
    }
    else
    {
        CONSOLEUtilsPrintf("GPMC IP is not present on this SOC!\n");
        status = E_FAIL;
    }

    return status;
}
