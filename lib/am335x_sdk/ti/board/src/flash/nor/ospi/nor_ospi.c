/*
 * Copyright (c) 2018 - 2020, Texas Instruments Incorporated
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

//#include "board_utils.h"
#include <ti/board/src/flash/nor/ospi/nor_ospi.h>
#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/csl/soc.h>

#if defined (j7200_evm)
/* SPI entry offset is at index 5 of SPI config array */
#define SPI_CONFIG_OFFSET     (5U)
#else
#define SPI_CONFIG_OFFSET     CSL_MCSPI_PER_CNT
#endif

static NOR_HANDLE Nor_ospiOpen(uint32_t norIntf, uint32_t portNum, void *params);
static void Nor_ospiClose(NOR_HANDLE handle);
static NOR_STATUS Nor_ospiRead(NOR_HANDLE handle, uint32_t addr,
                               uint32_t len, uint8_t *buf, uint32_t mode);
static NOR_STATUS Nor_ospiWrite(NOR_HANDLE handle, uint32_t addr,
                                uint32_t len, uint8_t *buf, uint32_t mode);
static NOR_STATUS Nor_ospiErase(NOR_HANDLE handle, int32_t eraseCnt, bool blkErase);

static NOR_STATUS Nor_ospiCmdWrite(SPI_Handle handle, uint8_t *cmdBuf,
                                   uint32_t cmdLen, uint32_t dataLen);

/* NOR function table for NOR OSPI interface implementation */
const NOR_FxnTable Nor_ospiFxnTable =
{
    &Nor_ospiOpen,
    &Nor_ospiClose,
    &Nor_ospiRead,
    &Nor_ospiWrite,
    &Nor_ospiErase,
};

NOR_Info Nor_ospiInfo =
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

static NOR_STATUS NOR_ospiCmdRead(SPI_Handle handle, uint8_t *cmdBuf,
                            uint32_t cmdLen, uint8_t *rxBuf, uint32_t rxLen)
{
    SPI_Transaction  transaction;
    uint32_t         transferType = SPI_TRANSACTION_TYPE_READ;
    bool             ret;

    /* Update the mode and transfer type with the required values */
    SPI_control(handle, SPI_V0_CMD_SET_CFG_MODE, NULL);
    SPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);

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

static NOR_STATUS Nor_ospiReadId(SPI_Handle handle)
{
    NOR_STATUS  retVal;
    uint8_t     idCode[NOR_RDID_NUM_BYTES];
    uint8_t     cmd = NOR_CMD_RDID;
    uint32_t    manfID, devID;

    retVal = NOR_ospiCmdRead(handle, &cmd, 1, idCode, NOR_RDID_NUM_BYTES);
    if (retVal == NOR_PASS)
    {
        manfID = (uint32_t)idCode[0];
        devID = ((uint32_t)idCode[1] << 8) | ((uint32_t)idCode[2]);
        if ((manfID == NOR_MANF_ID) && (devID == NOR_DEVICE_ID))
        {
            Nor_ospiInfo.manufacturerId = manfID;
            Nor_ospiInfo.deviceId = devID;
        }
        else
        {
            retVal = NOR_FAIL;
        }
    }

    return (retVal);
}

static NOR_STATUS Nor_ospiEnableDDR(SPI_Handle handle)
{
    NOR_STATUS             retVal;
    uint8_t                cmdWren = NOR_CMD_WREN;
    uint32_t               data[3];

    /* Send Write Enable command */
    retVal = Nor_ospiCmdWrite(handle, &cmdWren, 1, 0);

    /* Enable double transfer rate mode */
    if (retVal == NOR_PASS)
    {
        /* send write VCR command to reg addr 0x0 to set to DDR mode */
        data[0] = (NOR_CMD_WRITE_VCR << 24)         | /* write volatile config reg cmd */
                  (0 << 23)                         | /* read data disable */
                  (7 << 20)                         | /* read 8 data bytes */
                  (1 << 19)                         | /* enable cmd adddr */
                  (2 << 16)                         | /* 3 address bytes */
                  (1 << 15);                          /* write data enable */
        data[1] = 0;     /* Non-volatile config register address */
        data[2] = 0xE7U; /* set to Octal DDR in Nonvolatile Config Reg 0x0 */
        SPI_control(handle, SPI_V0_CMD_ENABLE_DDR, (void *)data);
    }

    return retVal;
}

