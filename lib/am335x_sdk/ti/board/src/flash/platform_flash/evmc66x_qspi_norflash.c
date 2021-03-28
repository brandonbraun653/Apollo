/*
 * Copyright (c) 2015, Texas Instruments Incorporated
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
 * \file  evmc66x_qspi_norflash.c
 *
 * \brief This file contains qspi norflash functions.
 *
 ******************************************************************************/
#include "platform_internal.h"

#if (PLATFORM_QSPI_FLASH_IN)

/**
 * \brief     To check whether the FLASH device is busy or in standby mode by
 *            reading WIP(Write in Progress) bit of Status register.
 *
 * \param     timeOut [IN]  : Time out given to wait for the device to come
 *                                to standby mode to accept commands.
 *
 * \return    QSPI_SUCCESS  : if success.
 *            QSPI_ERR      : if error.
 *
 **/
static QSPI_STATUS qspiFlashWaitReady(uint32_t timeOut)
{
    QSPI_STATUS ret;
    uint8_t     status;
    uint8_t     cmd = QSPI_FLASH_CMD_RDSR;

    do
    {
        ret = qspiCommandRead(&cmd, 1, &status, 1);
        if (ret) {
            IFPRINT (platform_write("Sending RDSR command failed\n"));
            return ret;
        }
        if ((status & QSPI_FLASH_SR_WIP) == 0) {
            break;
        }

        timeOut--;
        if (!timeOut) {
            break;
        }

    } while (TRUE);

    if ((status & QSPI_FLASH_SR_WIP) == 0) {
        return QSPI_SUCCESS;
    }

    IFPRINT (platform_write("qspiFlashWaitReady() : Timed out error\n"));

    /* Timed out */
    return QSPI_ERR;
}

/**
 * \brief     Enables/Disables the QUAD mode of the FLASH device.
 *
 * \param     pDevice [IN]  : Platform device handle.
 * \param     enable [IN]   : Enables or disables the QUAD mode.
 *                 1        - Enable QUAD mode
 *                 0        - Disable QUAD mode.
 *
 * \return    QSPI_SUCCESS  : if success.
 *            QSPI_ERR      : if error.
 *
 **/
QSPI_STATUS qspiFlashQuadModeCtrl(PLATFORM_DEVICE_info *pDevice,
                                  uint8_t enable)
{
    uint8_t cmdRdsr = QSPI_FLASH_CMD_RDSR;
    uint8_t cmdWrr  = QSPI_FLASH_CMD_WRR;
    uint8_t cmdWren = QSPI_FLASH_CMD_WREN;
    uint8_t cmdRdcr = QSPI_FLASH_CMD_RDCR;
    uint8_t status;
    uint8_t data[2];

    /* Write enable command */
    if (qspiCommandWrite(&cmdWren, 1, NULL, 0)) {
        IFPRINT (platform_write("qspiFlashQuadModeCtrl: Sending WREN command failed\n"));
        goto err;
    }

    /* Read status register */
    if (qspiCommandRead(&cmdRdsr, 1, &status, 1)) {
        IFPRINT (platform_write("qspiFlashQuadModeCtrl: Sending RDSR command failed\n"));
        goto err;
    }

    data[0] = status;

    /* The first byte will be written to the status register, while the
       second byte will be written to the configuration register */

    if (enable) {
        /* Write enabled, quad enabled, no protected blocks */
        data[1] = 0x02;
    } else {
        /* Write enabled, quad disabled, no protected block */
        data[1] = 0x0;
    }

    if (qspiCommandWrite(&cmdWrr, 1, data, 2)) {
        IFPRINT (platform_write("qspiFlashQuadModeCtrl: Sending WRR command failed\n"));
        goto err;
    }

    if (qspiFlashWaitReady(QSPI_FLASH_WRR_WRITE_TIMEOUT)) {
        IFPRINT (platform_write("qspiFlashQuadModeCtrl: WRR timeout error\n"));
        goto err;
    }

    if (qspiCommandRead(&cmdRdcr, 1, &status, 1)) {
        IFPRINT (platform_write("qspiFlashQuadModeCtrl: Sending RDCR command failed\n"));
        goto err;
    }

    if (status != data[1]) {
        IFPRINT (platform_write("qspiFlashQuadModeCtrl: Quad Mode Configuration Failed\n"));
        goto err;
    }

    return QSPI_SUCCESS;

err :
    return QSPI_ERR;
}

