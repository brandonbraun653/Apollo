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

#include <ti/board/src/flash/nor/gpmc/nor_gpmc.h>

static NOR_HANDLE Nor_gpmcOpen(uint32_t norIntf, uint32_t portNum, void *params);
static void Nor_gpmcClose(NOR_HANDLE handle);
static NOR_STATUS Nor_gpmcRead(NOR_HANDLE handle, uint32_t addr,
                               uint32_t len, uint8_t *buf, uint32_t mode);
static NOR_STATUS Nor_gpmcWrite(NOR_HANDLE handle, uint32_t addr,
                                uint32_t len, uint8_t *buf, uint32_t mode);
static NOR_STATUS Nor_gpmcErase(NOR_HANDLE handle, int32_t block, bool blkErase);

/* NAND function table for NAND GPMC interface implementation */
const NOR_FxnTable Nor_gpmcFxnTable =
{
    &Nor_gpmcOpen,
    &Nor_gpmcClose,
    &Nor_gpmcRead,
    &Nor_gpmcWrite,
    &Nor_gpmcErase,
};

NOR_Info Nor_gpmcInfo =
{
    0,                          /* hwHandle */
    0,                          /* manufacturerId */
    0,                          /* deviceId */
    0,                          /* busWidth */
    NOR_NUM_BLOCKS,            /* blockCnt */
    NOR_NUM_PAGES_PER_BLOCK,   /* pageCnt */
    NOR_PAGE_SIZE,             /* pageSize */
    0,                         /* baseAddr */
    NOR_SECTOR_SIZE            /* sectorSize */
};

static volatile uint8_t *Nor_gpmcMakeAddr(NOR_HANDLE handle,
                                          uint32_t blkAddr,
                                          uint32_t offset)
{
    NOR_Info *norGpmcInfo = (NOR_Info *)handle;
    uint32_t addr;

    if (norGpmcInfo->busWidth == NOR_BUSWIDTH_8BITS)
    {
        addr = 	blkAddr + offset;
    }
    else
    {
        addr = 	blkAddr + (offset << 1);
    }

    return ((volatile uint8_t *) addr);
}

static void Nor_gpmcMakeCmd(NOR_HANDLE handle,
                            uint32_t cmd,
                            void *cmdbuf)
{
    NOR_Info *norGpmcInfo = (NOR_Info *)handle;
    uint32_t  i;
    uint8_t  *cp = (uint8_t *) cmdbuf;

    for (i = (1 << norGpmcInfo->busWidth); i > 0; i--)
    {
        *cp = (i & ((1 << norGpmcInfo->busWidth) - 1)) ? 0x00 : cmd;
        cp++;
    }
}

static void Nor_gpmcWriteCmd(NOR_HANDLE handle, uint32_t blkAddr,
                             uint32_t offset, uint32_t cmd)
{
    NOR_Info         *norGpmcInfo = (NOR_Info *)handle;
    volatile NOR_Ptr  addr;
    NOR_Data          cmdword;

    addr.cp = Nor_gpmcMakeAddr(handle, blkAddr, offset);
    Nor_gpmcMakeCmd(handle, cmd, &cmdword);
    if (norGpmcInfo->busWidth == NOR_BUSWIDTH_8BITS)
    {
        /* Bus width 8 bit */
        *addr.cp = cmdword.c;
    }
    else
    {
        /* Default Bus width 16 bit */
        *addr.wp = cmdword.w;
    }
}

static void Nor_gpmcPrefixCommands(NOR_HANDLE handle)
{
    NOR_Info         *norGpmcInfo = (NOR_Info *)handle;

    Nor_gpmcWriteCmd(handle, norGpmcInfo->baseAddr, NOR_CMD0_ADDR, NOR_CMD0);
    Nor_gpmcWriteCmd(handle, norGpmcInfo->baseAddr, NOR_CMD1_ADDR, NOR_CMD1);
}