static NOR_STATUS Nor_ospiEnableSDR(SPI_Handle handle)
{
    NOR_STATUS             retVal;
    uint8_t                cmdWren = NOR_CMD_WREN;
    uint32_t               data[3];

    /* Send Write Enable command */
    retVal = Nor_ospiCmdWrite(handle, &cmdWren, 1, 0);

    /* Enable single transfer rate mode */
    if (retVal == NOR_PASS)
    {
        /* send write VCR command to reg addr 0x0 to set to SDR mode */
        data[0] = (NOR_CMD_WRITE_VCR << 24)         | /* write volatile config reg cmd */
                  (0 << 23)                         | /* read data disable */
                  (7 << 20)                         | /* read 8 data bytes */
                  (1 << 19)                         | /* enable cmd adddr */
                  (2 << 16)                         | /* 3 address bytes */
                  (1 << 15);                          /* write data enable */
        data[1] = 0;     /* Non-volatile config register address */
        data[2] = 0xFFU; /* set to Extended SPI mode in Nonvolatile Config Reg 0x0 */
        SPI_control(handle, SPI_V0_CMD_ENABLE_SDR, (void *)data);

    }

    return retVal;
}

static NOR_STATUS Nor_ospiResetMemory(SPI_Handle handle)
{
    NOR_STATUS             retVal;
    uint8_t                cmd;

    /* Send Reset Enable command */
    cmd = NOR_CMD_RSTEN;
    retVal = Nor_ospiCmdWrite(handle, &cmd, 1, 0);

    if (retVal == NOR_PASS)
    {
        /* Send Reset Device Memory command */
        cmd = NOR_CMD_RST_MEM;
        retVal = Nor_ospiCmdWrite(handle, &cmd, 1, 0);
    }

    return (retVal);
}

static NOR_STATUS Nor_ospiXipEnable(SPI_Handle handle)
{
    NOR_STATUS             retVal;
    uint8_t  cmdWren = NOR_CMD_WREN;
    uint32_t value = 0x0;
    uint8_t  stigCmd[10];
    uint32_t data[3];

    /* Send Write Enable command */
    retVal = Nor_ospiCmdWrite(handle, &cmdWren, 1, 0);

    if (retVal == NOR_PASS)
    {
        stigCmd[0] = NOR_CMD_WRITE_VCR; /* opcode */
        stigCmd[1] = 0x0; /* disable read operation */
        stigCmd[2] = 0x7; /* read 0x7=8 data bytes (ignored) */
        stigCmd[3] = 0x1; /* enable cmd address */
        stigCmd[4] = 0x0; /* disable mode bits */
        stigCmd[5] = 0x3; /* use 0x3=4 address bytes */
        stigCmd[6] = 0x1; /* enable write operation */
        stigCmd[7] = 0x0; /* write 0x0=1 data byte */
        stigCmd[8] = 0x0; /* 0x7=8 dummy cycles */
        stigCmd[9] = 0x0; /* disable memory bank */

        value |= (stigCmd[0] << 24);
        value |= (stigCmd[1] << 23);
        value |= (stigCmd[2] << 20);
        value |= (stigCmd[3] << 19);
        value |= (stigCmd[4] << 18);
        value |= (stigCmd[5] << 16);
        value |= (stigCmd[6] << 15);
        value |= (stigCmd[7] << 12);
        value |= (stigCmd[8] << 7);
        value |= (stigCmd[9] << 2);

        data[0] = value; /* NVCR cmd */
        data[1] = 0x06;  /* addr */
        data[2] = 0xFE;  /* data */

        SPI_control(handle, SPI_V0_CMD_CFG_XIP, (void*)data);
    }

    return retVal;
}

