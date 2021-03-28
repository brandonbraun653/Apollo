/**
 *  \file   nor_spi.c
 *
 *  \brief  SPI NOR Flash specific driver implementation.
 *
 */

/*
 * Copyright (C) 2015 - 2019 Texas Instruments Incorporated - http://www.ti.com/
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the
 * distribution.
 *
 * Neither the name of Texas Instruments Incorporated nor the names of
 * its contributors may be used to endorse or promote products derived
 * from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#if !(defined(evmOMAPL137) || defined(am65xx_evm) || defined(am65xx_idk) || defined(j721e_sim) || defined(j721e_evm))
#include "board_utils.h"
#endif
#include <ti/board/src/flash/nor/spi/nor_spi.h>

static NOR_HANDLE Nor_spiOpen(uint32_t norIntf, uint32_t portNum, void *params);
static void Nor_spiClose(NOR_HANDLE handle);
static NOR_STATUS Nor_spiRead(NOR_HANDLE handle, uint32_t addr,
                              uint32_t len, uint8_t *buf, uint32_t mode);
static NOR_STATUS Nor_spiWrite(NOR_HANDLE handle, uint32_t addr,
                               uint32_t len, uint8_t *buf, uint32_t mode);
static NOR_STATUS Nor_spiErase(NOR_HANDLE handle, int32_t eraseCnt, bool blkErase);

/* NOR function table for NOR SPI interface implementation */
const NOR_FxnTable Nor_spiFxnTable =
{
    &Nor_spiOpen,
    &Nor_spiClose,
    &Nor_spiRead,
    &Nor_spiWrite,
    &Nor_spiErase,
};

NOR_Info Nor_spiInfo =
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

static SPI_Transaction transaction;     /* SPI transaction structure */
static NOR_STATUS Nor_spiCmdRead(SPI_Handle handle,
                                 uint8_t *cmdBuf,
                                 uint32_t cmdLen,
                                 uint8_t *rxBuf,
                                 uint32_t rxLen)
{
    uint32_t        xferEnable;
    uint32_t        terminateXfer = 0;
    bool            retVal;

    /* Enable transfer */
    xferEnable = 1;
    SPI_control(handle, SPI_V0_CMD_XFER_ACTIVATE, (void *)&xferEnable);

    /* If no read data, release CS at the end of write */
    if (rxLen == 0)
    {
        terminateXfer = 1;
    }

    /* Write Command */
    transaction.txBuf = cmdBuf;
    transaction.rxBuf = NULL;
    transaction.count = cmdLen;
    transaction.arg = (void *)&terminateXfer;

    retVal = SPI_transfer(handle, &transaction);

    if (retVal == false)
    {
        return NOR_FAIL;
    }

    /* Receive the data */
    if (rxLen)
    {
        /* Read Device ID */
        transaction.txBuf = NULL;
        transaction.rxBuf = rxBuf;
        transaction.count = rxLen;
        terminateXfer = 1;
        transaction.arg = (void *)&terminateXfer;

        retVal = SPI_transfer(handle, &transaction);
    }

    /* Disable transfer */
    xferEnable = 0;
    SPI_control(handle, SPI_V0_CMD_XFER_ACTIVATE, (void *)&xferEnable);

    if (retVal == true)
    {
        return NOR_PASS;
    }
    else
    {
        return NOR_FAIL;
    }
}

static NOR_STATUS Nor_spiReadId(SPI_Handle handle)
{
    NOR_STATUS  retVal;
    uint8_t     idCode[NOR_RDID_NUM_BYTES];
    uint8_t     cmd = NOR_CMD_RDID;
    uint32_t    manfID, devID;

    retVal = Nor_spiCmdRead(handle, &cmd, 1, idCode, NOR_RDID_NUM_BYTES);
    if (retVal == NOR_PASS)
    {
        manfID = (uint32_t)idCode[0];
        devID = ((uint32_t)idCode[1] << 8) | ((uint32_t)idCode[2]);
        if ((manfID == NOR_MANF_ID) && (devID == NOR_DEVICE_ID))
        {
            Nor_spiInfo.manufacturerId = manfID;
            Nor_spiInfo.deviceId = devID;
        }
        else
        {
            retVal = NOR_FAIL;
        }
    }

    return (retVal);
}