static void Nor_gpmcWriteData(NOR_HANDLE handle, uint32_t address, uint32_t data)
{
    NOR_Info         *norGpmcInfo = (NOR_Info *)handle;
    volatile NOR_Ptr  pAddr;
    NOR_Data          dataword;

    dataword.l = data;
    pAddr.cp = (volatile uint8_t *)address;

    if (norGpmcInfo->busWidth == NOR_BUSWIDTH_8BITS)
    {
        /* Bus width 8 bit */
        *pAddr.cp = dataword.c;
    }
    else
    {
        /* Default Bus width 16 bit */
        *pAddr.wp = dataword.w;
    }
}

uint32_t Nor_gpmcReadData(NOR_HANDLE handle, uint32_t address,
                          uint32_t offset)
{
    NOR_Info        *norGpmcInfo = (NOR_Info *)handle;
    volatile NOR_Ptr pAddr;
    NOR_Data         dataword;

    dataword.l = 0x00000000;

    pAddr.cp = Nor_gpmcMakeAddr(handle, address, offset);

    if (norGpmcInfo->busWidth == NOR_BUSWIDTH_8BITS)
    {
        /* Bus width 8 bit */
        dataword.c = *pAddr.cp;
    }
    else
    {
        /* Default Bus width 16 bit */
        dataword.w = *pAddr.wp;
    }
    return dataword.l;
}

