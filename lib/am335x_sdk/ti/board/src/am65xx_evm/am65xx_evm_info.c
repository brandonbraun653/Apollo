/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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

#include "board_internal.h"
#include "board_cfg.h"
#include <stdio.h>
#include <string.h>

/**
 *  \brief   This function enables I2C0 for wake-up domain
 *
 */
static void enableWKUPI2C(void)
{
    I2C_HwAttrs i2cCfg;

    I2C_socGetInitCfg(0, &i2cCfg);

    i2cCfg.baseAddr = CSL_WKUP_I2C0_CFG_BASE;
    i2cCfg.enableIntr = 0;

    I2C_socSetInitCfg(0, &i2cCfg);
}

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

    /* Enable Wake-up I2C port for EEPROM access */
    enableWKUPI2C();

    /* If handle not opened yet, init i2c */
    if (Board_obj.i2cHandle == NULL)
    {
        ret = Board_internalInitI2C();
    }
    if (ret != BOARD_SOK)
        return ret;

    handle = Board_obj.i2cHandle;

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
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;
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
            I2C_close(handle);
            Board_obj.i2cHandle = NULL;
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
            I2C_close(handle);
            Board_obj.i2cHandle = NULL;
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
            I2C_close(handle);
            Board_obj.i2cHandle = NULL;
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
                I2C_close(handle);
                Board_obj.i2cHandle = NULL;
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
                I2C_close(handle);
                Board_obj.i2cHandle = NULL;
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
                I2C_close(handle);
                Board_obj.i2cHandle = NULL;
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
                I2C_close(handle);
                Board_obj.i2cHandle = NULL;
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
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;
        return ret;
    }

    I2C_close(handle);
    Board_obj.i2cHandle = NULL;

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
    uint16_t offsetSize = 2;
    char txBuf[BOARD_EEPROM_MAX_BUFF_LENGTH + 2 + 1];
    bool status;

    /* Checking the structure is valid or not */
    if (info->headerInfo.magicNumber != BOARD_EEPROM_MAGIC_NUMBER)
    {
        ret = BOARD_INVALID_PARAM;
        return ret;
    }

    I2C_transactionInit(&i2cTransaction);

    /* Enable Wake-up I2C port for EEPROM access */
    enableWKUPI2C();

    /* If handle not opened yet, init i2c */
    if (Board_obj.i2cHandle == NULL)
    {
        ret = Board_internalInitI2C();
    }
    if (ret != BOARD_SOK)
        return ret;

    handle = Board_obj.i2cHandle;

    /* Transferring Header and Board Info field */
    i2cTransaction.slaveAddress = slaveAddress;
    i2cTransaction.writeBuf = &txBuf[0];
    i2cTransaction.writeCount = BOARD_EEPROM_HEADER_FIELD_SIZE +
                                BOARD_EEPROM_TYPE_SIZE +
                                BOARD_EEPROM_STRUCT_LENGTH_SIZE +
                                info->boardInfo.boardInfoLength +
                                offsetSize;
    txBuf[0] = (char)(((uint32_t) 0xFF00 & offsetAddress) >> 8);
    txBuf[1] = (char)((uint32_t) 0xFF & offsetAddress);
    memcpy(&txBuf[2], &info->headerInfo, i2cTransaction.writeCount);

    i2cTransaction.readBuf = NULL;
    i2cTransaction.readCount = 0;

    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;
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
            I2C_close(handle);
            Board_obj.i2cHandle = NULL;
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
            I2C_close(handle);
            Board_obj.i2cHandle = NULL;
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
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;
        return ret;
    }

    I2C_close(handle);
    Board_obj.i2cHandle = NULL;
    return ret;
}

/**
 * \brief  Board check SoC PG version function
 *
 * Check if the SoC is PG1 version or not.
 *
 * \param   none
 *
 * \return  TRUE: SoC is PG1 version, FALSE: SoC is not PG1 version
 *
 */
uint32_t Board_isSocPG1(void)
{
    uint32_t retVal = TRUE;
    uint32_t jtagIdVal;
    uint32_t variatn;

    jtagIdVal = CSL_REG32_RD(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_JTAGID);
    variatn   = CSL_FEXT(jtagIdVal, WKUP_CTRL_MMR_CFG0_JTAGID_VARIATN);
    if (variatn != 0U)
    {
        retVal = FALSE;
    }

    return (retVal);
}

