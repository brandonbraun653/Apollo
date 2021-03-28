/*
 * Copyright (c) 2016, Texas Instruments Incorporated
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

#include <ti/board/src/flash/nand/gpmc/nand_gpmc.h>
#include <ti/drv/gpmc/soc/GPMC_soc.h>


static NAND_HANDLE Nand_gpmcOpen(uint32_t nandIntf, uint32_t portNum, void *params);
static void Nand_gpmcClose(NAND_HANDLE handle);
static NAND_STATUS Nand_gpmcRead(NAND_HANDLE handle, uint32_t addr,
                              uint32_t len, uint8_t *buf);
static NAND_STATUS Nand_gpmcWrite(NAND_HANDLE handle, uint32_t addr,
                         uint32_t len, uint8_t *buf);
static NAND_STATUS Nand_gpmcErase(NAND_HANDLE handle, int32_t block);

/* NAND function table for NAND GPMC interface implementation */
const NAND_FxnTable Nand_gpmcFxnTable =
{
    &Nand_gpmcOpen,
    &Nand_gpmcClose,
    &Nand_gpmcRead,
    &Nand_gpmcWrite,
    &Nand_gpmcErase,
};

NAND_Info Nand_gpmcInfo =
{
    0,                        /* hwHandle */
    0,                        /* manufacturerId */
    0,                        /* deviceId */
    NAND_BUSWIDTH_8BITS,      /* busWidth */
    NAND_NUM_BLOCKS,          /* blockCnt */
    NAND_NUM_PAGES_PER_BLOCK, /* pageCnt */
    NAND_PAGE_SIZE,           /* pageSize */
    NAND_SPARE_AREA_SIZE,     /* spareSize */
    NAND_BAD_BLK_OFFSET,      /* bbOffset */
    NULL,                     /* bbList */
    NAND_ECC_ALGO_BCH_8BIT,   /* eccAlgo */
    NAND_PAGE_SIZE + NAND_ECC_BCH_8BIT_OOB_OFFSET, /* eccOffset */
    NAND_ECC_BCH_8BIT_BYTECNT /* eccByteCount */
};

uint8_t Nand_gpmcBBlist[NAND_NUM_BLOCKS] = {0, };

static void Nand_delay(uint32_t usec)
{
#if defined (evmAM437x)
    /* Board_delay is currently not supported for AM devices */
    volatile uint32_t count = usec * 1000000;

    while (count)
    {

        count--;
        if (0U == count)
        {
            break;
        }
    }
#elif defined (evmK2G)
    Board_delay(usec);
#else
#endif
}

static void Nand_gpmcSetCmd(GPMC_Handle handle, uint32_t cmd)
{
	uint32_t nandCmd = cmd;
    GPMC_control(handle, GPMC_V1_CMD_SETNANDCMD, (void *)(&nandCmd));
}

static void Nand_gpmcSetAddr(GPMC_Handle handle, uint32_t addr)
{
	uint32_t nandAddr = addr;
    GPMC_control(handle, GPMC_V1_CMD_SETNANDADDR, (void *)(&nandAddr));
}

static void Nand_gpmcWriteData(GPMC_Handle handle, uint8_t *txbuf, uint32_t size)
{
    uint32_t    params[2];

    params[0] = (uint32_t)txbuf;
    params[1] = size;
    GPMC_control(handle, GPMC_V1_CMD_WRNANDDATA, (void *)params);
}

static void Nand_gpmcReadData(GPMC_Handle handle, uint8_t *rxbuf, uint32_t size)
{
    uint32_t    params[2];

    params[0] = (uint32_t)rxbuf;
    params[1] = size;
    GPMC_control(handle, GPMC_V1_CMD_RDNANDDATA, (void *)params);
}

static NAND_STATUS Nand_gpmcWaitPinStatus(GPMC_Handle handle, uint32_t timeout)
{
    uint32_t status = NAND_PASS;
    uint32_t waitPinStatus;

    /*
    ** This function is called immediatly after issuing commands
    ** to the NAND flash. Since the NAND flash takes sometime to
    ** pull the R/B line low,it would be safe to introduce a delay
    ** before checking the ready/busy status.
    */
    Nand_delay(1U);

    while(timeout)
    {
        /* Check the Ready/Busy status. */
        GPMC_control(handle, GPMC_V1_CMD_GETWAITPINSTATUS, (void *)(&waitPinStatus));
        if(waitPinStatus != 0U)
        {
            break;
        }
        timeout--;
    }

    if(0U == timeout)
    {
        status = NAND_TIMEOUT;
    }

    return status;
}

static NAND_STATUS Nand_reset(GPMC_Handle handle)
{
    Nand_gpmcSetCmd(handle, NAND_CMD_RESET);

    return (Nand_gpmcWaitPinStatus(handle, NAND_TIMEOUT_VAL));
}

static NAND_STATUS Nand_gpmcReadId(GPMC_Handle handle)
{
    uint8_t     idCode[NAND_RDID_NUM_BYTES];
    uint32_t    devID;
    NAND_STATUS ret = NAND_PASS;

    Nand_gpmcSetCmd(handle, NAND_CMD_RDID);
    Nand_gpmcSetAddr(handle, 0);
    Nand_delay(1);

    ret = Nand_gpmcWaitPinStatus(handle, NAND_TIMEOUT_VAL);
    if (ret == NAND_PASS)
    {
        Nand_gpmcReadData(handle, idCode, NAND_RDID_NUM_BYTES);
        devID = ((uint32_t)idCode[1] << 8) | (uint32_t)idCode[2];
        if ((idCode[0] == NAND_MANF_ID) && (devID == NAND_DEVICE_ID))
        {
            Nand_gpmcInfo.manufacturerId = (uint32_t)idCode[0];
            Nand_gpmcInfo.deviceId = devID;
        }
        else
        {
            ret = NAND_FAIL;
        }
    }

    return (ret);
}