/**
 * \brief     Reads the device ID and manufacture ID of the FLASH device.
 *
 * \param     pDevice [IN]  : Platform device handle.
 *
 * \return    QSPI_SUCCESS  : if success.
 *            QSPI_ERR      : if error.
 *
 **/
QSPI_STATUS qspiFlashReadId(PLATFORM_DEVICE_info *pDevice)
{
    QSPI_STATUS ret;
    uint8_t     idcode[3];
    uint8_t     cmd = QSPI_FLASH_CMD_RDID;
    uint32_t    deviceId;

    ret = qspiCommandRead(&cmd, 1, idcode, sizeof(idcode));
    if (ret) {
        IFPRINT (platform_write("qspiFlashReadId: Error in reading the idcode\n"));
        return ret;
    }

    IFPRINT (platform_write("qspiFlashReadId: Flash idcode %02x %02x %02x\n",
                             idcode[0], idcode[1], idcode[2]));

    deviceId = (idcode[1] << 8) | (idcode[2]);

    IFPRINT (platform_write("qspiFlashReadId: Flash Device Id = 0x%x\n", deviceId));

    if (pDevice) {
        /* Get the actuals */
        pDevice->manufacturer_id   = idcode[0];
        pDevice->device_id         = deviceId;

        /* No blocks are bad for QSPI flash */
        pDevice->bblist = NULL;
    }

    return QSPI_SUCCESS;
}

#if (PLATFORM_QSPI_FLASH_READ_IN)

/**
 * \brief     Reads the data from the FLASH device.
 *
 * \param     pDevice [IN]  : Platform device handle.
 * \param     addr    [IN]  : Address of the FLASH device in bytes.
 * \param     len     [IN]  : Length of the data to be read in bytes.
 * \param     buf     [IN]  : Pointer to the buffer of read data.
 * \param     mode    [IN]  : Mode of the FLASH device to be operated.
 *                            QSPI_FLASH_SINGLE_READ - Single mode.
 *                            QSPI_FLASH_DUAL_READ   - Dual mode.
 *                            QSPI_FLASH_QUAD_READ   - Quad mode.
 *
 *
 * \return    QSPI_SUCCESS      : if success.
 *            QSPI_ERR          : if error.
 *
 **/
QSPI_STATUS qspiFlashRead(PLATFORM_DEVICE_info *pDevice, uint32_t addr,
                          uint32_t len, uint8_t *buf, uint8_t mode)
{
    uint8_t     cmd[3];
    uint8_t     command;
    uint8_t     dummyCycles;
    QSPI_STATUS ret;

    /* Validate address input */
    if ((addr + len) > QSPI_FLASH_SIZE) {
        IFPRINT (platform_write("qspiFlashRead() : Invalid Flash Address\n"));

        return QSPI_ERR;
    }

    switch(mode)
    {
        case QSPI_FLASH_SINGLE_READ :
            command     = QSPI_FLASH_CMD_READ;
            dummyCycles = QSPI_FLASH_SINGLE_READ_DUMMY_CYCLE;
            break;
        case QSPI_FLASH_DUAL_READ :
            command     = QSPI_FLASH_CMD_DUAL_READ;
            dummyCycles = QSPI_FLASH_DUAL_READ_DUMMY_CYCLE;
            break;
        case QSPI_FLASH_QUAD_READ :
            command     = QSPI_FLASH_CMD_QUAD_READ;
            dummyCycles = QSPI_FLASH_QUAD_READ_DUMMY_CYCLE;
            break;
        default :
            IFPRINT (platform_write("qspiFlashRead() : Invalid Flash Read Mode!"));
            IFPRINT (platform_write("Setting to Single Mode Read \n"));
            command     = QSPI_FLASH_CMD_READ;
            dummyCycles = QSPI_FLASH_SINGLE_READ_DUMMY_CYCLE;
            mode        = QSPI_FLASH_SINGLE_READ;
            break;
    }

    /* Initialize the command to be sent serially */
    cmd[0]  = command;
    cmd[1]  = mode;
    cmd[2]  = dummyCycles;

    IFPRINT (platform_write("%s: Reading from 0x%x of len 0x%x\n",__FUNCTION__,addr,len));
    ret = qspiRead(addr, cmd, buf, len);

    return ret;
}
#endif /* #if (PLATFORM_QSPI_FLASH_READ_IN) */

