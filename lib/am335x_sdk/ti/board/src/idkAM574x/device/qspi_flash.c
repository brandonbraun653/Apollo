/**
 *  \file   S25FL.c
 *
 *  \brief  Flash specific driver implementation.
 *
 */

/*
 * Copyright (C) 2014-2019 Texas Instruments Incorporated - http://www.ti.com/
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

#include "qspi_flash.h"
#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>


/*!
 *  @brief Flash object containing flash attributes.
 */
S25FL_Object s25flObject = {NULL,
                            4,
                            S25FL_FLASH_SECTOR_SIZE,
                            S25FL_FLASH_BLOCK_SIZE,
                            S25FL_FLASH_DEVICE_SIZE,
                            S25FL_FLASH_DEVICE_ID};


static bool SF25FL_ConfigMode_Write(uint32_t dstOffstAddr,
                                    unsigned char* srcAddr,
                                    uint32_t length,
                                    S25FL_Handle flashHandle);

/*
 *  ======== SF25FL_close ========
 */
void SF25FL_close(S25FL_Handle handle)
{
    SPI_close(handle->spiHandle);
}

/*
 *  ======== SF25FL_open ========
 */
S25FL_Handle SF25FL_open(unsigned int index, SPI_Params *params)
{
    S25FL_Handle s25flHandle;

    s25flHandle = &s25flObject;

    /* Open SPI driver for SF25FL */
    s25flHandle->spiHandle = SPI_open(index, params);

    return s25flHandle;
}

/*
 *  ======== SF25FL_bufferWrite ========
 */
bool SF25FL_bufferWrite(S25FL_Handle flashHandle,
                        S25FL_Transaction* flashTransaction)
{
    bool retVal = false;                        /* return value */
    SPI_Handle handle = flashHandle->spiHandle; /* SPI handle */
    SPI_Transaction transaction;                /* SPI transaction structure */
    unsigned int idx;                           /* index */
    uint32_t dstOffstAddr;                      /* Flash offset address */
    unsigned char *srcAddr;                     /* Address of data buffer */
    uint32_t length;                            /* data length in bytes */
    unsigned int transferType;
    unsigned char transferCmd;
    QSPI_v1_Object  *object;

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object *)handle->object;

    /* Copy flash transaction parameters to local variables */
    dstOffstAddr = flashTransaction->address;
    srcAddr = flashTransaction->data;
    length = flashTransaction->dataSize;

    if(QSPI_OPER_MODE_CFG == object->qspiMode)
    {
        /*
         * Config mode write supports 256 bytes at a time. So if the length is
         * greater than 256, then multiple transactions have to be performed till
         * all the bytes are written.
         */
        while(length > 256)
        {
            SF25FL_ConfigMode_Write(dstOffstAddr, srcAddr, 256, flashHandle);
            dstOffstAddr = dstOffstAddr + (256 / 4);
            srcAddr += 256;
            length -= 256;
        }
        if(length > 0)
        {
            SF25FL_ConfigMode_Write(dstOffstAddr, srcAddr, length, flashHandle);
        }
    }


    if(QSPI_OPER_MODE_MMAP == object->qspiMode)
    {
        if(dstOffstAddr > 0xFFFFFFU)
        {
            /* Enter 32 bit addressing mode */
            S25FLFlash_Enable4ByteAddrMode(flashHandle, true);
        }

        for(idx = 0; idx < length; idx++)
        {
            /* Write enable */
            S25FLFlash_WriteEnable(flashHandle);

            /* Perform the transfer */
            transaction.txBuf = (unsigned char *)dstOffstAddr;
            transaction.rxBuf = srcAddr;
            transaction.count = 1;

            transferType = SPI_TRANSACTION_TYPE_WRITE;
            transferCmd  = QSPI_LIB_CMD_PAGE_PRG;
            SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);
            SPI_control(handle, SPI_V1_CMD_MMAP_TRANSFER_CMD, (void *)&transferCmd);
            retVal = SPI_transfer(handle, &transaction);

            /* Check flash status for completion */
            while ((FlashStatus(flashHandle) & 0x1U));

            dstOffstAddr += 1;
            srcAddr += 1;
        }

        if(dstOffstAddr > 0xFFFFFFU)
        {
            /* Exit 4 byte addressing mode */
            S25FLFlash_Enable4ByteAddrMode(flashHandle, false);
        }
    }

    return retVal;
}