static NAND_STATUS Nand_gpmcSendPageReadCmd(GPMC_Handle handle,
                                            uint32_t    blockNum,
                                            uint32_t    pageNum,
                                            uint32_t    columnAddr)
{
    uint32_t colAddr = columnAddr;
    uint32_t pageAddr;
    uint32_t count;

    Nand_gpmcSetCmd(handle, NAND_CMD_READ);

    /* Write 2 Bytes of column address. */
    for (count = 0; count < NAND_NUM_BYTES_COLUMN_ADDR; count++)
    {
        Nand_gpmcSetAddr(handle, colAddr & 0xFF);
        colAddr = colAddr >> 0x8;
    }

    /* Write the 4 bytes of row address. */
    pageAddr = blockNum * NAND_NUM_PAGES_PER_BLOCK + pageNum;
    for (count = 0; count < NAND_NUM_BYTES_ROW_ADDR; count++)
    {
        Nand_gpmcSetAddr(handle, pageAddr & 0xFF);
        pageAddr = pageAddr >> 0x8;
    }

    Nand_gpmcSetCmd(handle, NAND_CMD_READ_CYC2);

    return (Nand_gpmcWaitPinStatus(handle, NAND_TIMEOUT_VAL));
}

static NAND_STATUS Nand_gpmcCheckBadBlock(GPMC_Handle handle, uint32_t blockNum)
{
    uint8_t     badBlkMark[2];
    uint32_t    columnAddr;
    uint32_t    pageNum = 0U;

    columnAddr = NAND_PAGE_SIZE + NAND_BAD_BLK_OFFSET;

    /* Adjust column address for 16 bit address. */
    if (NAND_BUSWIDTH_16BITS == Nand_gpmcInfo.busWidth)
    {
        columnAddr /= 2;
    }

    /* Read the spare area of 1st, 2nd and last page of the block. */
    for(pageNum = 0; pageNum < 3; pageNum++)
    {
        if (2U == pageNum)
        {
            pageNum = (NAND_NUM_PAGES_PER_BLOCK - 1U);
        }

        if (NAND_TIMEOUT == Nand_gpmcSendPageReadCmd(handle, blockNum,
                                                     pageNum, columnAddr))
        {
            return NAND_TIMEOUT;
        }

        /* Read the ECC Data from the spare area */
        Nand_gpmcReadData(handle, badBlkMark, 2);

        /* Check for Bad Block Marker */
        if (badBlkMark[0] != NAND_BLK_GOOD_MARK)
        {
            return NAND_BLOCK_BAD;
        }
        if ((NAND_BUSWIDTH_16BITS == Nand_gpmcInfo.busWidth) &&
            (badBlkMark[1] != NAND_BLK_GOOD_MARK))
        {
            return NAND_BLOCK_BAD;
        }
    }

    return NAND_PASS;
}

static void Nand_gpmcGetBBlist(GPMC_Handle handle, uint8_t *bbList)
{
    NAND_STATUS status;
    uint32_t    count;

    for (count = 0; count < NAND_NUM_BLOCKS; count++)
    {
		status = Nand_gpmcCheckBadBlock(handle, count);
		if (status == NAND_BLOCK_BAD)
        {
            bbList[count] = NAND_BAD_BLOCK;
        }
        else
        {
            bbList[count] = NAND_GOOD_BLOCK;
        }
    }
}

static NAND_HANDLE Nand_gpmcOpen(uint32_t nandIntf, uint32_t portNum, void *params)
{
    GPMC_Params     gpmcParams;  /* GPMC params structure */
    GPMC_Handle     gpmcHandle;  /* GPMC handle */
    NAND_HANDLE     nandHandle = 0;

    /* Init GPMC driver */
    GPMC_init();

    if (params)
    {
        memcpy(&gpmcParams, params, sizeof(GPMC_Params));
    }
    else
    {
        /* Use default GPMC config params if no params provided */
        GPMC_Params_init(&gpmcParams);
    }
    gpmcHandle = (GPMC_Handle)GPMC_open(portNum, &gpmcParams);

    if (gpmcHandle)
    {
		GPMC_control(gpmcHandle, GPMC_V1_CMD_GETDEVSIZE, (void *)(&Nand_gpmcInfo.busWidth));
        GPMC_control(gpmcHandle, GPMC_V1_CMD_ECCGETINFO, (void *)(&Nand_gpmcInfo.eccAlgo));
        if (Nand_gpmcInfo.eccAlgo == NAND_ECC_ALGO_HAMMING_1BIT)
        {
            Nand_gpmcInfo.eccOffset = NAND_PAGE_SIZE + NAND_ECC_1BIT_HAMMINGCODE_OOB_OFFSET;
            Nand_gpmcInfo.eccByteCount = NAND_ECC_1BIT_HAMMINGCODE_BYTECNT;
        }
        else if (Nand_gpmcInfo.eccAlgo == NAND_ECC_ALGO_BCH_8BIT)
        {
            Nand_gpmcInfo.eccOffset = NAND_PAGE_SIZE + NAND_ECC_BCH_8BIT_OOB_OFFSET;
            Nand_gpmcInfo.eccByteCount = NAND_ECC_BCH_8BIT_BYTECNT;
        }
        else
        {
			/* Not supported */
            Nand_gpmcInfo.eccOffset = 0;
            Nand_gpmcInfo.eccByteCount = 0;
        }

        if (Nand_reset(gpmcHandle) == NAND_PASS)
        {
            if (Nand_gpmcReadId(gpmcHandle) == NAND_PASS)
            {
                Nand_gpmcGetBBlist(gpmcHandle, Nand_gpmcBBlist);
                Nand_gpmcInfo.bbList = Nand_gpmcBBlist;
                Nand_gpmcInfo.hwHandle = (uint32_t)gpmcHandle;
                nandHandle = (NAND_HANDLE)(&Nand_gpmcInfo);

                return (nandHandle);
            }
            else
            {
                goto err;
            }
        }
        else
        {
            goto err;
        }
	}

err:
    if (gpmcHandle)
    {
        GPMC_close(gpmcHandle);
    }
    Nand_gpmcInfo.hwHandle = 0;
    return (nandHandle);
}