static void Nor_ospiSetOpcode(SPI_Handle handle)
{
    uint32_t               data[3];
    uint32_t               dummyCycles;
    uint32_t               rx_lines;
    OSPI_v0_HwAttrs const *hwAttrs= (OSPI_v0_HwAttrs const *)handle->hwAttrs;

    rx_lines = hwAttrs->xferLines;
    if (rx_lines == OSPI_XFER_LINES_OCTAL)
    {
        dummyCycles = NOR_OCTAL_READ_DUMMY_CYCLE;
        if (hwAttrs->dtrEnable == true)
        {
            data[0]     = NOR_CMD_OCTAL_DDR_O_FAST_RD;
            data[1]     = NOR_CMD_OCTAL_FAST_PROG;
        }
        else
        {
            data[0]     = NOR_CMD_OCTAL_IO_FAST_RD;
            data[1]     = NOR_CMD_EXT_OCTAL_FAST_PROG;
        }
    }
    else
    {
        /* Set to legacy SPI mode 1-1-1 if not Octal mode */
        dummyCycles = 0;
        data[0]     = NOR_CMD_READ;
        data[1]     = NOR_CMD_PAGE_PROG;
    }
    data[2]     = NOR_CMD_RDSR;

    /* Update the read opCode, rx lines and read dummy cycles */
    SPI_control(handle, SPI_V0_CMD_RD_DUMMY_CLKS, (void *)&dummyCycles);
    SPI_control(handle, SPI_V0_CMD_SET_XFER_LINES, (void *)&rx_lines);
    SPI_control(handle, SPI_V0_CMD_XFER_OPCODE, (void *)data);

    return;
}

NOR_HANDLE Nor_ospiOpen(uint32_t norIntf, uint32_t portNum, void *params)
{
    SPI_Params      spiParams;  /* SPI params structure */
    SPI_Handle      hwHandle;  /* SPI handle */
    NOR_HANDLE      norHandle = 0;
    uint32_t        i = 0;
    uint32_t        delay;
    uint32_t        readCnt = 0;
    uint32_t        readStart = 0;
    uint32_t        readCntPrv = 0;
    uint32_t        readStartPrv = 0;
    OSPI_v0_HwAttrs ospi_cfg;
    NOR_STATUS      retVal;

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
        retVal = NOR_PASS;
        if (retVal == NOR_PASS)
        {
            OSPI_socGetInitCfg(portNum, &ospi_cfg);
            if (ospi_cfg.xferLines == OSPI_XFER_LINES_OCTAL)
            {
                /* Enable DDR or SDR mode for Octal lines */
                if (ospi_cfg.dtrEnable == true)
                {
                    Nor_ospiEnableDDR(hwHandle);
                }
                else
                {
                    Nor_ospiEnableSDR(hwHandle);
                }
            }
            else
            {
                /* Reset device memory for all the other lines */
                Nor_ospiResetMemory(hwHandle);
            }
            
            /* Set read/write opcode and read dummy cycles */
            Nor_ospiSetOpcode(hwHandle);

            if (ospi_cfg.phyEnable == true)
            {
                /* set initial PHY DLL delay */
                delay = 0U;
                SPI_control(hwHandle, SPI_V0_CMD_CFG_PHY, (void *)(&delay));

                /* calibrate PHY */
                for (i = 0; i < 128U; i++)
                {
                    if (Nor_ospiReadId(hwHandle) == NOR_PASS)
                    {
                        /* Iterate flash reads, find the start index and successful read ID count */
                        if (readCnt == 0)
                            readStart = i;
                        readCnt++;
                    }
                    else
                    {
                        if ((readCnt != 0) && (readCnt > readCntPrv))
                        {
                            /* save the start index and most successful read ID count */
                            readCntPrv = readCnt;
                            readStartPrv = readStart;
                            readCnt = 0;
                            readStart = 0;
                        }
                    }

                    /* Increment DLL delay */
                    SPI_control(hwHandle, SPI_V0_CMD_CFG_PHY, NULL);
                }

                if (readCnt > readCntPrv)
                {
                    readCntPrv = readCnt;
                    readStartPrv = readStart;
                }

                if (readCntPrv != 0U)
                {
                    /* Find the delay in the middle working position */
                    delay = readStartPrv + (readCntPrv / 2);
                    SPI_control(hwHandle, SPI_V0_CMD_CFG_PHY, (void *)(&delay));
                    Nor_ospiInfo.hwHandle = (uintptr_t)hwHandle;
                    norHandle = (NOR_HANDLE)(&Nor_ospiInfo);
                }
                else
                {
                    SPI_close(hwHandle);
                }
            }
            else /* ospi_cfg->phyEnable == false */
            {
                if (Nor_ospiReadId(hwHandle) == NOR_PASS)
                {
                    Nor_ospiInfo.hwHandle = (uintptr_t)hwHandle;
                    norHandle = (NOR_HANDLE)(&Nor_ospiInfo);
                }
                else
                {
                    SPI_close(hwHandle);
                }
            }

            if (ospi_cfg.xipEnable == true)
            {
                Nor_ospiXipEnable(hwHandle);
            }
        }
        else /* Nor_ospiEnableDDR(hwHandle) != NOR_PASS */
        {
            SPI_close(hwHandle);
        }
    }

    return (norHandle);
}