bool SF25FL_bufferRead(S25FL_Handle flashHandle,
                       S25FL_Transaction* flashTransaction)
{
    bool retVal = false;                        /* return value */
    SPI_Handle handle = flashHandle->spiHandle; /* SPI handle */
    unsigned char writeVal[4];               /* data to be written */
    SPI_Transaction transaction;             /* SPI transaction structure */
    uint32_t addrLengthInBytes = 3U;         /* Flash address length in bytes */
    uint32_t readCmd;                        /* Read command */
    uint32_t numDummyBits;                   /* Number of dummy bits */
    uint32_t frameLength;                    /* Frame length */
    uint32_t dstOffstAddr;                   /* Flash offset address */
    unsigned char *srcAddr;                  /* Address of data buffer */
    uint32_t length;                         /* data length in bytes */
    unsigned int *tempPtr = (unsigned int *)&writeVal[0];  /* temp pointer */
    unsigned int frmLength;
    unsigned int transferType;
    unsigned char transferCmd;
    QSPI_v1_Object  *object;

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object *)handle->object;

    /* Copy flash transaction parameters to local variables */
    dstOffstAddr = (uint32_t)flashTransaction->data;
    srcAddr = (unsigned char *)flashTransaction->address;
    length = flashTransaction->dataSize;

    /* Initialize variables */
    frameLength = 0;
    readCmd = 0;
    numDummyBits = 0;

    if(QSPI_OPER_MODE_CFG == object->qspiMode)
    {
        addrLengthInBytes = 3U;
        if(srcAddr > (unsigned char *)0xFFFFFF)
        {
            /* Enter 32 bit addressing mode */
            S25FLFlash_Enable4ByteAddrMode(flashHandle, true);
            addrLengthInBytes = 4;
        }

        switch(object->rxLines)
        {
            case QSPI_RX_LINES_SINGLE:
            {
                readCmd = QSPI_LIB_CMD_READ_SINGLE;
                numDummyBits = 0U;

                /* total transaction frame length in number of words (bytes)*/
                frameLength = length + 1 + addrLengthInBytes;
                break;
            }

            case QSPI_RX_LINES_DUAL:
            {
                readCmd = QSPI_LIB_CMD_READ_DUAL;
                numDummyBits = 8U;

                /* total transaction frame length in number of words (bytes)*/
                frameLength = length + 1 + 1 + addrLengthInBytes;
                break;
            }

            case QSPI_RX_LINES_QUAD:
            {
                readCmd = QSPI_LIB_CMD_READ_QUAD;
                numDummyBits = 8U;

                /* total transaction frame length in number of words (bytes)*/
                frameLength = length + 1 + 1 + addrLengthInBytes;
                break;
            }

            default:
            break;
        }

        /* total transaction frame length */
        frmLength = frameLength;
        SPI_control(handle, SPI_V1_CMD_SETFRAMELENGTH, (void *)&frmLength);

        /* Write read command */
        writeVal[0] = readCmd;
        transaction.txBuf = (unsigned char *)&writeVal[0];
        transaction.rxBuf = NULL;
        transaction.count = 1;

        transferType = SPI_TRANSACTION_TYPE_WRITE;
        SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);
        retVal = SPI_transfer(handle, &transaction);

        /* Write Address Bytes */
        *tempPtr = (unsigned int)srcAddr;
        transaction.txBuf = (unsigned char *)tempPtr;
        transaction.rxBuf = NULL;
        transaction.count = addrLengthInBytes;

        transferType = SPI_TRANSACTION_TYPE_WRITE;
        SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);
        retVal = SPI_transfer(handle, &transaction);

        /* Write dummy bits for fast read if required */
        if(0 != numDummyBits)
        {
            writeVal[0] = 0U;
            transaction.txBuf = (unsigned char *)&writeVal[0];
            transaction.rxBuf = NULL;
            transaction.count = (numDummyBits >> 3);      /* In bytes */

        transferType = SPI_TRANSACTION_TYPE_WRITE;
        SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);
            retVal = SPI_transfer(handle, &transaction);
        }

        /* Read the actual flash data */
        transaction.txBuf = NULL;
        transaction.rxBuf = (unsigned char *)dstOffstAddr;
        transaction.count = length;

        transferType = SPI_TRANSACTION_TYPE_READ;
        SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);
        retVal = SPI_transfer(handle, &transaction);

        if(srcAddr > (unsigned char *)0xFFFFFF)
        {
            /* Exit 32 bit addressing mode */
            S25FLFlash_Enable4ByteAddrMode(flashHandle, false);
            addrLengthInBytes = 3;
        }
    }

    if(QSPI_OPER_MODE_MMAP == object->qspiMode)
    {
        if(srcAddr > (unsigned char *)0xFFFFFF)
        {
            /* Enter 32 bit addressing mode */
            S25FLFlash_Enable4ByteAddrMode(flashHandle, true);
        }

        switch(object->rxLines)
        {
            case QSPI_RX_LINES_SINGLE:
            {
                readCmd = QSPI_LIB_CMD_READ_SINGLE;
                break;
            }

            case QSPI_RX_LINES_DUAL:
            {
                readCmd = QSPI_LIB_CMD_READ_DUAL;
                break;
            }

            case QSPI_RX_LINES_QUAD:
            {
                readCmd = QSPI_LIB_CMD_READ_QUAD;
                break;
            }

            default:
            break;
        }

        /* Perform the transfer */
        transaction.txBuf = srcAddr;
        transaction.rxBuf = (uint8_t *)dstOffstAddr;
        transaction.count = length;

        transferType = SPI_TRANSACTION_TYPE_READ;
        transferCmd  = (unsigned char)readCmd;
        SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);
        SPI_control(handle, SPI_V1_CMD_MMAP_TRANSFER_CMD, (void *)&transferCmd);
        retVal = SPI_transfer(handle, &transaction);

        if(srcAddr > (unsigned char *)0xFFFFFF)
        {
            /* Exit 32 bit addressing mode */
            S25FLFlash_Enable4ByteAddrMode(flashHandle, false);
        }
    }

    return retVal;
}