NOR_HANDLE Nor_spiOpen(uint32_t norIntf, uint32_t portNum, void *params)
{
    SPI_Params      spiParams;  /* SPI params structure */
    SPI_Handle      hwHandle;  /* SPI handle */
    NOR_HANDLE      norHandle = 0;

    /* Init SPI driver */
    SPI_init();

    if (params)
    {
		memcpy(&spiParams, params, sizeof(SPI_Params));
    }
    else
    {
        /* Use default SPI config params if no params provided */
		SPI_Params_init(&spiParams);
    }
    hwHandle = (SPI_Handle)SPI_open(portNum, &spiParams);

    if (hwHandle)
    {
        if (Nor_spiReadId(hwHandle) == NOR_PASS)
        {
            Nor_spiInfo.hwHandle = (uintptr_t)hwHandle;
            norHandle = (NOR_HANDLE)(&Nor_spiInfo);
        }
	}

    return (norHandle);
}

void Nor_spiClose(NOR_HANDLE handle)
{
    NOR_Info    *norSpiInfo;
    SPI_Handle   spiHandle;

    if (handle)
    {
        norSpiInfo = (NOR_Info *)handle;
        spiHandle = (SPI_Handle)norSpiInfo->hwHandle;

        if (spiHandle)
        {
            SPI_close(spiHandle);
        }
    }
}

NOR_STATUS Nor_spiRead(NOR_HANDLE handle, uint32_t addr,
                       uint32_t len, uint8_t *buf, uint32_t mode)
{
    NOR_Info        *norSpiInfo;
    uint8_t          cmd[4];
    SPI_Handle       spiHandle;

    if (!handle)
    {
        return NOR_FAIL;
    }

    norSpiInfo = (NOR_Info *)handle;
    if (!norSpiInfo->hwHandle)
    {
        return NOR_FAIL;
    }
    spiHandle = (SPI_Handle)norSpiInfo->hwHandle;

    /* Validate address input */
    if ((addr + len) > NOR_SIZE)
    {
        return NOR_FAIL;
    }

    cmd[0] = NOR_CMD_READ;
    cmd[1] = (uint8_t)(addr >> 16);
    cmd[2] = (uint8_t)(addr >> 8);
    cmd[3] = (uint8_t)(addr);

    return (Nor_spiCmdRead(spiHandle, cmd, 4, buf, len));
}

static NOR_STATUS Nor_spiWaitReady(SPI_Handle handle, uint32_t timeOut)
{
    uint8_t         status;
    uint8_t         cmd = NOR_CMD_RDSR;

    do
    {
        if (Nor_spiCmdRead(handle, &cmd, 1, &status, 1))
        {
            return NOR_FAIL;
        }
        if ((status & NOR_SR_WIP) == 0)
        {
            break;
        }

        timeOut--;
        if (!timeOut) {
            break;
        }

    } while (1);

    if ((status & NOR_SR_WIP) == 0)
    {
        return NOR_PASS;
    }

    /* Timed out */
    return NOR_FAIL;
}

static NOR_STATUS Nor_spiCmdWrite(SPI_Handle handle,
                                  uint8_t   *cmd,
                                  uint32_t   cmdLen,
                                  uint8_t   *txBuf,
                                  uint32_t   txlen)
{
    uint32_t        xferEnable;
    uint32_t        terminateXfer = 0;
    bool            retVal;

    /* Enable transfer */
    xferEnable = 1;
    SPI_control(handle, SPI_V0_CMD_XFER_ACTIVATE, (void *)&xferEnable);

    /* If no read data, release CS at the end of write */
    if (txlen == 0)
    {
        terminateXfer = 1;
    }

    /* Write Command */
    transaction.txBuf = cmd;
    transaction.rxBuf = NULL;
    transaction.count = cmdLen;
    transaction.arg = (void *)&terminateXfer;

    retVal = SPI_transfer(handle, &transaction);

    if (retVal == false)
    {
        return NOR_FAIL;
    }

    /* write data */
    if (txlen)
    {
        /* Write data */
        transaction.txBuf = txBuf;
        transaction.rxBuf = NULL;
        transaction.count = txlen;
        terminateXfer = 1;
        transaction.arg = (void *)&terminateXfer;

        retVal = SPI_transfer(handle, &transaction);
    }

    /* Disable transfer */
    xferEnable = 0;
    SPI_control(handle, SPI_V0_CMD_XFER_ACTIVATE, (void *)&xferEnable);
    if (retVal == true)
    {
        return NOR_PASS;
    }
    else
    {
        return NOR_FAIL;
    }
}