#if (PLATFORM_QSPI_FLASH_WRITE_IN)
/**
 * \brief     Writes the data into the FLASH device.
 *
 * \param     pDevice [IN]  : Platform device handle.
 * \param     addr    [IN]  : Address of the FLASH device in bytes.
 * \param     len     [IN]  : Length of the data to be written in bytes.
 * \param     buf     [IN]  : Pointer to the buffer of data to be
 *                            written.
 * \param     mode    [IN]  : Mode of the FLASH device to be
 *                            operated.
 *                            QSPI_FLASH_SINGLE_PAGE_PROG - Single mode.
 *                            QSPI_FLASH_QUAD_PAGE_PROG   - Quad mode.
 *
 *
 * \return    QSPI_SUCCESS      : if success.
 *            QSPI_ERR          : if error.
 *
 **/
QSPI_STATUS qspiFlashWrite(PLATFORM_DEVICE_info *pDevice, uint32_t addr,
                           uint32_t len, uint8_t *buf, uint8_t mode)
{
    uint32_t byteAddr;
    uint32_t pageSize;
    uint32_t loopCount;
    uint32_t chunkLen;
    uint32_t actual;
    uint8_t cmd[2];
    uint8_t cmdWren = QSPI_FLASH_CMD_WREN;
    QSPI_STATUS ret;

    /* Validate address input */
    if ((addr + len) > QSPI_FLASH_SIZE) {
        IFPRINT (platform_write("qspiFlashWrite() : Invalid Flash Address\n"));
        return QSPI_ERR;
    }

    switch(mode)
    {
        case QSPI_FLASH_SINGLE_PAGE_PROG :
            cmd[0] = QSPI_FLASH_CMD_PAGE_PROG;
            break;
        case QSPI_FLASH_QUAD_PAGE_PROG:
            cmd[0] = QSPI_FLASH_CMD_QUAD_PAGE_PROG;
            break;
        default :
            IFPRINT (platform_write("qspiFlashWrite() : Invalid Flash Write Mode!"));
            IFPRINT (platform_write("Setting to Single Mode Write \n"));
            cmd[0] = QSPI_FLASH_CMD_PAGE_PROG;
            mode   = QSPI_FLASH_SINGLE_PAGE_PROG;
            break;
    }

    /* Initialize the command to be sent serially */
    cmd[1]  = mode;

    /* The QSPI Flash Controller will automatically issue
       the WREN command before triggering a write command via the direct or
       indirect access controllers (DAC/INDAC) – i.e the user does not need
       to perform this operation.
    */
    pageSize    = QSPI_FLASH_PAGE_SIZE;
    byteAddr    = addr & (QSPI_FLASH_PAGE_SIZE - 1); /* % page_size; */

    ret = 0;
    for (actual = 0; actual < len; actual += chunkLen)
    {
        /* Send Write Enable command */
        if (qspiCommandWrite(&cmdWren, 1, NULL, 0)) {
            return QSPI_ERR;
        }

        /* Send Page Program command */
        chunkLen = ((len - actual) < (pageSize - byteAddr) ?
                (len - actual) : (pageSize - byteAddr));

        IFPRINT (platform_write("%s: Writing to 0x%x of len 0x%x\n",__FUNCTION__,addr,chunkLen));
        ret = qspiWrite(addr, cmd, buf + actual, chunkLen);
        if (ret) {
            return ret;
        }

        ret = qspiFlashWaitReady(QSPI_FLASH_PAGE_PROG_TIMEOUT);
        if (ret) {
            return ret;
        }

        addr += chunkLen;
        byteAddr = 0;

        loopCount = 4000;
        while (loopCount--) {
            asm("   NOP");
        }
    }

    return ret;
}