static void Nand_gpmcClose(NAND_HANDLE handle)
{
    NAND_Info    *nandGpmcInfo;

    if (handle)
    {
        nandGpmcInfo = (NAND_Info *)handle;
        if (nandGpmcInfo->hwHandle)
        {
            GPMC_close((GPMC_Handle)nandGpmcInfo->hwHandle);
            nandGpmcInfo->hwHandle = 0;
        }
    }
}

static NAND_STATUS Nand_gpmcDeviceStatus(GPMC_Handle handle)
{
    NAND_STATUS      status = NAND_PASS;
    uint8_t          nandDevStatus;

    Nand_gpmcSetCmd(handle, NAND_CMD_READ_STATUS);

    Nand_delay(10U);

    Nand_gpmcReadData(handle, &nandDevStatus, 1U);

    if(nandDevStatus & NAND_READ_STATUS_FAIL_MASK)
    {
        status = NAND_FAIL;
    }

    if(!(nandDevStatus & NAND_READ_STATUS_DEVRDY_MASK))
    {
        status = NAND_DEV_BUSY;
    }

    if(!(nandDevStatus & NAND_READ_STATUS_WRPROT_MASK))
    {
        status = NAND_DEV_PROTECTED;
    }

    return status;
}

static void Nand_gpmcEccEnable(GPMC_Handle handle)
{
	uint32_t control = 1;

    GPMC_control(handle, GPMC_V1_CMD_ECCCONTROL, (void *)(&control));
}

static void Nand_gpmcEccDisable(GPMC_Handle handle)
{
	uint32_t control = 0;

    GPMC_control(handle, GPMC_V1_CMD_ECCCONTROL, (void *)(&control));
}

static void Nand_gpmcEccReadSizeSet(GPMC_Handle handle)
{
    uint32_t eccSize[2];

    if(GPMC_NAND_ECC_ALGO_BCH_8BIT == Nand_gpmcInfo.eccAlgo)
    {
        eccSize[0] = (NAND_ECC_BCH_8BIT_BYTECNT * 2) - NAND_ECC_BCH_8BIT_UNUSED_BYTECNT;
        eccSize[1] = NAND_ECC_BCH_8BIT_UNUSED_BYTECNT;
    }
    else
    {
        /* Not Supported */
        eccSize[0] = 0U;
        eccSize[0] = 0U;
    }

    GPMC_control(handle, GPMC_V1_CMD_ECCSETSIZE, (void *)eccSize);
}

static void Nand_gpmcEccWriteSizeSet(GPMC_Handle handle)
{
    uint32_t eccSize[2];

    if(GPMC_NAND_ECC_ALGO_BCH_8BIT == Nand_gpmcInfo.eccAlgo)
    {
        eccSize[0] = 0;
        eccSize[1] = NAND_ECC_BCH_8BIT_BYTECNT * 2;
    }
    else
    {
        /* Not Supported */
        eccSize[0] = 0U;
        eccSize[0] = 0U;
    }

    GPMC_control(handle, GPMC_V1_CMD_ECCSETSIZE, (void *)eccSize);
}

static uint32_t Nand_gpmcGetEccResult(GPMC_Handle handle,
                                      uint32_t    eccResIdx)
{
    uint32_t eccResult[2];

    eccResult[0] = eccResIdx;
    GPMC_control(handle, GPMC_V1_CMD_ECCGETRESULT, (void *)eccResult);

    return (eccResult[1]);
}

static void Nand_gpmcHammingCodeEccCalculate(GPMC_Handle handle,
                                             uint32_t    eccResIdx,
                                             uint8_t    *pEccData)
{
    uint32_t eccVal;

    eccVal  = Nand_gpmcGetEccResult(handle, eccResIdx);
    /*
    ** Squeeze 4 bytes ECC into 3 bytes by removing RESERVED bits
    ** and shifting. RESERVED bits are 31 to 28 and 15 to 12.
    */
    eccVal = (eccVal & 0x00000FFF) | ((eccVal & 0x0FFF0000) >> 4);
    /* Invert so that erased block ECC is correct */
    eccVal = ~eccVal;

    *pEccData++ = (uint8_t)eccVal;
    *pEccData++ = (uint8_t)eccVal >>  8U;
    *pEccData++ = (uint8_t)eccVal >> 16U;
}