NOR_STATUS Nor_spiWrite(NOR_HANDLE handle, uint32_t addr, uint32_t len,
                         uint8_t *buf, uint32_t mode)
{
    NOR_Info        *norSpiInfo;
    SPI_Handle       spiHandle;
    uint8_t          cmd[4];
    uint32_t         byteAddr;
    uint32_t         pageSize;
    uint32_t         chunkLen;
    uint32_t         actual;
    uint8_t          cmdWren = NOR_CMD_WREN;

    if (!handle)
    {
        return NOR_FAIL;
    }

    norSpiInfo = (NOR_Info *)handle;
    if (!norSpiInfo->hwHandle)
    {
        return NOR_FAIL;
    }
    spiHandle = (SPI_Handle)norSpiInfo->hwHandle;

    /* Validate address input */
    if ((addr + len) > NOR_SIZE)
    {
        return NOR_FAIL;
    }

    cmd[0]      = NOR_CMD_PAGE_PROG;
    pageSize    = NOR_PAGE_SIZE;
    byteAddr    = addr & (NOR_PAGE_SIZE - 1); /* % page_size; */

    for (actual = 0; actual < len; actual += chunkLen)
    {
        /* Send Write Enable command */
        if (Nor_spiCmdRead(spiHandle, &cmdWren, 1, NULL, 0) == NOR_FAIL)
        {
            return NOR_FAIL;
        }

        /* Send Page Program command */
        chunkLen = ((len - actual) < (pageSize - byteAddr) ?
                (len - actual) : (pageSize - byteAddr));

        cmd[1]  = (uint8_t)(addr >> 16);
        cmd[2]  = (uint8_t)(addr >> 8);
        cmd[3]  = (uint8_t)(addr);

        if (Nor_spiCmdWrite(spiHandle, cmd, 4, buf + actual, chunkLen) == NOR_FAIL)
        {
            return NOR_FAIL;
        }

        if (Nor_spiWaitReady(spiHandle, NOR_PAGE_PROG_TIMEOUT)) {
            return NOR_FAIL;
        }

        addr += chunkLen;
        byteAddr = 0;

#if !(defined(evmOMAPL137) || defined(am65xx_evm) || defined(am65xx_idk) || defined(j721e_sim) || defined(j721e_evm))
        BOARD_delay(10);
#endif
    }

    return NOR_PASS;
}

NOR_STATUS Nor_spiErase(NOR_HANDLE handle, int32_t erLoc, bool blkErase)
{
    uint8_t         cmd[4];
    uint32_t        cmdLen;
    uint32_t        addr = 0;
    uint8_t         cmdWren  = NOR_CMD_WREN;
    NOR_Info       *norSpiInfo;
    SPI_Handle      spiHandle;

    if (!handle)
    {
        return NOR_FAIL;
    }

    norSpiInfo = (NOR_Info *)handle;
    if (!norSpiInfo->hwHandle)
    {
        return NOR_FAIL;
    }
    spiHandle = (SPI_Handle)norSpiInfo->hwHandle;

    if (erLoc == NOR_BE_SECTOR_NUM)
    {
        cmd[0]  = NOR_CMD_BULK_ERASE;
        cmdLen = 1;
    }
    else
    {
		if (blkErase == true)
		{
            if (erLoc >= NOR_NUM_BLOCKS)
            {
                return NOR_FAIL;
            }
			addr   = erLoc * NOR_BLOCK_SIZE;
            cmd[0] = NOR_CMD_BLOCK_ERASE;
        }
        else
        {
            if (erLoc >= NOR_NUM_SECTORS)
            {
                return NOR_FAIL;
            }
            addr   = erLoc * NOR_SECTOR_SIZE;
            cmd[0] = NOR_CMD_SECTOR_ERASE;
        }
        cmd[1] = (uint8_t)(addr >> 16);
        cmd[2] = (uint8_t)(addr >> 8);
        cmd[3] = (uint8_t)(addr);
        cmdLen = 4;
    }

    /* Send Write Enable command */
    if (Nor_spiCmdRead(spiHandle, &cmdWren, 1, NULL, 0) == NOR_FAIL)
    {
        return NOR_FAIL;
    }

    /* Send erase command */
    if (Nor_spiCmdRead(spiHandle, cmd, cmdLen, NULL, 0) == NOR_FAIL)
    {
    	return NOR_FAIL;
    }

    return (Nor_spiWaitReady(spiHandle, NOR_BULK_ERASE_TIMEOUT));
}