/**
 * \brief     Erase the FLASH device.
 *
 * This function can perform sector erase or complete device erase of the
 * flash.
 *  Pass sector number as parameter for sector erase.
 *  Pass 'QSPI_FLASH_BE_SECTOR_NUM' as parameter for bulk or device erase.
 *
 * \param     pDevice [IN]      : Platform device handle.
 * \param     sector  [IN]      : Sector number to be erased.
 *                                0 to 255 - SECTOR ERASE.
 *                                QSPI_FLASH_BE_SECTOR_NUM - BULK ERASE.
 *
 * \return    QSPI_SUCCESS      : if success.
 *            QSPI_ERR          : if error.
 *
 **/
QSPI_STATUS qspiFlashErase(PLATFORM_DEVICE_info *pDevice, int32_t  sector)
{
    uint8_t cmd[5];
    uint32_t cmdLen;
    uint32_t address = 0;
    uint8_t cmdWren  = QSPI_FLASH_CMD_WREN;
    QSPI_STATUS ret;

    if (sector == QSPI_FLASH_BE_SECTOR_NUM) {
        cmd[0]  = QSPI_FLASH_CMD_BULK_ERASE;
        cmdLen = 1;
    } else if (sector >= QSPI_FLASH_NUM_SECTORS) {
        IFPRINT (platform_write("qspiFlashErase: Not a valid sector number\n"));
        return QSPI_ERR;
    } else {
        address = sector * QSPI_FLASH_SECTOR_SIZE;
        cmd[0] = QSPI_FLASH_CMD_SECTOR_ERASE;
        cmd[1] = (address >> 24) & 0xff; /* 64MB flash device */
        cmd[2] = (address >> 16) & 0xff;
        cmd[3] = (address >>  8) & 0xff;
        cmd[4] = (address >>  0) & 0xff;

        cmdLen = 5;
    }

    IFPRINT (platform_write("%s: Erasing sector 0x%x of len 0x%x\n",__FUNCTION__,address,QSPI_FLASH_SECTOR_SIZE));

    ret = qspiCommandWrite(&cmdWren, 1, NULL, 0);
    if (ret) {
        goto err;
    }

    if (qspiFlashWaitReady(QSPI_FLASH_WRR_WRITE_TIMEOUT)) {
        IFPRINT (platform_write("qspiFlashQuadModeCtrl: WRR timeout error\n"));
        goto err;
    }

    ret = qspiCommandWrite(cmd, cmdLen, NULL, 0);
    if (ret) {
        goto err;
    }

    ret = qspiFlashWaitReady(QSPI_FLASH_BULK_ERASE_TIMEOUT);

err :
    return ret;
}

#endif /* #if (PLATFORM_QSPI_FLASH_WRITE_IN) */

/**
 * \brief     Initializes the FLASH device and configure communication
 *            between FLASH and QSPI controller.
 *
 * \param     pDevice  [IN] : Platform device handle.
 *
 * \return    QSPI_SUCCESS  : if success.
 *            QSPI_ERR      : if error.
 *
 **/
QSPI_STATUS qspiFlashInit(PLATFORM_DEVICE_info *pDevice)
{
    QSPI_STATUS ret;

    ret = qspiInit(QSPI_FLASH_PAGE_SIZE);

    return ret;
}

#endif /* #if (PLATFORM_QSPI_FLASH_IN) */

/* Nothing past this point */