static NAND_STATUS Nand_gpmcHamCodeEccCorrect(GPMC_Handle handle,
                                              uint8_t    *pEccRead,
                                              uint8_t    *pData)
{
    NAND_STATUS status = NAND_PASS;
    uint8_t     eccCalc[4];
    uint32_t    readEccVal = 0U;
    uint32_t    calcEccVal = 0U;
    uint32_t    eccDiffVal = 0U;
    uint32_t    bitPos = 0U;
    uint32_t    bytePos = 0U;

    Nand_gpmcHammingCodeEccCalculate(handle, 1, &eccCalc[0]);

    readEccVal = pEccRead[0] | (pEccRead[1] << 8) | (pEccRead[2] << 16);
    calcEccVal = eccCalc[0] | (eccCalc[1] << 8) | (eccCalc[2] << 16);
    eccDiffVal = readEccVal ^ calcEccVal;

    if(eccDiffVal)
    {
        /*
        ** No error              : The ecc diff value (eccDiffVal) is 0.
        ** Correctable error     : For 512-byte inputs, ecc diff value has
        **                         12 bits at 1. For 256 byte ecc diff value has
        **                         11 bits at 1.
        ** ECC error             : The ecc diff value has only 1 bit at 1.
        ** Non-correctable error : The ecc diff value provides all other results
        */

        /*
        ** Below condition checks for number of 1's in eccDiffValu.
        ** Since Total ecc has 3bytes = 24 bits. Make 2 halfs and XOR.
        ** If eccDiffVal has  12 1's, it produces the result 0xFFF.
        */
        if ((((eccDiffVal >> 12) ^ eccDiffVal) & 0xfff) == 0xfff)
        {
             /* Correctable error
             ** Check bytePos is within NAND_BYTES_PER_XFER i.e 512
             */
            if ((eccDiffVal >> (12 + 3)) < NAND_BYTES_PER_XFER)
            {
                bitPos  = 1 << ((eccDiffVal >> 12) & 7);
                bytePos = eccDiffVal >> (12 + 3);
                pData[bytePos] ^= bitPos;
                status = NAND_ECC_ERR_CORRECTED;
            }
            else
            {
                status = NAND_ECC_UNCORRECTABLE;
            }
        }
        else if(!(eccDiffVal & (eccDiffVal - 1)))
        {
            /* Single bit ECC error in the ECC itself,nothing to fix */
            status = NAND_ECC_ERR_CORRECTED;
        }
        else
        {
            status = NAND_ECC_UNCORRECTABLE;
        }
    }

    return (status);
}

static uint32_t Nand_gpmcGetEccBchResult(GPMC_Handle handle,
                                         uint32_t    eccResIdx)
{
    uint32_t eccResult[2];

    eccResult[0] = eccResIdx;
    GPMC_control(handle, GPMC_V1_CMD_ECCGETBCHRESULT, (void *)eccResult);

    return (eccResult[1]);
}

static void Nand_gpmcBchEccCalculate(GPMC_Handle handle,
                                     uint8_t    *pEccData)
{
    uint32_t eccRes;

    if (NAND_ECC_ALGO_BCH_8BIT == Nand_gpmcInfo.eccAlgo)
    {
        eccRes = Nand_gpmcGetEccBchResult(handle, 3);
        pEccData[0] = (eccRes & 0xFF);
        eccRes = Nand_gpmcGetEccBchResult(handle, 2);
        pEccData[1] = ((eccRes >> 24) & 0xFF);
        pEccData[2] = ((eccRes >> 16) & 0xFF);
        pEccData[3] = ((eccRes >> 8) & 0xFF);
        pEccData[4] = (eccRes & 0xFF);
        eccRes = Nand_gpmcGetEccBchResult(handle, 1);
        pEccData[5] = ((eccRes >> 24) & 0xFF);
        pEccData[6] = ((eccRes >> 16) & 0xFF);
        pEccData[7] = ((eccRes >> 8) & 0xFF);
        pEccData[8] = (eccRes & 0xFF);
        eccRes = Nand_gpmcGetEccBchResult(handle, 0);
        pEccData[9] = ((eccRes >> 24) & 0xFF);
        pEccData[10] = ((eccRes >> 16) & 0xFF);
        pEccData[11] = ((eccRes >> 8) & 0xFF);
        pEccData[12] = (eccRes & 0xFF);
    }
    else
    {
       /* Not Supported */
    }
}

static void  Nand_gpmcElmSyndromeFrgmtSet(GPMC_Handle handle,
                                          uint32_t    synFrgmtId,
                                          uint32_t    synFrgmtVal)
{
    uint32_t    params[2];

    params[0] = synFrgmtId;
    params[1] = synFrgmtVal;
    GPMC_control(handle, GPMC_V1_CMD_ELMSETSYNDFRGMT, (void *)params);
}

static void  Nand_gpmcElmErrLocProcessingStart(GPMC_Handle handle)
{
    GPMC_control(handle, GPMC_V1_CMD_ELMSTARTERRLOCPROC, NULL);
}

static uint32_t Nand_gpmcElmIntStatusGet(GPMC_Handle handle,
                                         uint32_t    locValidStatus)
{
    uint32_t    params[2];

    params[0] = locValidStatus;
    GPMC_control(handle, GPMC_V1_CMD_ELMGETINTSTATUS, (void *)params);

    return (params[1]);
}

static void Nand_gpmcElmIntStatusClear(GPMC_Handle handle,
                                       uint32_t    locValidStatus)
{
    uint32_t    params;

    params = locValidStatus;
    GPMC_control(handle, GPMC_V1_CMD_ELMCLRINTSTATUS, (void *)(&params));
}