bool S25FLFlash_WriteEnable(S25FL_Handle flashHandle)
{
    SPI_Handle handle = flashHandle->spiHandle; /* SPI handle */
    bool retVal = false;                /* return value */
    unsigned char writeVal;             /* data to be written */
    SPI_Transaction transaction;        /* SPI transaction structure */
    unsigned int operMode;              /* temp variable to hold mode */
    unsigned int rxLines;               /* temp variable to hold rx lines */
    unsigned int frmLength;
    unsigned int transferType;
    QSPI_v1_Object  *object;
    unsigned int rxLinesArg;

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object *)handle->object;

    /* These operations require the qspi to be configured in the following mode
       only: tx/rx single line and config mode. */

    /* Save the current mode and rxLine configurations */
    operMode = object->qspiMode;
    rxLines  = object->rxLines;

    /* Update the mode and rxLines with the required values */
    SPI_control(handle, SPI_V1_CMD_SETCONFIGMODE, NULL);

    rxLinesArg = QSPI_RX_LINES_SINGLE;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLinesArg);

    /* transaction frame length in words (bytes) */
    frmLength = 1;
    SPI_control(handle, SPI_V1_CMD_SETFRAMELENGTH, (void *)&frmLength);

    /* Write enable command */
    writeVal = QSPI_LIB_CMD_WRITE_ENABLE;

    /* Update transaction parameters */
    transaction.txBuf = (unsigned char *)&writeVal;
    transaction.rxBuf = NULL;
    transaction.count  = 1;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    /* Restore operating mode and rx Lines */
    object->qspiMode = operMode;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLines);

    return retVal;
}