void Nor_ospiClose(NOR_HANDLE handle)
{
    NOR_Info    *norOspiInfo;
    SPI_Handle   spiHandle;

    if (handle)
    {
        norOspiInfo = (NOR_Info *)handle;
        spiHandle = (SPI_Handle)norOspiInfo->hwHandle;

        if (spiHandle)
        {
            SPI_close(spiHandle);
        }
    }
}

static NOR_STATUS Nor_ospiCmdWrite(SPI_Handle handle, uint8_t *cmdBuf,
                                        uint32_t cmdLen, uint32_t dataLen)
{
    SPI_Transaction  transaction;
    uint32_t         transferType = SPI_TRANSACTION_TYPE_WRITE;
    bool             ret;

    /* Update the mode and transfer type with the required values */
    SPI_control(handle, SPI_V0_CMD_SET_CFG_MODE, NULL);
    SPI_control(handle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);

    transaction.txBuf = (void *)cmdBuf; /* Buffer includes command and write data */
    transaction.count = cmdLen + dataLen;
    transaction.rxBuf = NULL;
    transaction.arg = (void *)(uintptr_t)dataLen;

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

static NOR_STATUS Nor_ospiWaitReady(SPI_Handle handle, uint32_t timeOut)
{
    uint8_t         status;
    uint8_t         cmd = NOR_CMD_RDSR;

    do
    {
        if (NOR_ospiCmdRead(handle, &cmd, 1, &status, 1))
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

static SPI_Transaction transaction;
NOR_STATUS Nor_ospiRead(NOR_HANDLE handle, uint32_t addr,
                        uint32_t len, uint8_t *buf, uint32_t mode)
{
    NOR_Info        *norOspiInfo;
    SPI_Handle       spiHandle;
    bool             ret;
    uint32_t         transferType = SPI_TRANSACTION_TYPE_READ;

    if (!handle)
    {
        return NOR_FAIL;
    }

    norOspiInfo = (NOR_Info *)handle;
    if (!norOspiInfo->hwHandle)
    {
        return NOR_FAIL;
    }
    spiHandle = (SPI_Handle)norOspiInfo->hwHandle;

    /* Validate address input */
    if ((addr + len) > NOR_SIZE)
    {
        return NOR_FAIL;
    }
    /* Set transfer mode and read type */
    SPI_control(spiHandle, SPI_V0_CMD_SET_XFER_MODE, NULL);
    SPI_control(spiHandle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);

    transaction.arg   = (void *)(uintptr_t)addr;
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

NOR_STATUS Nor_ospiWrite(NOR_HANDLE handle, uint32_t addr, uint32_t len,
                         uint8_t *buf, uint32_t mode)
{
    NOR_Info        *norOspiInfo;
    SPI_Handle       spiHandle;
    bool             ret;
    uint32_t         byteAddr;
    uint32_t         wrSize = len;
    uint32_t         chunkLen;
    uint32_t         actual;
    uint32_t         transferType = SPI_TRANSACTION_TYPE_WRITE;
    OSPI_v0_HwAttrs *hwAttrs;

    if (!handle)
    {
        return NOR_FAIL;
    }

    norOspiInfo = (NOR_Info *)handle;
    if (!norOspiInfo->hwHandle)
    {
        return NOR_FAIL;
    }

    /* Validate address input */
    if ((addr + len) > NOR_SIZE)
    {
        return NOR_FAIL;
    }

    spiHandle = (SPI_Handle)norOspiInfo->hwHandle;
    hwAttrs = (OSPI_v0_HwAttrs *)spiHandle->hwAttrs;

    /* Set the transfer mode, write op code and tx lines */
    SPI_control(spiHandle, SPI_V0_CMD_SET_XFER_MODE, NULL);
    SPI_control(spiHandle, SPI_V0_CMD_XFER_MODE_RW, (void *)&transferType);

    if (hwAttrs->dacEnable )
    {
        /* direct access transfer mode */
        if ((hwAttrs->dmaEnable) && (hwAttrs->phyEnable))
        {
            wrSize = 16U;
        }
    }
    else
    {
        /* indirect access transfer mode */
        if (hwAttrs->intrEnable)
        {
            wrSize = 256U;
        }
    }
    byteAddr = addr & (wrSize - 1);

    for (actual = 0; actual < len; actual += chunkLen)
    {
        /* Send Page Program command */
        chunkLen = ((len - actual) < (wrSize - byteAddr) ?
                    (len - actual) : (wrSize - byteAddr));

        transaction.arg   = (void *)(uintptr_t)addr;
        transaction.txBuf = (void *)(buf + actual);
        transaction.rxBuf = NULL;
        transaction.count = chunkLen;

        ret = SPI_transfer(spiHandle, &transaction);
        if (ret == false)
        {
            return NOR_FAIL;
        }

        addr += chunkLen;
        byteAddr = 0;
    }

    return NOR_PASS;
}

NOR_STATUS Nor_ospiErase(NOR_HANDLE handle, int32_t erLoc, bool blkErase)
{
    uint8_t         cmd[5];
    uint32_t        cmdLen;
    uint32_t        address = 0;
    uint8_t         cmdWren  = NOR_CMD_WREN;
    NOR_Info       *norOspiInfo;
    SPI_Handle      spiHandle;
    OSPI_v0_HwAttrs const *hwAttrs;

    if (!handle)
    {
        return NOR_FAIL;
    }

    norOspiInfo = (NOR_Info *)handle;
    if (!norOspiInfo->hwHandle)
    {
        return NOR_FAIL;
    }
    spiHandle = (SPI_Handle)norOspiInfo->hwHandle;
    hwAttrs = (OSPI_v0_HwAttrs const *)spiHandle->hwAttrs;

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

        if (hwAttrs->dtrEnable == (bool)true)
        {
            cmd[1] = (address >> 24) & 0xff; /* 4 address bytes */
            cmd[2] = (address >> 16) & 0xff;
            cmd[3] = (address >>  8) & 0xff;
            cmd[4] = (address >>  0) & 0xff;
            cmdLen = 5;
        }
        else
        {
            cmd[1] = (address >> 16) & 0xff; /* 3 address bytes */
            cmd[2] = (address >>  8) & 0xff;
            cmd[3] = (address >>  0) & 0xff;
            cmdLen = 4;
        }

    }

    if (Nor_ospiCmdWrite(spiHandle, &cmdWren, 1, 0))
    {
    	return NOR_FAIL;
    }

    if (Nor_ospiWaitReady(spiHandle, NOR_WRR_WRITE_TIMEOUT))
    {
    	return NOR_FAIL;
    }

    if (Nor_ospiCmdWrite(spiHandle, cmd, cmdLen, 0))
    {
    	return NOR_FAIL;
    }

    if (Nor_ospiWaitReady(spiHandle, NOR_BULK_ERASE_TIMEOUT))
    {
    	return NOR_FAIL;
    }

    return NOR_PASS;
}