static uint32_t Nand_gpmcElmErrLocProcessingStatusGet(GPMC_Handle handle)
{
    uint32_t    params;

    GPMC_control(handle, GPMC_V1_CMD_ELMGETERRLOCPROCSTATUS,
                (void *)(&params));
    return (params);
}

static uint32_t Nand_gpmcElmNumOfErrsGet(GPMC_Handle handle)
{
    uint32_t    params;

    GPMC_control(handle, GPMC_V1_CMD_ELMGETNUMERRS,
                (void *)(&params));
    return (params);
}

static uint32_t Nand_gpmcElmErrLocBitAddrGet(GPMC_Handle handle,
                                             uint32_t    errNum)
{
    uint32_t    params[2];

    params[0] = errNum;
    GPMC_control(handle, GPMC_V1_CMD_ELMGETERRLOCADDR, (void *)params);

    return (params[1]);
}

static NAND_STATUS Nand_gpmcBchEccCheckAndCorrect(GPMC_Handle handle,
                                                  uint8_t    *pEccRead,
                                                  uint8_t    *pData)
{
    NAND_STATUS status = NAND_PASS;
    uint32_t intrStatus = 0U;
    uint32_t eccVal = 0U;
    uint32_t i = 0U;
    uint32_t errNum = 0U;
    uint32_t numOfErrs = 0U;
    uint32_t errLoc = 0U;
    uint32_t lastECCBit = 0U;
    uint32_t lastDataBit = 0U;
    uint32_t errBitMask = 0U;
    uint32_t errBytePos = 0U;
    uint32_t numBytes = 0U;
    uint8_t eccCalc[NAND_ECC_BCH_8BIT_BYTECNT * 4] = {0, 0, 0, 0};
    uint8_t syndrome[NAND_ECC_BCH_8BIT_BYTECNT * 4];
    uint32_t j;

    if (NAND_ECC_ALGO_BCH_8BIT == Nand_gpmcInfo.eccAlgo)
    {

        numBytes    = NAND_ECC_BCH_8BIT_BYTECNT - 1;
        lastECCBit  = NAND_ECC_BCH_8BIT_LASTECCBIT;
        lastDataBit = NAND_ECC_BCH_8BIT_LASTDATABIT;
    }
    else
    {
       /* Not Supported */
        numBytes    = 0;
        lastECCBit  = 0;
        lastDataBit = 0;
    }

    Nand_gpmcBchEccCalculate(handle, &eccCalc[0]);

    /*
    ** While reading ECC result we read it in big endian.
    ** Hence while loading to ELM we have rotate to get the right endian.
    */

    /* Rotate the syndrome bytes */
    for (i = 0, j = (numBytes-1); i < numBytes; i++, j--)
          syndrome[i] = eccCalc[j];

    /* Load the BCH syndrome */
    eccVal = (syndrome[0] | (syndrome[1] << 8) | (syndrome[2] << 16) |
              (syndrome[3] << 24));
    Nand_gpmcElmSyndromeFrgmtSet(handle, 0, eccVal);

    eccVal = (syndrome[4] | (syndrome[5] << 8) | (syndrome[6] << 16) |
              (syndrome[7] << 24));
    Nand_gpmcElmSyndromeFrgmtSet(handle, 1, eccVal);

    if(Nand_gpmcInfo.eccAlgo == NAND_ECC_ALGO_BCH_8BIT)
    {
        eccVal = (syndrome[8] | (syndrome[9] << 8) | (syndrome[10] << 16) |
                 (syndrome[11] << 24));
        Nand_gpmcElmSyndromeFrgmtSet(handle, 2, eccVal);

        eccVal = (syndrome[12] | (syndrome[13] << 8) | (syndrome[14] << 16) |
                 (syndrome[15] << 24));
        Nand_gpmcElmSyndromeFrgmtSet(handle, 3, eccVal);
    }

    Nand_gpmcElmErrLocProcessingStart(handle);

    while(intrStatus == 0)
    {
        intrStatus = Nand_gpmcElmIntStatusGet(handle, 0);
    }

    Nand_gpmcElmIntStatusClear(handle, 0);

    if(Nand_gpmcElmErrLocProcessingStatusGet(handle))
    {
        numOfErrs = Nand_gpmcElmNumOfErrsGet(handle);
        if(numOfErrs == 0)
        {
            status = NAND_PASS;
        }
        else
        {
            errNum = 0U;
             /* Get the error location and correct the same */
            for(i = 0; i < numOfErrs; i++)
            {
                errLoc = Nand_gpmcElmErrLocBitAddrGet(handle, errNum);
                if (errLoc >= (lastECCBit - 1))
                {
                   /* Error is at the Data bytes */
                    errBytePos = ((lastDataBit - 1) - errLoc) / 8;
                    /* Error Bit mask */
                    errBitMask = 0x1 << (errLoc % 8);
                    /* Toggle the error bit to make the correction. */
                    pData[errBytePos] ^= errBitMask;
                    status = NAND_ECC_ERR_CORRECTED;
                }
                else
                {
                    /* Error is at the ECC bytes which we are not handling */
                }
                errNum++;
            }
        }
    }
    else
    {
        status = NAND_ECC_UNCORRECTABLE;
    }

    return status;
}