bool S25FLFlash_Enable4ByteAddrMode(S25FL_Handle flashHandle,
                                    bool enable4ByteMode)
{
    SPI_Handle handle = flashHandle->spiHandle; /* SPI handle */
    bool retVal = false;             /* return value */
    unsigned char writeVal;          /* data to be written */
    SPI_Transaction transaction;     /* SPI transaction structure */
    unsigned int operMode;           /* temp variable to hold mode */
    unsigned int rxLines;            /* temp variable to hold rx lines */
    unsigned int transferType;
    QSPI_v1_Object  *object;
    unsigned int rxLinesArg;

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object *)handle->object;

    /* These operations require the qspi to be configured in the following mode
       only: tx/rx single line and config mode. */

    /* Save the current mode and rxLine configurations */
    operMode = object->qspiMode;
    rxLines  = object->rxLines;


    /* Update the mode and rxLines with the required values */
    SPI_control(handle, SPI_V1_CMD_SETCONFIGMODE, NULL);
    rxLinesArg = QSPI_RX_LINES_SINGLE;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLinesArg);

    /* Command to control the 4 byte mode */
    if (true == enable4ByteMode)
    {
        writeVal = QSPI_LIB_CMD_ENTER_4_BYTE_ADDR;
    }
    else
    {
        writeVal = QSPI_LIB_CMD_EXIT_4_BYTE_ADDR;
    }

    /* Write 4 byte enable/disable command to flash */
    transaction.count = 1U;                    /* Frame length in bytes */
    transaction.txBuf = (unsigned char *)&writeVal;  /* Value to be written */
    transaction.rxBuf = NULL;                  /* Nothing to read */
    transaction.arg   = NULL;                  /* Not applicable */

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);


    retVal = SPI_transfer(handle, &transaction);

    /* Restore operating mode and rx Lines */
    object->qspiMode = operMode;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLines);

    return retVal;
}


uint32_t FlashStatus(S25FL_Handle flashHandle)
{
    SPI_Handle handle = flashHandle->spiHandle; /* SPI handle */
    bool retVal = false;             /* return value */
    unsigned char writeVal;          /* data to be written */
    SPI_Transaction transaction;     /* SPI transaction structure */
    uint32_t rxData = 0U;            /* received data */
    unsigned int operMode;           /* temp variable to hold mode */
    unsigned int rxLines;            /* temp variable to hold rx lines */
    unsigned int frmLength;
    unsigned int transferType;
    QSPI_v1_Object  *object;
    unsigned int rxLinesArg;

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object *)handle->object;

    /* These operations require the qspi to be configured in the following mode
       only: tx/rx single line and config mode. */

    /* Save the current mode and rxLine configurations */
    operMode = object->qspiMode;
    rxLines  = object->rxLines;

    /* Update the mode and rxLines with the required values */
    SPI_control(handle, SPI_V1_CMD_SETCONFIGMODE, NULL);

    rxLinesArg = QSPI_RX_LINES_SINGLE;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLinesArg);

    /* Total transaction frame length in words (bytes) */
    frmLength = 1 + 1;
    SPI_control(handle, SPI_V1_CMD_SETFRAMELENGTH, (void *)&frmLength);

    /* Write Address Bytes */
    writeVal = QSPI_LIB_CMD_READ_STATUS_REG;
    transaction.txBuf = (unsigned char *)&writeVal;
    transaction.rxBuf = NULL;
    transaction.count = 1U;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    if(retVal == false)
    {
        /* Error */
    }

    /* Read the status register */
    transaction.txBuf = NULL;
    transaction.rxBuf = (unsigned char *)&rxData;
    transaction.count = 1U;

    transferType = SPI_TRANSACTION_TYPE_READ;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    if(retVal == false)
    {
        /* Error */
    }

    /* Restore operating mode and rx Lines */
    object->qspiMode = operMode;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLines);

    return (rxData & 0xFF);
}