static void Nor_delay(uint32_t usec)
{
#if defined (evmAM335x)
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

static void Nor_gpmcSoftReset(NOR_HANDLE handle)
{
    NOR_Info    *norGpmcInfo = (NOR_Info *)handle;

    /* Reset Flash to be in Read Array Mode*/
    Nor_gpmcWriteCmd(handle, norGpmcInfo->baseAddr, NOR_CMD2_ADDR, NOR_CMD_RESET);
    Nor_delay(1);
}

static NOR_STATUS Nor_gpmcReadId(NOR_HANDLE handle)
{
    NOR_STATUS  retVal = NOR_FAIL;
    NOR_Info   *norGpmcInfo = (NOR_Info *)handle;
    uint32_t    manfID, devID;

    Nor_gpmcSoftReset(handle);

    /* Write read ID commands*/
    Nor_gpmcPrefixCommands(handle);
    Nor_gpmcWriteCmd(handle, norGpmcInfo->baseAddr, NOR_CMD2_ADDR,
                     NOR_CMD_RDID);

    /* Read manufacturer's and device ID */
    manfID = Nor_gpmcReadData(handle, norGpmcInfo->baseAddr, NOR_MANFID_ADDR);
    devID = Nor_gpmcReadData(handle, norGpmcInfo->baseAddr, NOR_DEVID_ADDR0);
    if ((manfID == NOR_MANF_ID) && (devID == NOR_DEVICE_ID))
    {
        Nor_gpmcInfo.manufacturerId = manfID;
        Nor_gpmcInfo.deviceId = devID;
        retVal = NOR_PASS;
    }

    /* Exit back to read array mode */
    Nor_gpmcSoftReset(handle);

    return (retVal);
}

NOR_HANDLE Nor_gpmcOpen(uint32_t norIntf, uint32_t portNum, void *params)
{
    GPMC_Params      gpmcParams;  /* GPMC params structure */
    GPMC_Handle      hwHandle;  /* GPMC handle */
    NOR_HANDLE       norHandle = 0;

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
    hwHandle = (GPMC_Handle)GPMC_open(portNum, &gpmcParams);

    if (hwHandle)
    {
		GPMC_control(hwHandle, GPMC_V1_CMD_GETDEVADDR, (void *)(&Nor_gpmcInfo.baseAddr));
		GPMC_control(hwHandle, GPMC_V1_CMD_GETDEVSIZE, (void *)(&Nor_gpmcInfo.busWidth));

        Nor_gpmcSoftReset((NOR_HANDLE)(&Nor_gpmcInfo));
        if (Nor_gpmcReadId((NOR_HANDLE)(&Nor_gpmcInfo)) == NOR_PASS)
        {
            Nor_gpmcInfo.hwHandle = (uint32_t)hwHandle;
            norHandle = (NOR_HANDLE)(&Nor_gpmcInfo);
        }
	}

    return (norHandle);
}

void Nor_gpmcClose(NOR_HANDLE handle)
{
    NOR_Info    *norGpmcInfo;
    GPMC_Handle  gpmcHandle;

    if (handle)
    {
        norGpmcInfo = (NOR_Info *)handle;
        gpmcHandle = (GPMC_Handle)norGpmcInfo->hwHandle;

        if (gpmcHandle)
        {
            GPMC_close(gpmcHandle);
        }
    }
}

static NOR_STATUS Nor_gpmcIsSetAll (NOR_HANDLE handle,
                                    uint32_t addr,
                                    uint8_t mask)
{
    NOR_Info        *norGpmcInfo = (NOR_Info *)handle;
    volatile NOR_Ptr address;
    NOR_Data         maskword;
    bool             retval = true;
    uint32_t         temp;

    maskword.l = 0x00000000;

    address.cp = Nor_gpmcMakeAddr(handle, addr, 0);
    temp = *address.wp;
    Nor_gpmcMakeCmd (handle, mask, &maskword);
    if (norGpmcInfo->busWidth == NOR_BUSWIDTH_8BITS)
    {
        temp = *address.cp;
        retval = ((maskword.c & temp) == maskword.c);
    }
    else
    {
        temp = *address.wp;
        retval = ((maskword.w & temp) == maskword.w);
    }
    return retval;
}

static NOR_STATUS Nor_gpmcWaitReady(NOR_HANDLE handle, uint32_t addr, uint32_t mask, uint32_t timeOut)
{
    NOR_STATUS      status = NOR_PASS;

    do
    {
        if (Nor_gpmcIsSetAll(handle, addr, mask))
        {
            break;
        }

        timeOut--;
        if (!timeOut) {
			status = NOR_TIMEOUT;
            break;
        }

    } while (1);

    return (status);
}

NOR_STATUS Nor_gpmcRead(NOR_HANDLE handle, uint32_t addr,
                        uint32_t len, uint8_t *buf, uint32_t mode)
{
    NOR_Info         *norGpmcInfo;
    GPMC_Transaction  transaction;
    GPMC_Handle       gpmcHandle;
    bool              ret;

    if ((!handle) || ((addr + len) > NOR_SIZE))
    {
        return NOR_INVALID_PARAM;
    }

    norGpmcInfo = (NOR_Info *)handle;
    if (!norGpmcInfo->hwHandle)
    {
        return NOR_FAIL;
    }
    gpmcHandle = (GPMC_Handle)norGpmcInfo->hwHandle;

    transaction.offset = addr;
    transaction.txBuf  = NULL;
    transaction.rxBuf  = (void *)buf;
    transaction.count  = len;

    ret = GPMC_transfer(gpmcHandle, &transaction);
    if (ret == true)
    {
        return NOR_PASS;
    }
	else
    {
        return NOR_FAIL;
    }
}

/* Write one byte (or one 16-bit word) data */
static NOR_STATUS Nor_gpmcWriteOne(NOR_HANDLE handle, uint32_t offsetAddr,
                                   uint32_t data)
{
    NOR_STATUS       status = NOR_PASS;
    NOR_Info        *norGpmcInfo = (NOR_Info *)handle;
    uint32_t         flag   = 0;
    uint32_t         address = norGpmcInfo->baseAddr + offsetAddr;

    /* Send Commands*/
    Nor_gpmcPrefixCommands(handle);
    Nor_gpmcWriteCmd(handle, norGpmcInfo->baseAddr,
                     NOR_CMD2_ADDR, NOR_CMD_PROG);
    Nor_gpmcWriteData(handle, address, data);

    /* Wait for ready.*/
    while (1)
    {
        if ((Nor_gpmcReadData(handle, address, 0) &
             (BIT7 | BIT15)) == (data & (BIT7 | BIT15)))
        {
            flag = 1U;
        }
        else
        {
            if (Nor_gpmcWaitReady(handle, address, BIT5, NOR_WRITE_TIMEOUT) == NOR_PASS)
            {
                if ((Nor_gpmcReadData(handle, address, 0) &
                     (BIT7 | BIT15)) != (data & (BIT7 | BIT15)))
                {
                    status = NOR_FAIL;
                }
                flag = 1U;
            }
        }

        if (flag == 1U)
        {
            break;
        }
    }

    /* Return Read Mode*/
    Nor_gpmcSoftReset(handle);

    return (status);
}

NOR_STATUS Nor_gpmcWrite(NOR_HANDLE handle, uint32_t addr, uint32_t len,
                         uint8_t *buf, uint32_t mode)
{
    NOR_Info        *norGpmcInfo;
    uint8_t         *bufPt8 = buf;
    uint16_t        *bufPt16 = (uint16_t *)buf;
    uint32_t         i;
    uint32_t         offsetAddr = addr;

    if ((!handle) || ((addr + len) > NOR_SIZE))
    {
        return NOR_INVALID_PARAM;
    }

    norGpmcInfo = (NOR_Info *)handle;
    if (!norGpmcInfo->hwHandle)
    {
        return NOR_FAIL;
    }

    if (norGpmcInfo->busWidth == NOR_BUSWIDTH_8BITS)
    {
        for (i = 0; i < len; i++)
        {
			if (Nor_gpmcWriteOne(handle, offsetAddr, (uint32_t)(*bufPt8)) !=
			    NOR_PASS)
            {
                return NOR_FAIL;
            }
            bufPt8++;
            offsetAddr++;
        }
    }
    else
    {
        for (i = 0; i < len/2; i++)
        {
			if (Nor_gpmcWriteOne(handle, offsetAddr, (uint32_t)(*bufPt16)) !=
			    NOR_PASS)
            {
                return NOR_FAIL;
            }
            bufPt16++;
            offsetAddr += 2;
        }
    }

    return NOR_PASS;
}

NOR_STATUS Nor_gpmcErase(NOR_HANDLE handle, int32_t sector, bool blkErase)
{
    NOR_STATUS      status = NOR_PASS;
    NOR_Info       *norGpmcInfo;
    uint32_t        sectorAddr;
    uint32_t        timeOut;

    if ((!handle) || (sector >= NOR_NUM_SECTORS))
    {
        return NOR_INVALID_PARAM;
    }

    norGpmcInfo = (NOR_Info *)handle;
    if (!norGpmcInfo->hwHandle)
    {
        return NOR_FAIL;
    }

    Nor_gpmcPrefixCommands(handle);
    Nor_gpmcWriteCmd(handle, norGpmcInfo->baseAddr, NOR_CMD2_ADDR, NOR_CMD_BLK_ERASE_SETUP);
    Nor_gpmcPrefixCommands(handle);

    /* Send commands */
    if (sector == NOR_BE_SECTOR_NUM)
    {
        sectorAddr = 0;
        timeOut = NOR_BULK_ERASE_TIMEOUT;
        Nor_gpmcWriteCmd(handle, NOR_CMD0_ADDR, 0x0, NOR_CMD_BULK_ERASE);
    }
    else
    {
        sectorAddr = norGpmcInfo->baseAddr + sector * NOR_SECTOR_SIZE;
        timeOut = NOR_SECTOR_ERASE_TIMEOUT;
        Nor_gpmcWriteCmd(handle, sectorAddr, 0x0, NOR_CMD_BLK_ERASE);
    }

    status = Nor_gpmcWaitReady(handle, sectorAddr, BIT7, timeOut);

    /* Flash Mode: Read Array*/
    Nor_gpmcSoftReset(handle);

    return (status);
}