static void Nand_gpmcEccCalculate(GPMC_Handle handle,
                                  uint8_t *pEccData)
{
    if(Nand_gpmcInfo.eccAlgo == NAND_ECC_ALGO_HAMMING_1BIT)
    {
        Nand_gpmcHammingCodeEccCalculate(handle, 1, pEccData);
    }
    else if((Nand_gpmcInfo.eccAlgo == NAND_ECC_ALGO_BCH_4BIT) ||
            (Nand_gpmcInfo.eccAlgo == NAND_ECC_ALGO_BCH_8BIT))
    {
        Nand_gpmcBchEccCalculate(handle, pEccData);
    }
}

static NAND_STATUS Nand_gpmcEccCheckAndCorrect(GPMC_Handle handle,
                                               uint8_t    *pEccRead,
                                               uint8_t    *pData)
{
    NAND_STATUS status = NAND_PASS;

    if(Nand_gpmcInfo.eccAlgo == NAND_ECC_ALGO_HAMMING_1BIT)
    {
        status = Nand_gpmcHamCodeEccCorrect(handle, pEccRead, pData);
    }
    else if(Nand_gpmcInfo.eccAlgo == NAND_ECC_ALGO_BCH_8BIT)
    {
        status = Nand_gpmcBchEccCheckAndCorrect(handle, pEccRead, pData);
    }
    else
    {
       /* Not Supported */
    }

    return status;
}

static NAND_STATUS  Nand_gpmcReadPage(GPMC_Handle handle,
                                      uint32_t    blockNum,
                                      uint32_t    pageNum,
                                      uint8_t    *pRxData)
{
    NAND_STATUS       status;
    GPMC_Transaction  transaction;
    uint32_t          columnAddr = 0U;
    uint8_t           eccData[256] = {0, };
    uint32_t          xferCount, count;
    uint8_t          *pEccData = eccData;
    uint32_t          eccCorFlag = 0U;


    /* Disable the ECC engine. */
    Nand_gpmcEccDisable(handle);

    status = Nand_gpmcSendPageReadCmd(handle, blockNum, pageNum, columnAddr);

    if(NAND_PASS == status)
    {
        if (NAND_ECC_ALGO_NONE != Nand_gpmcInfo.eccAlgo)
        {
            Nand_gpmcEccReadSizeSet(handle);
            Nand_gpmcEccDisable(handle);
        }

        for(xferCount = 0; xferCount < (NAND_PAGE_SIZE/
            NAND_BYTES_PER_XFER); xferCount++)
        {
            if (NAND_ECC_ALGO_NONE != Nand_gpmcInfo.eccAlgo)
            {
                Nand_gpmcEccEnable(handle);
            }

            transaction.txBuf = NULL;
            transaction.rxBuf = (void *)pRxData;
            transaction.count = NAND_BYTES_PER_XFER;

            if (false == GPMC_transfer(handle, &transaction))
            {
                return NAND_FAIL;
            }

            if(NAND_ECC_ALGO_NONE != Nand_gpmcInfo.eccAlgo)
            {
                /* Read the ECC data, as BCH algorithm requires this for
                   syndrome calculation. */
                columnAddr = Nand_gpmcInfo.eccOffset +
                             (xferCount * Nand_gpmcInfo.eccByteCount);
                if(Nand_gpmcInfo.busWidth == NAND_BUSWIDTH_16BITS)
                {
                    columnAddr = columnAddr/2;
                }

                Nand_gpmcSetCmd(handle, NAND_CMD_READ_RANDOM);

                /* Write 2 Bytes of column address. */
                for (count = 0; count < NAND_NUM_BYTES_COLUMN_ADDR; count++)
                {
                    Nand_gpmcSetAddr(handle, columnAddr & 0xFF);
                    columnAddr = columnAddr >> 8U;
                }

                Nand_gpmcSetCmd(handle, NAND_CMD_READ_RANDOM_CYC2);

                status = Nand_gpmcWaitPinStatus(handle, NAND_TIMEOUT_VAL);
            }

            if(NAND_PASS == status)
            {
                /* Read ECC data from the Spare area. */
                Nand_gpmcReadData(handle, pEccData,
                                  Nand_gpmcInfo.eccByteCount - 1);
                status = Nand_gpmcEccCheckAndCorrect(handle, pEccData, pRxData);
                Nand_gpmcEccDisable(handle);

                if(status & NAND_ECC_ERR_CORRECTED)
                {
                        eccCorFlag = 1U;
                }
                else if(status & NAND_ECC_UNCORRECTABLE)
                {
                        break;
                }
                else
                {

                }
            }

            if(NAND_ECC_ALGO_BCH_8BIT == Nand_gpmcInfo.eccAlgo)
            {
                /* Reset the column pointer to appropriate position.  */
                columnAddr = ((xferCount + 1) * (NAND_BYTES_PER_XFER));
                if(Nand_gpmcInfo.busWidth == NAND_BUSWIDTH_16BITS)
                {
                    columnAddr = columnAddr/2;
                }
                if(xferCount != (NAND_PAGE_SIZE / NAND_BYTES_PER_XFER - 1))
                {
                    Nand_gpmcSetCmd(handle, NAND_CMD_READ_RANDOM);

                    /* Write 2 Bytes of column address. */
                    for (count = 0; count < NAND_NUM_BYTES_COLUMN_ADDR; count++)
                    {
                        Nand_gpmcSetAddr(handle, columnAddr & 0xFF);
                        columnAddr = columnAddr >> 8U;
                    }

                    Nand_gpmcSetCmd(handle, NAND_CMD_READ_RANDOM_CYC2);

                    status = Nand_gpmcWaitPinStatus(handle, NAND_TIMEOUT_VAL);
                    if(NAND_PASS != status)
                    {
                        return status;
                    }
                }
                pEccData += Nand_gpmcInfo.eccByteCount;
            }
            pRxData += NAND_BYTES_PER_XFER;
        }
        if(eccCorFlag && (!(status & NAND_ECC_UNCORRECTABLE)))
        {
            status = NAND_ECC_ERR_CORRECTED;
        }
    }
    return status;
}

