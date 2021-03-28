/******************************************************************************
 * Copyright (c) 2019 Texas Instruments Incorporated - http://www.ti.com
 *
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
 *****************************************************************************/

/**
 *  \file board_info.c
 *
 *  \brief This file contains the functions to read/write board info data 
 *
 */

#include "board_utils.h"
#include "board_internal.h"
#include "board_cfg.h"
#include <stdio.h>
#include <string.h>

extern Board_I2cInitCfg_t gBoardI2cInitCfg;

/**
 *  @brief  This function is not supported by this platform.
 *
 *  Function implementation for build backward compatibilty.
 *  Always returns 'BOARD_UNSUPPORTED_FEATURE'
 *
 */
Board_STATUS Board_getIDInfo(Board_IDInfo *info)
{
    return BOARD_UNSUPPORTED_FEATURE;
}

/**
 *  @brief      Get board information.
 *  
 *  This function requires the information of I2C instance and domain
 *  to which board ID EEPROM is connected. This need to be set using
 *  Board_setI2cInitConfig() before calling this function.
 *
 *  @param[out] Board_STATUS
 *    Returns status on API call
 *  @param[out] info
 *    This structure will have board information on return
 *  @param[in] slaveAddress
 *    I2C slave address of EEPROM to be read
 *
 */
Board_STATUS Board_getIDInfo_v2(Board_IDInfo_v2 *info, uint8_t slaveAddress)
{
    Board_STATUS ret = BOARD_SOK;
    I2C_Transaction i2cTransaction;
    I2C_Handle handle = NULL;
    uint16_t offsetAddress = BOARD_EEPROM_HEADER_ADDR;
    uint8_t rdBuff[3];
    char txBuf[2] = {0x00, 0x00};
    bool status;

    I2C_transactionInit(&i2cTransaction);

    handle = Board_getI2CHandle(gBoardI2cInitCfg.socDomain,
                                gBoardI2cInitCfg.i2cInst);
    if(handle == NULL)
    {
        ret = BOARD_I2C_OPEN_FAIL;
    }

    i2cTransaction.slaveAddress = slaveAddress;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = 2;

    /* Get header info */
    txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress)>>8);
    txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
    i2cTransaction.readBuf = &info->headerInfo;
    i2cTransaction.readCount = BOARD_EEPROM_HEADER_FIELD_SIZE;

    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        Board_i2cDeInit();
        return ret;
    }

    /* Checking whether the board contents are flashed or not */
    if (info->headerInfo.magicNumber == BOARD_EEPROM_MAGIC_NUMBER)
    {
        offsetAddress = offsetAddress + i2cTransaction.readCount;
        txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress) >> 8);
        txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
        i2cTransaction.readBuf = &info->boardInfo;
        i2cTransaction.readCount = BOARD_EEPROM_TYPE_SIZE +
                                    BOARD_EEPROM_STRUCT_LENGTH_SIZE;
        status = I2C_transfer(handle, &i2cTransaction);
        if (status == false)
        {
            ret = BOARD_I2C_TRANSFER_FAIL;
            Board_i2cDeInit();
            return ret;
        }

        offsetAddress = offsetAddress + i2cTransaction.readCount;
        txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress) >> 8);
        txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
        i2cTransaction.readBuf = info->boardInfo.boardName;
        i2cTransaction.readCount = info->boardInfo.boardInfoLength;

        status = I2C_transfer(handle, &i2cTransaction);
        if (status == false)
        {
            ret = BOARD_I2C_TRANSFER_FAIL;
            Board_i2cDeInit();
            return ret;
        }

        offsetAddress = offsetAddress + i2cTransaction.readCount;
        txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress) >> 8);
        txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
        i2cTransaction.readBuf = &rdBuff[0];
        i2cTransaction.readCount = BOARD_EEPROM_TYPE_SIZE +
                                    BOARD_EEPROM_STRUCT_LENGTH_SIZE;

        status = I2C_transfer(handle, &i2cTransaction);
        if (status == false)
        {
            ret = BOARD_I2C_TRANSFER_FAIL;
            Board_i2cDeInit();
            return ret;
        }

        /* Checking whether DDR field is present or not */
        if (rdBuff[0] == BOARD_DDR_FIELD_TYPE)
        {
            memcpy(&info->ddrInfo, &rdBuff[0], sizeof(rdBuff));

            offsetAddress = offsetAddress + i2cTransaction.readCount;
            txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress)>>8);
            txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
            i2cTransaction.readBuf = &info->ddrInfo.ddrCtrl;
            i2cTransaction.readCount = info->ddrInfo.ddrStructLen;

            status = I2C_transfer(handle, &i2cTransaction);
            if (status == false)
            {
                ret = BOARD_I2C_TRANSFER_FAIL;
                Board_i2cDeInit();
                return ret;
            }

            offsetAddress = offsetAddress + i2cTransaction.readCount;
            txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress) >> 8);
            txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
            i2cTransaction.readBuf = &rdBuff[0];
            i2cTransaction.readCount = BOARD_EEPROM_TYPE_SIZE +
                                        BOARD_EEPROM_STRUCT_LENGTH_SIZE;
            status = I2C_transfer(handle, &i2cTransaction);
            if (status == false)
            {
                ret = BOARD_I2C_TRANSFER_FAIL;
                Board_i2cDeInit();
                return ret;
            }
        }

        /* Checking whether MAC id field is present or not */
        if(rdBuff[0] == BOARD_MACINFO_FIELD_TYPE)
        {
            memcpy(&info->macInfo, &rdBuff[0], sizeof(rdBuff));

            offsetAddress = offsetAddress + i2cTransaction.readCount;
            txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress) >> 8);
            txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
            i2cTransaction.readBuf = &info->macInfo.macControl;
            i2cTransaction.readCount = info->macInfo.macLength;

            status = I2C_transfer(handle, &i2cTransaction);
            if (status == false)
            {
                ret = BOARD_I2C_TRANSFER_FAIL;
                Board_i2cDeInit();
                return ret;
            }

            offsetAddress = offsetAddress + i2cTransaction.readCount;
            txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress)>>8);
            txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
            i2cTransaction.readBuf = &rdBuff[0];
            i2cTransaction.readCount = BOARD_EEPROM_TYPE_SIZE;

            status = I2C_transfer(handle, &i2cTransaction);
            if (status == false)
            {
                ret = BOARD_I2C_TRANSFER_FAIL;
                Board_i2cDeInit();
                return ret;
            }
        }

        if(rdBuff[0] == BOARD_ENDLIST)
        {
            info->endList = rdBuff[0];
        }
    }
    else
    {
        ret = BOARD_INVALID_PARAM;
        Board_i2cDeInit();
        return ret;
    }

    Board_i2cDeInit();

    return ret;
}