bool S25FLFlash_QuadModeEnable(S25FL_Handle flashHandle)
{
    SPI_Transaction transaction;                /* SPI transaction structure */
    SPI_Handle handle = flashHandle->spiHandle; /* SPI handle */
    unsigned char writeVal = 0U;    /* data to be written */
    uint32_t norStatus;             /* flash status value */
    uint32_t configReg;             /* configuration register value */
    uint32_t data;                  /* data to be written */
    bool retVal = false;            /* return value */
    unsigned int operMode;          /* temp variable to hold mode */
    unsigned int rxLines;           /* temp variable to hold rx lines */
    unsigned int frmLength;
    unsigned int transferType;
    QSPI_v1_Object  *object;
    unsigned int rxLinesArg;

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object *)handle->object;

    /* These operations require the qspi to be configured in the following mode
       only: tx/rx single line and config mode. */

    /* Save the current mode and rxLine configurations */
    operMode = object->qspiMode;
    rxLines  = object->rxLines;

    /* Update the mode and rxLines with the required values */
    SPI_control(handle, SPI_V1_CMD_SETCONFIGMODE, NULL);

    rxLinesArg = QSPI_RX_LINES_SINGLE;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLinesArg);

    /* Set transfer length in bytes: Reading status register */
    frmLength = 1 + 1;
    SPI_control(handle, SPI_V1_CMD_SETFRAMELENGTH, (void *)&frmLength);

    /* Read Status register */
    writeVal = QSPI_LIB_CMD_READ_STATUS_REG;
    transaction.txBuf = (unsigned char *)&writeVal;
    transaction.rxBuf = NULL;
    transaction.count = 1;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    transaction.txBuf = NULL;
    transaction.rxBuf = (unsigned char *)&norStatus;
    transaction.count = 1;

    transferType = SPI_TRANSACTION_TYPE_READ;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    /* Set transfer length in bytes: Reading status register */
    frmLength = 1 + 1;
    SPI_control(handle, SPI_V1_CMD_SETFRAMELENGTH, (void *)&frmLength);

    /* Read command register */
    writeVal = QSPI_LIB_CMD_QUAD_RD_CMD_REG;
    transaction.txBuf = (unsigned char *)&writeVal;
    transaction.rxBuf = NULL;
    transaction.count = 1;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    transaction.txBuf = NULL;
    transaction.rxBuf = (unsigned char *)&configReg;
    transaction.count = 1;

    transferType = SPI_TRANSACTION_TYPE_READ;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    /* Set 2nd bit of configuration register to 1 to enable quad mode */
    configReg |= (QSPI_FLASH_QUAD_ENABLE_VALUE << QSPI_FLASH_QUAD_ENABLE_BIT);
    data = (QSPI_LIB_CMD_WRITE_STATUS_REG << 16) | (norStatus << 8) | configReg;

    /* Set transfer length in bytes */
    frmLength = 1;
    SPI_control(handle, SPI_V1_CMD_SETFRAMELENGTH, (void *)&frmLength);


    transaction.txBuf = (unsigned char *)&data;
    transaction.rxBuf = NULL;
    transaction.count = 3;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    /* Wait till the status register is being written */
    while (1U == (FlashStatus(flashHandle) & 0x1U));

    /* Restore operating mode and rx Lines */
    object->qspiMode = operMode;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLines);

    return retVal;
}