static NAND_STATUS Nand_gpmcRead(NAND_HANDLE handle, uint32_t addr,
                              uint32_t len, uint8_t *buf)
{
    NAND_STATUS       status = NAND_PASS;
    NAND_Info        *nandGpmcInfo;
    uint32_t          blockNum;
    uint32_t          pageNum;
    uint32_t          numPages;
    uint32_t          count;
    uint8_t          *rxData = (uint8_t *)buf;

    if (!handle)
    {
        return NAND_INVALID_PARAM;
    }

    nandGpmcInfo = (NAND_Info *)handle;
    if (!nandGpmcInfo->hwHandle)
    {
        return NAND_FAIL;
    }

    /* Validate address input */
    if ((addr + len) > NAND_SIZE)
    {
        return NAND_INVALID_PARAM;
    }

    blockNum = addr / NAND_BLOCK_SIZE;
    pageNum = (addr % NAND_BLOCK_SIZE) / NAND_PAGE_SIZE;
    numPages = len / NAND_PAGE_SIZE;

    for (count = 0; count < numPages; count++)
    {
        status = Nand_gpmcReadPage((GPMC_Handle)nandGpmcInfo->hwHandle, blockNum,
                                   pageNum, rxData);
        if ((status != NAND_PASS) &&
            (status != NAND_ECC_ERR_CORRECTED))
        {
           return status;
        }
        rxData += NAND_PAGE_SIZE;
    }

    return status;
}

static void Nand_gpmcStartPageWriteCmd(GPMC_Handle handle,
                                       uint32_t    blockNum,
                                       uint32_t    pageNum,
                                       uint32_t    columnAddr)
{
    uint32_t colAddr = columnAddr;
    uint32_t pageAddr;
    uint32_t count;

    Nand_gpmcSetCmd(handle, NAND_CMD_PROG_PAGE);

    /* Write 2 Bytes of column address. */
    for (count = 0; count < NAND_NUM_BYTES_COLUMN_ADDR; count++)
    {
        Nand_gpmcSetAddr(handle, colAddr & 0xFF);
        colAddr = colAddr >> 0x8;
    }

    /* Write the 4 bytes of row address. */
    pageAddr = blockNum * NAND_NUM_PAGES_PER_BLOCK + pageNum;
    for (count = 0; count < NAND_NUM_BYTES_ROW_ADDR; count++)
    {
        Nand_gpmcSetAddr(handle, pageAddr & 0xFF);
        pageAddr = pageAddr >> 0x8;
    }
}

static NAND_STATUS Nand_gpmcEndPageWriteCmd(GPMC_Handle handle)
{
    NAND_STATUS status = NAND_PASS;

    Nand_gpmcSetCmd(handle, NAND_CMD_PROG_PAGE_CYC2);

    status = Nand_gpmcWaitPinStatus(handle, NAND_TIMEOUT_VAL);
    if(NAND_TIMEOUT == NAND_PASS)
    {
        status = Nand_gpmcDeviceStatus(handle);
    }

    return status;
}

static NAND_STATUS Nand_gpmcWritePage(GPMC_Handle handle,
                                      uint32_t    blockNum,
                                      uint32_t    pageNum,
                                      uint8_t    *pTxData)
{
    NAND_STATUS      status = NAND_PASS;
    GPMC_Transaction transaction;
    uint32_t         columnAddr = 0U;
    uint8_t          eccData[256] = {0, };
    uint8_t         *pEccData = eccData;
    uint32_t         xferCount, count;

    Nand_gpmcStartPageWriteCmd(handle, blockNum, pageNum, columnAddr);

    if(NAND_ECC_ALGO_NONE != Nand_gpmcInfo.eccAlgo)
    {
        Nand_gpmcEccWriteSizeSet(handle);
        Nand_gpmcEccDisable(handle);
    }
    for(xferCount = 0U; xferCount < (NAND_PAGE_SIZE / NAND_BYTES_PER_XFER);
        xferCount++)
    {
        if(NAND_ECC_ALGO_NONE != Nand_gpmcInfo.eccAlgo)
        {
            Nand_gpmcEccEnable(handle);
        }

        transaction.txBuf = (void *)pTxData;
        transaction.rxBuf = NULL;
        transaction.count = NAND_BYTES_PER_XFER;

        if (false == GPMC_transfer(handle, &transaction))
        {
            return NAND_FAIL;
        }

        if(NAND_ECC_ALGO_NONE != Nand_gpmcInfo.eccAlgo)
        {
            Nand_gpmcEccDisable(handle);
            Nand_gpmcEccCalculate(handle, pEccData);
            pEccData += Nand_gpmcInfo.eccByteCount;
        }
        pTxData += NAND_BYTES_PER_XFER;
    }
    if(NAND_PASS == status)
    {
        if(NAND_ECC_ALGO_NONE != Nand_gpmcInfo.eccAlgo)
        {
            if(status == NAND_PASS)
            {
                columnAddr = Nand_gpmcInfo.eccOffset;
                if(Nand_gpmcInfo.busWidth == NAND_BUSWIDTH_16BITS)
                {
                    columnAddr = columnAddr / 2;
                }
                Nand_gpmcSetCmd(handle, NAND_CMD_INPUT_RANDOM);

                /* Write 2 Bytes of column address. */
                for (count = 0; count < NAND_NUM_BYTES_COLUMN_ADDR; count++)
                {
                    Nand_gpmcSetAddr(handle, columnAddr & 0xFF);
                    columnAddr = columnAddr >> 8U;
                }

                Nand_gpmcWriteData(handle, &eccData[0],
                                   Nand_gpmcInfo.eccByteCount *
                                   (NAND_PAGE_SIZE/NAND_BYTES_PER_XFER));
            }
        }
        status = Nand_gpmcEndPageWriteCmd(handle);
    }

    return status;
}