/**
 *  @brief  This function is not supported by this platform.
 *
 *  Function implementation for build backward compatibilty.
 *  Always returns 'BOARD_UNSUPPORTED_FEATURE'
 *
 */
Board_STATUS Board_writeIDInfo(Board_IDInfo *info)
{
    return BOARD_UNSUPPORTED_FEATURE;
}

/**
 *  @brief  Write board id contents to specific EEPROM.
 *
 *  This function requires the information of I2C instance and domain
 *  to which board ID EEPROM is connected. This need to be set using
 *  Board_setI2cInitConfig() before calling this function.
 *
 *  @param[out] Board_STATUS
 *    Returns status on API call
 * @param[out] info
 *    Structure contain board id contents to write
 *  @param[in] slaveAddress
 *    Address of eeprom
 *
 */
Board_STATUS Board_writeIDInfo_v2(Board_IDInfo_v2 *info, uint8_t slaveAddress)
{
    Board_STATUS ret = BOARD_SOK;
    I2C_Transaction i2cTransaction;
    I2C_Handle handle = NULL;
    uint16_t offsetAddress = BOARD_EEPROM_HEADER_ADDR;
    char txBuf[BOARD_EEPROM_MAX_BUFF_LENGTH + 2 + 1];
    bool status;

    /* Checking the structure is valid or not */
    if (info->headerInfo.magicNumber != BOARD_EEPROM_MAGIC_NUMBER)
    {
        ret = BOARD_INVALID_PARAM;
        return ret;
    }

    I2C_transactionInit(&i2cTransaction);

    handle = Board_getI2CHandle(gBoardI2cInitCfg.socDomain,
                                gBoardI2cInitCfg.i2cInst);
    if(handle == NULL)
    {
        ret = BOARD_I2C_OPEN_FAIL;
    }

    /* Transferring Header and Board Info field */
    i2cTransaction.slaveAddress = slaveAddress;
    i2cTransaction.writeBuf = &txBuf[0];
    i2cTransaction.writeCount = BOARD_EEPROM_HEADER_FIELD_SIZE +
                                BOARD_EEPROM_TYPE_SIZE +
                                BOARD_EEPROM_STRUCT_LENGTH_SIZE +
                                info->boardInfo.boardInfoLength;
    txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress) >> 8);
    txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
    memcpy(&txBuf[2], &info->headerInfo, i2cTransaction.writeCount);

    i2cTransaction.readBuf = NULL;
    i2cTransaction.readCount = 0;

    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        Board_i2cDeInit();
        return ret;
    }

    /* Checking whether DDR field is included or not */
    if (info->ddrInfo.ddrStructType == BOARD_DDR_FIELD_TYPE)
    {
        offsetAddress = offsetAddress + i2cTransaction.writeCount;
        i2cTransaction.writeCount = info->ddrInfo.ddrStructLen +
                                     BOARD_EEPROM_TYPE_SIZE +
                                     BOARD_EEPROM_STRUCT_LENGTH_SIZE;
        txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress) >> 8);
        txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
        memcpy(&txBuf[2], &info->ddrInfo, i2cTransaction.writeCount);

        status = I2C_transfer(handle, &i2cTransaction);
        if (status == false)
        {
            ret = BOARD_I2C_TRANSFER_FAIL;
            Board_i2cDeInit();
            return ret;
        }
    }

    /* Checking whether MAC id field is included or not */
    if (info->macInfo.macStructType == BOARD_MACINFO_FIELD_TYPE)
    {
        offsetAddress = offsetAddress + i2cTransaction.writeCount;
        i2cTransaction.writeCount = info->macInfo.macLength +
                                     BOARD_EEPROM_TYPE_SIZE +
                                     BOARD_EEPROM_STRUCT_LENGTH_SIZE;
        txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress) >> 8);
        txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
        memcpy(&txBuf[2], &info->macInfo, i2cTransaction.writeCount);

        status = I2C_transfer(handle, &i2cTransaction);
        if (status == false)
        {
            ret = BOARD_I2C_TRANSFER_FAIL;
            Board_i2cDeInit();
            return ret;
        }
    }

    offsetAddress = offsetAddress + i2cTransaction.writeCount;
    i2cTransaction.writeCount = BOARD_EEPROM_TYPE_SIZE;
    txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress)>>8);
    txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
    memcpy(&txBuf[2], &info->endList, i2cTransaction.writeCount);

    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        Board_i2cDeInit();
        return ret;
    }

    Board_i2cDeInit();
    return ret;
}
