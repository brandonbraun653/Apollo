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

#include "board_utils.h"
#include <ti/board/src/flash/nor/qspi/nor_qspi.h>
#include <ti/csl/soc.h>

#define SPI_CONFIG_OFFSET     CSL_SPI_CNT

static NOR_HANDLE Nor_qspiOpen(uint32_t norIntf, uint32_t portNum, void *params);
static void Nor_qspiClose(NOR_HANDLE handle);
static NOR_STATUS Nor_qspiRead(NOR_HANDLE handle, uint32_t addr,
                               uint32_t len, uint8_t *buf, uint32_t mode);
static NOR_STATUS Nor_qspiWrite(NOR_HANDLE handle, uint32_t addr,
                                uint32_t len, uint8_t *buf, uint32_t mode);
static NOR_STATUS Nor_qspiErase(NOR_HANDLE handle, int32_t erLoc, bool blkErase);

/* NOR function table for NOR QSPI interface implementation */
const NOR_FxnTable Nor_qspiFxnTable =
{
    &Nor_qspiOpen,
    &Nor_qspiClose,
    &Nor_qspiRead,
    &Nor_qspiWrite,
    &Nor_qspiErase,
};

NOR_Info Nor_qspiInfo =
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

static NOR_STATUS NOR_qspiCmdRead(SPI_Handle handle, uint8_t *cmdBuf,
                            uint32_t cmdLen, uint8_t *rxBuf, uint32_t rxLen)
{
    SPI_Transaction  transaction;
    uint32_t         transferType = SPI_TRANSACTION_TYPE_READ;
    bool             ret;

    /* Update the mode and transfer type with the required values */
    SPI_control(handle, SPI_V0_CMD_SETCONFIGMODE, NULL);
    SPI_control(handle, SPI_V0_CMD_TRANSFERMODE_RW, (void *)&transferType);

    transaction.txBuf = (void *)cmdBuf;
    transaction.rxBuf = (void *)rxBuf;
    transaction.count = cmdLen + rxLen;

    ret = SPI_transfer(handle, &transaction);
    if (ret == true)
    {
        return NOR_PASS;
    }
	else
    {
        return NOR_FAIL;
    }
}

static NOR_STATUS Nor_qspiReadId(SPI_Handle handle)
{
    NOR_STATUS  retVal;
    uint8_t     idCode[NOR_RDID_NUM_BYTES];
    uint8_t     cmd = NOR_CMD_RDID;
    uint32_t    manfID, devID;

    retVal = NOR_qspiCmdRead(handle, &cmd, 1, idCode, NOR_RDID_NUM_BYTES);
    if (retVal == NOR_PASS)
    {
        manfID = (uint32_t)idCode[0];
        devID = ((uint32_t)idCode[1] << 8) | ((uint32_t)idCode[2]);
        if ((manfID == NOR_MANF_ID) && (devID == NOR_DEVICE_ID))
        {
            Nor_qspiInfo.manufacturerId = manfID;
            Nor_qspiInfo.deviceId = devID;
        }
        else
        {
            retVal = NOR_FAIL;
        }
    }

    return (retVal);
}

NOR_HANDLE Nor_qspiOpen(uint32_t norIntf, uint32_t portNum, void *params)
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
    hwHandle = (SPI_Handle)SPI_open(portNum + SPI_CONFIG_OFFSET, &spiParams);

    if (hwHandle)
    {
        if (Nor_qspiReadId(hwHandle) == NOR_PASS)
        {
            Nor_qspiInfo.hwHandle = (uint32_t)hwHandle;
            norHandle = (NOR_HANDLE)(&Nor_qspiInfo);
        }
	}

    return (norHandle);
}

void Nor_qspiClose(NOR_HANDLE handle)
{
    NOR_Info    *norQspiInfo;
    SPI_Handle   spiHandle;

    if (handle)
    {
        norQspiInfo = (NOR_Info *)handle;
        spiHandle = (SPI_Handle)norQspiInfo->hwHandle;

        if (spiHandle)
        {
            SPI_close(spiHandle);
        }
    }
}

