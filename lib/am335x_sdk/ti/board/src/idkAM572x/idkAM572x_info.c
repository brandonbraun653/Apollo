/******************************************************************************
 * Copyright (c) 2010-2015 Texas Instruments Incorporated - http://www.ti.com
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
#include <string.h>
#include "board_internal.h"
#include "board_cfg.h"

/*
 *  ======== Board_getIDInfo ========
 */
Board_STATUS Board_getIDInfo(Board_IDInfo *info) {
    Board_STATUS ret = BOARD_SOK;
    I2C_Transaction i2cTransaction;
    I2C_Handle handle = NULL;
    char txBuf[2] = {0x00, 0x00};
    bool status;

    I2C_transactionInit(&i2cTransaction);

    /* If handle not opened yet, init i2c */
    if (Board_obj.i2cHandle == NULL)
    {
        ret = Board_internalInitI2C();
    }
    if (ret != BOARD_SOK)
        return ret;

    handle = Board_obj.i2cHandle;

    i2cTransaction.slaveAddress = BOARD_I2C_EEPROM_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = 2;

    /* Get header info */
    txBuf[0] = (char)(((uint32_t) 0xFF00 & BOARD_EEPROM_HEADER_ADDR)>>8);
    txBuf[1] = (char)((uint32_t) 0xFF & BOARD_EEPROM_HEADER_ADDR);
    i2cTransaction.readBuf = (uint8_t *) info->header;
    i2cTransaction.readCount = BOARD_EEPROM_HEADER_LENGTH;
    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;
        return ret;
    }
    info->header[BOARD_EEPROM_HEADER_LENGTH] = '\0';

    /* Get board name */
    txBuf[0] = (char)(((uint32_t) 0xFF00 & BOARD_EEPROM_BOARD_NAME_ADDR)>>8);
    txBuf[1] = (char)((uint32_t) 0xFF & BOARD_EEPROM_BOARD_NAME_ADDR);
    i2cTransaction.readBuf = (uint8_t *) info->boardName;
    i2cTransaction.readCount = BOARD_EEPROM_BOARD_NAME_LENGTH;
    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;
        return ret;
    }
    info->boardName[BOARD_EEPROM_BOARD_NAME_LENGTH] = '\0';

    /* Get board version */
    txBuf[0] = (char)(((uint32_t) 0xFF00 & BOARD_EEPROM_VERSION_ADDR)>>8);
    txBuf[1] = (char)((uint32_t) 0xFF & BOARD_EEPROM_VERSION_ADDR);
    i2cTransaction.readBuf = (uint8_t *) info->version;
    i2cTransaction.readCount = BOARD_EEPROM_VERSION_LENGTH;
    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;
        return ret;
    }
    info->version[BOARD_EEPROM_VERSION_LENGTH] = '\0';

    /* Get header info */
    txBuf[0] = (char)(((uint32_t) 0xFF00 & BOARD_EEPROM_SERIAL_NO_ADDR)>>8);
    txBuf[1] = (char)((uint32_t) 0xFF & BOARD_EEPROM_SERIAL_NO_ADDR);
    i2cTransaction.readBuf = (uint8_t *) info->serialNum;
    i2cTransaction.readCount = BOARD_EEPROM_SERIAL_NO_LENGTH;
    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;
        return ret;
    }
    info->serialNum[BOARD_EEPROM_SERIAL_NO_LENGTH] = '\0';

    /* Get PRU-ICSS MAC address */
    txBuf[0] = (char)(((uint32_t) 0xFF00 & BOARD_EEPROM_MACADDR_ADDR) >> 8);
    txBuf[1] = (char)((uint32_t) 0xFF & BOARD_EEPROM_MACADDR_ADDR);
    i2cTransaction.readBuf = (uint8_t *) info->indEthMacID0;
    i2cTransaction.readCount = BOARD_EEPROM_MACADDR_LENGTH;
    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;
        return ret;
    }
    info->serialNum[BOARD_EEPROM_MACADDR_LENGTH] = '\0';

    I2C_close(handle);
    Board_obj.i2cHandle = NULL;

    return ret;
}

/*
 *  ======== Board_writeIDInfo ========
 */
Board_STATUS Board_writeIDInfo(Board_IDInfo *info) {
    Board_STATUS ret = BOARD_SOK;
    I2C_Transaction i2cTransaction;
    I2C_Handle handle = NULL;
    char txBuf[2+BOARD_EEPROM_HEADER_LENGTH+BOARD_EEPROM_BOARD_NAME_LENGTH
        +BOARD_EEPROM_VERSION_ADDR+BOARD_EEPROM_SERIAL_NO_LENGTH];
    bool status;
    int i, idx;

    memset(&i2cTransaction, 0, sizeof(i2cTransaction));

    /* If handle not opened yet, init i2c */
    if (Board_obj.i2cHandle == NULL)
    {
        ret = Board_internalInitI2C();
    }
    if (ret != BOARD_SOK)
        return ret;

    handle = Board_obj.i2cHandle;

    i2cTransaction.slaveAddress = BOARD_I2C_EEPROM_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = 2;

    /* write header info */
    txBuf[0] = (char)(((uint32_t) 0xFF00 & BOARD_EEPROM_HEADER_ADDR)>>8);
    txBuf[1] = (char)((uint32_t) 0xFF & BOARD_EEPROM_HEADER_ADDR);
    i2cTransaction.readCount = 0;
    idx = 2;
    for (i = 0; i<BOARD_EEPROM_HEADER_LENGTH; i++) txBuf[idx++] = info->header[i];
    for (i = 0; i<BOARD_EEPROM_BOARD_NAME_LENGTH; i++) txBuf[idx++] = info->boardName[i];
    for (i = 0; i<BOARD_EEPROM_VERSION_ADDR; i++) txBuf[idx++] = info->version[i];
    for (i = 0; i<BOARD_EEPROM_SERIAL_NO_LENGTH; i++) txBuf[idx++] = info->serialNum[i];
    status = I2C_transfer(handle, &i2cTransaction);
    if (status == false)
    {
        ret = BOARD_I2C_TRANSFER_FAIL;
        I2C_close(handle);
        Board_obj.i2cHandle = NULL;
        return ret;
    }
    info->header[BOARD_EEPROM_HEADER_LENGTH] = '\0';

    I2C_close(handle);
    Board_obj.i2cHandle = NULL;
    
    return ret;
}

/* Function to differentiate between AM574x and AM572x silicon 
* 
*	Currently there is a spec issue with CTRL_WKUP_STD_FUSE_DIE_ID_2
*	Values used below are based on EFUSE programming detected on existing parts.
*/
socId_t Board_soc_detect()
{
    uint32_t part_no = (*(uint32_t *)(CSL_MPU_CTRL_MODULE_WKUP_CORE_REGISTERS_REGS + CTRL_WKUP_STD_FUSE_DIE_ID_2) & 0xFF000000) >> 24;
    
	if ((part_no > 0x38) && (part_no < 0x3D))
        return SOC_ID_AM572x;     //AM572x 
    else if ((part_no > 0x59) && (part_no < 0x6D))
        return SOC_ID_AM574x;     //AM574x
    else 
        return SOC_ID_UNKNOWN;
}