static bool S25FLFlash_Erase(S25FL_Handle flashHandle, uint32_t eraseAddr, uint32_t cmd)
{
    uint32_t writeVal;     /* data to be written */
    SPI_Handle handle = flashHandle->spiHandle;  /* SPI handle */
    SPI_Transaction transaction;         /* SPI transaction structure */
    unsigned int addrLenInBytes = 3;     /* address length in bytes */
    bool retVal = false;                 /* return value */
    unsigned int operMode;               /* temp variable to hold mode */
    unsigned int rxLines;                /* temp variable to hold rx lines */
    unsigned int frmLength;
    unsigned int transferType;
    QSPI_v1_Object  *object;
    unsigned int rxLinesArg;
    uint32_t tempAddr;

    /* Get the pointer to the object and hwAttrs */
    object = handle->object;

    /* These operations require the qspi to be configured in the following mode
       only: tx/rx single line and config mode. */

    /* Save the current mode and rxLine configurations */
    operMode = object->qspiMode;
    rxLines  = object->rxLines;

    /* Update the mode and rxLines with the required values */
    SPI_control(handle, SPI_V1_CMD_SETCONFIGMODE, NULL);

    rxLinesArg = QSPI_RX_LINES_SINGLE;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLinesArg);

    if(eraseAddr > 0xFFFFFF)
    {
        /* Enter 4 byte addressing mode */
        S25FLFlash_Enable4ByteAddrMode(flashHandle, true);
        addrLenInBytes = 4;
    }

    tempAddr = ((eraseAddr & 0xFF000000) >> 24) |
               ((eraseAddr & 0x00FF0000) >> 8)  |
               ((eraseAddr & 0x0000FF00) << 8)  |
               ((eraseAddr & 0x000000FF) << 24);

    if(addrLenInBytes == 3)
    {
        tempAddr = (tempAddr >> 8) & 0x00FFFFFF;
    }

    /* Flash write enable */
    S25FLFlash_WriteEnable(flashHandle);

    /*total transaction frame length */
    frmLength = 1 + addrLenInBytes;
    SPI_control(handle, SPI_V1_CMD_SETFRAMELENGTH, ((void *)&frmLength));

    /* Block erase command */
    writeVal = cmd;
    transaction.txBuf = (unsigned char *)&writeVal;
    transaction.rxBuf = NULL;
    transaction.count = 1;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    /* Send erase address */
    writeVal = tempAddr;
    transaction.txBuf = (unsigned char *)&writeVal;
    transaction.rxBuf = NULL;
    transaction.count = addrLenInBytes;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    /* Check flash status for write completion */
    while (1U == (FlashStatus(flashHandle) & 0x1U));

    if(eraseAddr > 0xFFFFFF)
    {
        /* Exit 4 byte addressing mode */
        S25FLFlash_Enable4ByteAddrMode(flashHandle, false);
        addrLenInBytes = 3;
    }

    /* Restore operating mode and rx Lines */
    object->qspiMode = operMode;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLines);

    return retVal;
}


bool S25FLFlash_SectorErase(S25FL_Handle flashHandle, unsigned int sectorNumber)
{
    uint32_t eraseAddr;

    /* Compute flash erase address based on the sector size */
    eraseAddr = sectorNumber * flashHandle->sectorSize;

    return(S25FLFlash_Erase(flashHandle, eraseAddr, QSPI_LIB_CMD_SECTOR_ERASE));
}


bool S25FLFlash_BlockErase(S25FL_Handle flashHandle, unsigned int blockNumber)
{
    uint32_t eraseAddr;

    /* Compute flash erase address based on the block size */
    eraseAddr = blockNumber * flashHandle->blockSize;

    return(S25FLFlash_Erase(flashHandle, eraseAddr, QSPI_LIB_CMD_BLOCK_ERASE));
}