static NOR_STATUS Nor_qspiCmdWrite(SPI_Handle handle, uint8_t *cmdBuf,
                                        uint32_t cmdLen, uint32_t dataLen)
{
    SPI_Transaction  transaction;
    uint32_t         transferType = SPI_TRANSACTION_TYPE_WRITE;
    bool             ret;

    /* Update the mode and transfer type with the required values */
    SPI_control(handle, SPI_V0_CMD_SETCONFIGMODE, NULL);
    SPI_control(handle, SPI_V0_CMD_TRANSFERMODE_RW, (void *)&transferType);

    transaction.txBuf = (void *)cmdBuf; /* Buffer includes command and write data */
    transaction.count = cmdLen + dataLen;
    transaction.rxBuf = NULL;
    transaction.arg = (void *)dataLen;

    ret = SPI_transfer(handle, &transaction);
    if (ret == true)
    {
        return NOR_PASS;
    }
	else
    {
        return NOR_FAIL;
    }
}

static NOR_STATUS Nor_qspiWaitReady(SPI_Handle handle, uint32_t timeOut)
{
    uint8_t         status;
    uint8_t         cmd = NOR_CMD_RDSR;

    do
    {
        if (NOR_qspiCmdRead(handle, &cmd, 1, &status, 1))
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

static NOR_STATUS Nor_qspiQuadModeCtrl(SPI_Handle handle,
                                       uint8_t enable)
{
    uint8_t status;
    uint8_t cmd[3];

    /* Write enable command */
    cmd[0] = NOR_CMD_WREN;
    if (Nor_qspiCmdWrite(handle, cmd, 1, 0))
    {
        goto err;
    }

    /* Read status register */
    cmd[0] = NOR_CMD_RDSR;
    status = 0;
    if (NOR_qspiCmdRead(handle, cmd, 1, &status, 1))
    {
        goto err;
    }

    cmd[0] = NOR_CMD_WRR;
    cmd[1] = status;

    /* The first byte will be written to the status register, while the
       second byte will be written to the configuration register */
    if (enable)
    {
        /* Write enabled, quad enabled, no protected blocks */
        cmd[2] = 0x02;
    }
    else
    {
        /* Write enabled, quad disabled, no protected block */
        cmd[2] = 0x0;
    }

    if (Nor_qspiCmdWrite(handle, cmd, 1, 2)) /* 1 byte command and 2 bytes write data */
    {
        goto err;
    }

    if (Nor_qspiWaitReady(handle, NOR_WRR_WRITE_TIMEOUT))
    {
        goto err;
    }

    cmd[0] = NOR_CMD_RDCR;
    status = 0;
    if (NOR_qspiCmdRead(handle, cmd, 1, &status, 1))
    {
        goto err;
    }

    if (status != cmd[2])
    {
        goto err;
    }

    return NOR_PASS;

err :
    return NOR_FAIL;
}

static SPI_Transaction transaction;
NOR_STATUS Nor_qspiRead(NOR_HANDLE handle, uint32_t addr,
                        uint32_t len, uint8_t *buf, uint32_t mode)
{
    NOR_Info        *norQspiInfo;
    uint32_t         command;
    uint32_t         dummyCycles;
    uint32_t         rx_lines;
    SPI_Handle       spiHandle;
    bool             ret;

    if (!handle)
    {
        return NOR_FAIL;
    }

    norQspiInfo = (NOR_Info *)handle;
    if (!norQspiInfo->hwHandle)
    {
        return NOR_FAIL;
    }
    spiHandle = (SPI_Handle)norQspiInfo->hwHandle;

    /* Validate address input */
    if ((addr + len) > NOR_SIZE)
    {
        return NOR_FAIL;
    }

    /* To set or unset the QUAD bit in CR1 register */
    if (mode != QSPI_FLASH_SINGLE_READ)
    {
        if (Nor_qspiQuadModeCtrl(spiHandle, 1))
        {
            return NOR_FAIL;
        }
    }
    else
    {
        if (Nor_qspiQuadModeCtrl(spiHandle, 0))
        {
            return NOR_FAIL;
        }
    }

    switch(mode)
    {
        case QSPI_FLASH_SINGLE_READ :
            command     = NOR_CMD_READ;
            dummyCycles = NOR_SINGLE_READ_DUMMY_CYCLE;
            rx_lines    = QSPI_XFER_LINES_SINGLE;
            break;
        case QSPI_FLASH_DUAL_READ :
            command     = NOR_CMD_DUAL_READ;
            dummyCycles = NOR_DUAL_READ_DUMMY_CYCLE;
            rx_lines    = QSPI_XFER_LINES_DUAL;
            break;
        case QSPI_FLASH_QUAD_READ :
            command     = NOR_CMD_QUAD_READ;
            dummyCycles = NOR_QUAD_READ_DUMMY_CYCLE;
            rx_lines    = QSPI_XFER_LINES_QUAD;
            break;
        default :
            command     = NOR_CMD_READ;
            dummyCycles = NOR_SINGLE_READ_DUMMY_CYCLE;
            rx_lines    = QSPI_XFER_LINES_SINGLE;
            break;
    }

    /* Update the indirect read command, rx lines and read dummy cycles */
    SPI_control(spiHandle, SPI_V0_CMD_SETINDXFERMODE, NULL);
    SPI_control(spiHandle, SPI_V0_CMD_IND_TRANSFER_CMD, (void *)&command);
    SPI_control(spiHandle, SPI_V0_CMD_SETXFERLINES, (void *)&rx_lines);
    SPI_control(spiHandle, SPI_V0_CMD_RD_DUMMY_CLKS, (void *)&dummyCycles);

    transaction.arg   = (void *)addr;
    transaction.txBuf = NULL;
    transaction.rxBuf = (void *)buf;
    transaction.count = len;

    ret = SPI_transfer(spiHandle, &transaction);
    if (ret == true)
    {
        return NOR_PASS;
    }
	else
    {
        return NOR_FAIL;
    }
}

NOR_STATUS Nor_qspiWrite(NOR_HANDLE handle, uint32_t addr, uint32_t len,
                         uint8_t *buf, uint32_t mode)
{
    NOR_Info        *norQspiInfo;
    SPI_Handle       spiHandle;
    uint32_t         command;
    uint32_t         tx_lines;
    bool             ret;
    uint32_t         byteAddr;
    uint32_t         pageSize;
    uint32_t         chunkLen;
    uint32_t         actual;
    uint8_t          cmdWren = NOR_CMD_WREN;

    if (!handle)
    {
        return NOR_FAIL;
    }

    norQspiInfo = (NOR_Info *)handle;
    if (!norQspiInfo->hwHandle)
    {
        return NOR_FAIL;
    }
    spiHandle = (SPI_Handle)norQspiInfo->hwHandle;

    /* Validate address input */
    if ((addr + len) > NOR_SIZE)
    {
        return NOR_FAIL;
    }

    if (mode == QSPI_FLASH_QUAD_PAGE_PROG)
    {
        if (Nor_qspiQuadModeCtrl(spiHandle, 1))
        {
            return NOR_FAIL;
        }
    }
    else
    {
        if (Nor_qspiQuadModeCtrl(spiHandle, 0))
        {
            return NOR_FAIL;
        }
    }

    switch(mode)
    {
        case QSPI_FLASH_SINGLE_PAGE_PROG :
            command = NOR_CMD_PAGE_PROG;
            tx_lines = QSPI_XFER_LINES_SINGLE;
            break;
        case QSPI_FLASH_QUAD_PAGE_PROG:
            command = NOR_CMD_QUAD_PAGE_PROG;
            tx_lines = QSPI_XFER_LINES_QUAD;
            break;
        default :
            command = NOR_CMD_PAGE_PROG;
            tx_lines = QSPI_XFER_LINES_SINGLE;
            break;
    }

    /* The QSPI Flash Controller will automatically issue
       the WREN command before triggering a write command via the direct or
       indirect access controllers (DAC/INDAC) – i.e the user does not need
       to perform this operation.
    */
    pageSize    = NOR_PAGE_SIZE;
    byteAddr    = addr & (NOR_PAGE_SIZE - 1); /* % page_size; */

    for (actual = 0; actual < len; actual += chunkLen)
    {
        /* Send Write Enable command */
        if (Nor_qspiCmdWrite(spiHandle, &cmdWren, 1, 0))
        {
            return NOR_FAIL;
        }

        /* Update the indirect write command and tx lines */
        SPI_control(spiHandle, SPI_V0_CMD_SETINDXFERMODE, NULL);
        SPI_control(spiHandle, SPI_V0_CMD_IND_TRANSFER_CMD, (void *)&command);
        SPI_control(spiHandle, SPI_V0_CMD_SETXFERLINES, (void *)&tx_lines);

        /* Send Page Program command */
        chunkLen = ((len - actual) < (pageSize - byteAddr) ?
                (len - actual) : (pageSize - byteAddr));

        transaction.arg   = (void *)addr;
        transaction.txBuf = (void *)(buf + actual);
        transaction.rxBuf = NULL;
        transaction.count = chunkLen;

        ret = SPI_transfer(spiHandle, &transaction);
        if (ret == false)
        {
            return NOR_FAIL;
        }

        if (Nor_qspiWaitReady(spiHandle, NOR_PAGE_PROG_TIMEOUT)) {
            return NOR_FAIL;
        }

        addr += chunkLen;
        byteAddr = 0;

        BOARD_delay(10);
    }

    return NOR_PASS;
}

NOR_STATUS Nor_qspiErase(NOR_HANDLE handle, int32_t erLoc, bool blkErase)
{
    uint8_t         cmd[5];
    uint32_t        cmdLen;
    uint32_t        address = 0;
    uint8_t         cmdWren  = NOR_CMD_WREN;
    NOR_Info       *norQspiInfo;
    SPI_Handle      spiHandle;
#if defined (iceK2G)
    uint8_t highAddress = 1;
    uint32_t  offset;
    uint8_t status = 0;
#endif

    if (!handle)
    {
        return NOR_FAIL;
    }

    norQspiInfo = (NOR_Info *)handle;
    if (!norQspiInfo->hwHandle)
    {
        return NOR_FAIL;
    }
    spiHandle = (SPI_Handle)norQspiInfo->hwHandle;
#if defined (iceK2G)
    /* Computes Hybrid Sector Size for S25FL256S flash device */
    if (blkErase == false)
    {
        cmd[0] = NOR_CMD_RDCR;
        status = 0;
        /* Read the TBPARM bit */
        if (NOR_qspiCmdRead(spiHandle, cmd, 1, &status, 1))
        {
            return NOR_FAIL;
        }
        if ((status & NOR_CR_TBPARM) == 1)
        {
            highAddress = 1; /* physical sectors at top */
        }
        else
        {
            highAddress = 0; /* physical sectors at bottom */
        }
        offset = erLoc * NOR_SECTOR_SIZE;
        if (highAddress == 0)
        {
            if (offset >= (NOR_NUM_4KSECTORS * NOR_SECTOR_SIZE))
            {
                blkErase = true;
                /* Re-calculate the erase location with the updated sector size */
                erLoc = offset / NOR_HYBRID_SECTOR_SIZE;
            }
            else
            {
                blkErase = false;
            }
        }
        else
        {
            if (offset < (NOR_HYBRID_SECTOR_SIZE * (NOR_NUM_SECTORS - NOR_NUM_4KSECTORS)))
            {
                blkErase = true;
                /* Re-calculate the erase location with the updated sector size */
                erLoc = offset / NOR_HYBRID_SECTOR_SIZE;
            }
            else
            {
                blkErase = false;
            }
        }
    }
#endif
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
#if defined (iceK2G)
                if (highAddress == 1)
#endif
                    return NOR_FAIL;
            }
            address   = erLoc * NOR_BLOCK_SIZE;
            cmd[0] = NOR_CMD_BLOCK_ERASE;
        }
        else
        {
            if (erLoc >= NOR_NUM_SECTORS)
            {
                return NOR_FAIL;
            }
            address   = erLoc * NOR_SECTOR_SIZE;
            cmd[0] = NOR_CMD_SECTOR_ERASE;
        }
        cmd[1] = (address >> 16) & 0xff; /* 64MB flash device */
        cmd[2] = (address >>  8) & 0xff;
        cmd[3] = (address >>  0) & 0xff;

        cmdLen = 4;
    }

    if (Nor_qspiCmdWrite(spiHandle, &cmdWren, 1, 0))
    {
    	return NOR_FAIL;
    }

    if (Nor_qspiWaitReady(spiHandle, NOR_WRR_WRITE_TIMEOUT))
    {
    	return NOR_FAIL;
    }

    if (Nor_qspiCmdWrite(spiHandle, cmd, cmdLen, 0))
    {
    	return NOR_FAIL;
    }

    if (Nor_qspiWaitReady(spiHandle, NOR_BULK_ERASE_TIMEOUT))
    {
    	return NOR_FAIL;
    }

    return NOR_PASS;
}