static NAND_STATUS Nand_gpmcWrite(NAND_HANDLE handle, uint32_t addr,
                                  uint32_t len, uint8_t *buf)
{
    NAND_STATUS       status = NAND_PASS;
    NAND_Info        *nandGpmcInfo;
    uint32_t          blockNum;
    uint32_t          pageNum;
    uint32_t          numPages;
    uint32_t          count;
    uint8_t          *txData = (uint8_t *)buf;

    if (!handle)
    {
        return NAND_INVALID_PARAM;
    }

    nandGpmcInfo = (NAND_Info *)handle;
    if (!nandGpmcInfo->hwHandle)
    {
        return NAND_FAIL;
    }

    /* Validate address input */
    if ((addr + len) > NAND_SIZE)
    {
        return NAND_INVALID_PARAM;
    }

    blockNum = addr / NAND_BLOCK_SIZE;
    pageNum = (addr % NAND_BLOCK_SIZE) / NAND_PAGE_SIZE;
    numPages = len / NAND_PAGE_SIZE;

    for (count = 0; count < numPages; count++)
    {
        status = Nand_gpmcWritePage((GPMC_Handle)nandGpmcInfo->hwHandle, blockNum,
                                    pageNum, txData);
        if (status != NAND_PASS)
        {
           return status;
        }
        txData += NAND_PAGE_SIZE;
    }

    return NAND_PASS;
}

static NAND_STATUS Nand_gpmcMarkBlockAsBad(GPMC_Handle handle, uint32_t blockNum)
{
    NAND_STATUS status = NAND_PASS;
    uint32_t    pageNum = 0U;
    uint32_t    columnAddr = 0U;
    uint8_t     badBlkMark[2];

    columnAddr = NAND_PAGE_SIZE + NAND_BAD_BLK_OFFSET;

    /* Adjust column address for 16 bit address. */
    if (NAND_BUSWIDTH_16BITS == Nand_gpmcInfo.busWidth)
    {
        columnAddr /= 2;
    }

    /* Read the spare area of 1st, 2nd and last page of the block */
    for(pageNum = 0; pageNum < 3; pageNum++)
    {
        /* Last page number of the block */
        if(pageNum == 2)
        {
            pageNum = NAND_NUM_PAGES_PER_BLOCK - 1U;
        }

        Nand_gpmcStartPageWriteCmd(handle, blockNum, pageNum, columnAddr);

        badBlkMark[0] = NAND_BLK_BAD_MARK;
        Nand_gpmcWriteData(handle, badBlkMark, 2);

        status = Nand_gpmcEndPageWriteCmd(handle);
        if(NAND_PASS != status)
        {
            break;
        }
    }

    return status;
}

static NAND_STATUS Nand_gpmcErase(NAND_HANDLE handle, int32_t blockNum)
{
    NAND_Info       *nandGpmcInfo;
    GPMC_Handle      gpmcHandle;
    uint32_t         firstPageAddr;
    uint32_t         count;
    NAND_STATUS      status;

    if (!handle)
    {
        return NAND_INVALID_PARAM;
    }

    nandGpmcInfo = (NAND_Info *)handle;
    if (!nandGpmcInfo->hwHandle)
    {
        return NAND_FAIL;
    }
    gpmcHandle = (GPMC_Handle)nandGpmcInfo->hwHandle;

    if (blockNum >= NAND_NUM_BLOCKS)
    {
        return NAND_INVALID_PARAM;
    }

    if (Nand_gpmcBBlist[blockNum] == NAND_BAD_BLOCK)
    {
        return NAND_BLOCK_BAD;
    }

    Nand_gpmcSetCmd(gpmcHandle, NAND_CMD_ERASE);

    /* Calculate linear page number of the first page of the block. */
    firstPageAddr = blockNum * NAND_NUM_PAGES_PER_BLOCK;

    /* Write the Row address. */
    for(count = 0; count < NAND_NUM_BYTES_ROW_ADDR; count++)
    {
        Nand_gpmcSetAddr(gpmcHandle, (uint8_t)firstPageAddr);
        firstPageAddr = firstPageAddr >> 8U;
    }

    Nand_gpmcSetCmd(gpmcHandle, NAND_CMD_ERASE_CYC2);

    status = Nand_gpmcWaitPinStatus(gpmcHandle, NAND_TIMEOUT_VAL);
    if(NAND_PASS == status)
    {
        status = Nand_gpmcDeviceStatus(gpmcHandle);
    }

    if ((status != NAND_PASS) && (status != NAND_DEV_PROTECTED))
    {
		if (Nand_gpmcMarkBlockAsBad(gpmcHandle, blockNum) == NAND_PASS)
        {
            Nand_gpmcBBlist[blockNum] = NAND_BAD_BLOCK;
            return NAND_BLOCK_BAD;
        }
    }
    return (status);
}