void FlashPrintId(S25FL_Handle flashHandle)
{
    uint32_t writeVal;               /* data to be written */
    SPI_Handle handle = flashHandle->spiHandle;  /* SPI handle */
    SPI_Transaction transaction;     /* SPI transaction structure */
    bool retVal = false;             /* return value */
    unsigned char mfgId = 0;         /* manufacture ID value */
    unsigned char deviceId = 0;      /* device ID value */
    unsigned int operMode;           /* temp variable to hold mode */
    unsigned int rxLines;            /* temp variable to hold rx lines */
    unsigned int frmLength;
    unsigned int transferType;
    QSPI_v1_Object  *object;
    unsigned int rxLinesArg;

    /* Get the pointer to the object and hwAttrs */
    object = (QSPI_v1_Object *)handle->object;

    /* These operations require the qspi to be configured in the following mode
       only: tx/rx single line and config mode. */

    /* Save the current mode and rxLine configurations */
    operMode = object->qspiMode;
    rxLines  = object->rxLines;

    /* Update the mode and rxLines with the required values */
    SPI_control(handle, SPI_V1_CMD_SETCONFIGMODE, NULL);

    rxLinesArg = QSPI_RX_LINES_SINGLE;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLinesArg);

    /* Total transaction frame length in bytes */
    frmLength = 1 + 3 + 2;   /* cmd + address + read data */
    SPI_control(handle, SPI_V1_CMD_SETFRAMELENGTH, (void *)&frmLength);

    /* Write Command */
    writeVal = QSPI_LIB_CMD_READ_MFG_ID;
    transaction.txBuf = (unsigned char *)&writeVal;
    transaction.rxBuf = NULL;
    transaction.count = 1;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    if(retVal == false)
    {
        /* Error */
    }

    /* Write Address Bytes */
    writeVal = 0x0U;
    transaction.txBuf = (unsigned char *)&writeVal;
    transaction.rxBuf = NULL;
    transaction.count = 3;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);


    retVal = SPI_transfer(handle, &transaction);


    /* Read Manufacturer ID
     * The manufacturer ID is of 1 byte(8 bits)
     */
    transaction.txBuf = NULL;
    transaction.rxBuf = &mfgId;
    transaction.count = 1;

    transferType = SPI_TRANSACTION_TYPE_READ;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);

    retVal = SPI_transfer(handle, &transaction);

    /* Read Device ID */
    transaction.txBuf = NULL;
    transaction.rxBuf = &deviceId;
    transaction.count = 1;

    transferType = SPI_TRANSACTION_TYPE_READ;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);


    retVal = SPI_transfer(handle, &transaction);

    /* Note - This ID is the device ID of the flash device.
     * This ID is read from the flash
     */

    /* Restore operating mode and rx Lines */
    object->qspiMode = operMode;
    SPI_control(handle, SPI_V1_CMD_SETRXLINES, (void *)&rxLines);
}

static bool SF25FL_ConfigMode_Write(uint32_t dstOffstAddr,
                                    unsigned char* srcAddr,
                                    uint32_t length,
                                    S25FL_Handle flashHandle)
{
    bool retVal = false;                        /* return value */
    SPI_Handle handle = flashHandle->spiHandle; /* SPI handle */
    uint32_t addrLengthInBytes = 3U;            /* Flash addr length in bytes */
    unsigned int frmLength;
    unsigned char writeVal[4];                  /* data to be written to QSPI */
    SPI_Transaction transaction;                /* SPI transaction structure */
    unsigned int transferType;


    addrLengthInBytes = 3U;        /* Flash address length in bytes */

    /* Extract address word length from the flash's destination offst addr*/
    if(dstOffstAddr > 0xFFFFFF)
    {
        /* Enter 32 bit addressing mode */
        S25FLFlash_Enable4ByteAddrMode(flashHandle, true);
        addrLengthInBytes = 4;
    }

    /* Write Enable */
    S25FLFlash_WriteEnable(flashHandle);

    /* total transaction frame length in number of words (bytes)*/
    frmLength = 1 + addrLengthInBytes + length;
    SPI_control(handle, SPI_V1_CMD_SETFRAMELENGTH, ((void *)&frmLength));

    /* Send Flash write command */
    writeVal[0] = QSPI_LIB_CMD_PAGE_PRG;   /* Flash write command */
    transaction.txBuf = (unsigned char *)&writeVal[0];
    transaction.rxBuf = NULL;
    transaction.count = 1U;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);
    retVal = SPI_transfer(handle, &transaction);

    /* Send flash address offset to which data has to be written */
    transaction.txBuf = (unsigned char *)dstOffstAddr;
    transaction.rxBuf = NULL;
    transaction.count = addrLengthInBytes;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);
    retVal = SPI_transfer(handle, &transaction);

    /* Write buffer data to flash */
    transaction.txBuf = (unsigned char *)srcAddr;
    transaction.rxBuf = NULL;
    transaction.count = length;

    transferType = SPI_TRANSACTION_TYPE_WRITE;
    SPI_control(handle, SPI_V1_CMD_TRANSFERMODE_RW, (void *)&transferType);
    retVal = SPI_transfer(handle, &transaction);

    /* Check flash status for write completion */
    while ((FlashStatus(flashHandle) & 0x1U));

    if(dstOffstAddr > 0xFFFFFF)
    {
        /* Exit 32 bit addressing mode */
        S25FLFlash_Enable4ByteAddrMode(flashHandle, false);
        addrLengthInBytes = 3;
    }

    return retVal;
}
