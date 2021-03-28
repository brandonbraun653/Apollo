/**
 *  \file   main_test.c
 *
 *  \brief  Example application main file. This application will read the data
 *          from eeprom and compares it with the known data.
 *
 */

/*
 * Copyright (C) 2018 Texas Instruments Incorporated - http://www.ti.com/
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

#include <ti/drv/i2c/test/firmware_test/src/test_utils.h>

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

#if defined (idkAM572x) || defined (idkAM574x)
char eepromTestData[I2C_EEPROM_TEST_LENGTH] = {0xD5, 0x33, 0xEE, 0x41, 0x4D, 0x35, 0x37, 0x32, 0x49, 0x44};
#elif defined (idkAM571x)
char eepromTestData[I2C_EEPROM_TEST_LENGTH] = {0x55, 0x33, 0xEE, 0x41, 0x4D, 0x35, 0x37, 0x31, 0x49, 0x44};
#elif defined (SOC_AM335x) || defined (SOC_AM437x)
char eepromTestData[I2C_EEPROM_TEST_LENGTH] = {0x55, 0x33, 0xEE, 0x41, 0x4D, 0x35, 0x37, 0x31, 0x49, 0x44};
#endif

#if defined (idkAM437x)
#define I2C_NUM_PRU_GPIO_PINS_UNUSED_PER_I2C    ( 2 )   // number of ICSS PRU GPO pins unused per I2C instance
#define I2C_MAX_NUM_TEST_INSTANCE               ( 2 )   // maximum number test I2C instances
#define I2C_NUM_PRU_GPIO_PINS_UNUSED            ( I2C_NUM_PRU_GPIO_PINS_UNUSED_PER_I2C * I2C_MAX_NUM_TEST_INSTANCE )
static I2C_PRU_IOPinMuxAttrs i2cPruGpioPinsUnused[I2C_NUM_PRU_GPIO_PINS_UNUSED] = 
{
#if !defined (AM437X_ICSS0)
    // These AM437x IDK ICSS0 pins are unused.
    {0x44E108F0,  8, 0x6, 0x5}, // I2C0 sclOutputPin
    {0x44E108F4,  9, 0x6, 0x5}, // I2C0 sdaInputPin
    {0x44E108F8, 10, 0x6, 0x5}, // I2C1 sclOutputPin
    {0x44E108FC, 11, 0x6, 0x5}, // I2C1 sdaInputPin
#else   // AM437X_ICSS0
    // These AM437x IDK ICSS1 pins are unused.
    {0x44E10880,  8, 0x6, 0x5}, // I2C0 sclOutputPin
    {0x44E10884,  9, 0x6, 0x5}, // I2C0 sdaInputPin
    {0x44E10830, 10, 0x6, 0x9}, // I2C1 sclOutputPin
    {0x44E10834, 11, 0x6, 0x9}, // I2C1 sdaInputPin
#endif  // AM437X_ICSS0
};
#endif

void printTestCase(uint32_t testId, uint32_t i2cInst, I2C_BitRate dataRate)
{
    I2C_log("\n I2C Test%d: Instance %d: ", testId, i2cInst);
    switch(dataRate)
    {
        case I2C_100kHz:
                I2C_log("Baud Rate 100KHz: \n");
                break;
        case I2C_400kHz:
                I2C_log("Baud Rate 400KHz: \n");
                break;
        case I2C_1P0Mhz:
#if !defined(AM437X_ICSS0)        
                I2C_log("Baud Rate 1MHz: \n");
#else
                I2C_log("AM437x ICSS0: Baud Rate 781.25 kHz: \n");
#endif            
                break;
        default:
                I2C_log("Baud Rate invalid: \n");
                break;
    }
}

extern I2C_config_list I2C_config;

/*
 *  ======== test function ========
 */
int32_t i2c_feature_test(uint32_t i2cInst, I2C_BitRate dataRate, uint32_t slaveAddr, bool smbusEnable)
{
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;
    I2C_Transaction i2cTransaction;
    char txBuf[I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE] = {0x00, };
    char rxBuf[4*I2C_EEPROM_TEST_LENGTH];
    bool copyStatus;
    int32_t status;
    int32_t controlStatus;
    int32_t retVal = 0;
    uint32_t slaveAddress, delayValue;
    I2C_TransactionCmd testCmd;

    /* Set the I2C EEPROM write/read address */
    txBuf[0] = (I2C_EEPROM_TEST_ADDR >> 8) & 0xff; /* EEPROM memory high address byte */
    txBuf[1] = I2C_EEPROM_TEST_ADDR & 0xff;        /* EEPROM memory low address byte */
    memcpy(&txBuf[I2C_EEPROM_ADDR_SIZE], eepromTestData, I2C_EEPROM_TEST_LENGTH);

    ///I2C_log("\n size of I2C_config %d. \n", sizeof(I2C_config));
    I2C_init();

    I2C_Params_init(&i2cParams);
    
    /* BitRate : 400 Kbps */
    i2cParams.bitRate = dataRate;

    handle = I2C_open(i2cInst, &i2cParams);
    if(handle == NULL)
    {
        I2C_log("\n Error: I2C open has failed. \n");
        retVal = -1;
    }

    if((retVal == 0) && (false == smbusEnable))
    {
        /* Write to EEPROM */
        I2C_transactionInit(&i2cTransaction);
        i2cTransaction.slaveAddress = slaveAddr;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE;
        i2cTransaction.readBuf = NULL;
        i2cTransaction.readCount = 0;
        i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
        status = I2C_transfer(handle, &i2cTransaction);

        if(I2C_STS_SUCCESS != status)
        {
            I2C_log("\n Error: Standard Write Data Transfer failed. \n");
            retVal = -1;
        }

        Sleep(1000);
    }

    if((retVal == 0) && (false == smbusEnable))
    {
        /* Read from EEPROM */
        memset(rxBuf, 0, I2C_EEPROM_TEST_LENGTH);
        I2C_transactionInit(&i2cTransaction);
        i2cTransaction.slaveAddress = slaveAddr;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
        i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
        i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH;
        i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
        status = I2C_transfer(handle, &i2cTransaction);

        if(I2C_STS_SUCCESS != status)
        {
            I2C_log("\n Error: Standard Read Data Transfer failed. \n");
            retVal = -1;
        }
        else
        {
            copyStatus = CompareData(&eepromTestData[0], &rxBuf[0], I2C_EEPROM_TEST_LENGTH);
            if(TRUE != copyStatus)
            {
                I2C_log("\n Error: Standard Data Mismatch \n");
                retVal = -1;
            }
        }
    }

    if((retVal == 0) && (false == smbusEnable))
    {
        /* Set the command for Loopback mode */
        testCmd.transferCmd = STANDARD_LOOPBACK_CMD;
        testCmd.cmdCode = 0U;
        controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
        
        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            /* Read from EEPROM */
            memset(rxBuf, 0, I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE);
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
            i2cTransaction.writeCount = I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE;
            i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
            i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE;
            i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: Loopback Data Transfer failed. \n");
                retVal = -1;
            }
            else
            {
                copyStatus = CompareData(&txBuf[0], &rxBuf[0], I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE);
                if(TRUE != copyStatus)
                {
                    I2C_log("\n Error: Loopback Data Mismatch \n");
                    retVal = -1;
                }
            }
        }
        else
        {
            I2C_log("\n Error: Standard Loopback control command failed. \n");
            retVal = -1;
        }
    }

    if((retVal == 0) && (true == smbusEnable))
    {
        /* Test bus recovery functionality */
        delayValue = 2000U;
        controlStatus = I2C_control(handle, I2C_CMD_RECOVER_BUS, &delayValue);

        /* Set the command for quick command mode */
        testCmd.transferCmd = SMBUS_QUICK_CMD;
        testCmd.cmdCode = 0U;
        controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
        
        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            /* Write SMBUS_QUICK_CMD */
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.timeout = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: smbus quick Command failed. \n");
                retVal = -1;
            }
        }
        else
        {
            I2C_log("\n Error: quick command control setup failed. \n");
            retVal = -1;
        }
    }

    if((retVal == 0) && (true == smbusEnable))
    {
        /* Set the command for send byte mode */
        testCmd.transferCmd = SMBUS_SEND_BYTE_CMD;
        testCmd.cmdCode = 0U;
        controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
        
        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            /* Write SMBUS_SEND_BYTE_CMD */
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.writeBuf = (uint8_t *)&txBuf[2];
            i2cTransaction.readBuf = NULL;
            i2cTransaction.timeout = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: smbus send byte Command failed. \n");
                retVal = -1;
            }
        }
        else
        {
            I2C_log("\n Error: send byte command control setup failed. \n");
            retVal = -1;
        }
    }

    if((retVal == 0) && (true == smbusEnable))
    {
        /* Set the command for receive byte mode */
        testCmd.transferCmd = SMBUS_RECEIVE_BYTE_CMD;
        testCmd.cmdCode = 0U;
        controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
        
        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            /* Write SMBUS_RECEIVE_BYTE_CMD */
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.writeBuf = NULL;
            i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
            i2cTransaction.timeout = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: smbus recieve byte Command failed. \n");
                retVal = -1;
            }
        }
        else
        {
            I2C_log("\n Error: recieve byte command control setup failed. \n");
            retVal = -1;
        }
    }

    if((retVal == 0) && (true == smbusEnable))
    {
        /* Set the command for write byte mode */
        testCmd.transferCmd = SMBUS_WRITE_BYTE_CMD;
        testCmd.cmdCode = WRITE_SMBUS_COMMAND_CODE;
        controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
        
        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            /* Write SMBUS_WRITE_BYTE_CMD */
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.writeBuf = (uint8_t *)&txBuf[2];
            i2cTransaction.readBuf = NULL;
            i2cTransaction.timeout = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: smbus write byte Command failed. \n");
                retVal = -1;
            }
        }
        else
        {
            I2C_log("\n Error: write byte command control setup failed. \n");
            retVal = -1;
        }
    }

    if((retVal == 0) && (true == smbusEnable))
    {
        /* Set the command for read byte mode */
        testCmd.transferCmd = SMBUS_READ_BYTE_CMD;
        testCmd.cmdCode = READ_SMBUS_COMMAND_CODE;
        controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
        
        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            /* Write SMBUS_READ_BYTE_CMD */
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.writeBuf = NULL;
            i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
            i2cTransaction.timeout = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: smbus read byte Command failed. \n");
                retVal = -1;
            }
        }
        else
        {
            I2C_log("\n Error: read byte command control setup failed. \n");
            retVal = -1;
        }
    }

    if((retVal == 0) && (true == smbusEnable))
    {
        /* Set the command for write word mode */
        testCmd.transferCmd = SMBUS_WRITE_WORD_CMD;
        testCmd.cmdCode = WRITE_SMBUS_COMMAND_CODE;
        controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
        
        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            /* Write SMBUS_WRITE_WORD_CMD */
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.writeBuf = (uint8_t *)&txBuf[2];
            i2cTransaction.readBuf = NULL;
            i2cTransaction.timeout = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: smbus write word Command failed. \n");
                retVal = -1;
            }
        }
        else
        {
            I2C_log("\n Error: write word command control setup failed. \n");
            retVal = -1;
        }
    }

    if((retVal == 0) && (true == smbusEnable))
    {
        /* Set the command for read word mode */
        testCmd.transferCmd = SMBUS_READ_WORD_CMD;
        testCmd.cmdCode = READ_SMBUS_COMMAND_CODE;
        controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
        
        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            /* Write SMBUS_READ_WORD_CMD */
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.writeBuf = NULL;
            i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
            i2cTransaction.timeout = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: smbus read word Command failed. \n");
                retVal = -1;
            }
        }
        else
        {
            I2C_log("\n Error: read word command control setup failed. \n");
            retVal = -1;
        }
    }

    if((retVal == 0) && (true == smbusEnable))
    {
        /* Set the command for block write mode */
        testCmd.transferCmd = SMBUS_BLOCK_WRITE_CMD;
        testCmd.cmdCode = WRITE_SMBUS_COMMAND_CODE;
        controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
        
        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            /* Write SMBUS_BLOCK_WRITE_CMD */
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.writeBuf = (uint8_t *)&txBuf[2];
            i2cTransaction.writeCount = 3;
            i2cTransaction.readBuf = NULL;
            i2cTransaction.timeout = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: smbus block write Command failed. \n");
                retVal = -1;
            }
        }
        else
        {
            I2C_log("\n Error: block write command control setup failed. \n");
            retVal = -1;
        }
    }

    if((retVal == 0) && (true == smbusEnable))
    {
        /* Set the command for block read mode */
        testCmd.transferCmd = SMBUS_BLOCK_READ_CMD;
        testCmd.cmdCode = READ_SMBUS_COMMAND_CODE;
        controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
        
        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            /* Write SMBUS_BLOCK_READ_CMD */
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.writeBuf = NULL;
            i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
            i2cTransaction.readCount = 0;
            i2cTransaction.timeout = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: smbus block read Command failed. \n");
                retVal = -1;
            }
        }
        else
        {
            I2C_log("\n Error: block read command control setup failed. \n");
            retVal = -1;
        }
    }

    /* Test Probe functionality */
    if((retVal == 0) && (false == smbusEnable))
    {
        /* Probe test with valid slave address */
        slaveAddress = slaveAddr;
        controlStatus = I2C_control(handle, I2C_CMD_PROBE, &slaveAddress);

        if(I2C_STATUS_SUCCESS != controlStatus)
        {
            I2C_log("\n Error: Probe test failed for valid address. \n");
            retVal = -1;
        }

        Sleep(500);
    }

    if((retVal == 0) && (false == smbusEnable))
    {
        /* Probe test with invalid slave address */
        slaveAddress = 0x70U;
        controlStatus = I2C_control(handle, I2C_CMD_PROBE, &slaveAddress);

        if(I2C_STATUS_ERROR != controlStatus)
        {
            I2C_log("\n Error: Probe test failed for invalid address. \n");
            retVal = -1;
        }

        Sleep(500);
    }

    if((retVal == 0) && (false == smbusEnable))
    {
        /* Write to EEPROM */
        I2C_transactionInit(&i2cTransaction);
        i2cTransaction.slaveAddress = slaveAddr;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = 512;
        i2cTransaction.readBuf = NULL;
        i2cTransaction.readCount = 0;
        i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
        status = I2C_transfer(handle, &i2cTransaction);

        if(I2C_STS_ERR_COMMAND_FAILURE != status)
        {
            I2C_log("\n Error: Buffer overflow error did not happened. \n");
            retVal = -1;
        }

        Sleep(1000);
    }

    if((retVal == 0) && (false == smbusEnable))
    {
        /* Test bus recovery functionality */
        delayValue = 2000U;
        controlStatus = I2C_control(handle, I2C_CMD_RECOVER_BUS, &delayValue);

        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            memset(rxBuf, 0, I2C_EEPROM_TEST_LENGTH);
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = slaveAddr;
            i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
            i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
            i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
            i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH;
            i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
            status = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != status)
            {
                I2C_log("\n Error: Bus recovery read failed. \n");
                retVal = -1;                
            }
            else
            {
                copyStatus = CompareData(&eepromTestData[0], &rxBuf[0], I2C_EEPROM_TEST_LENGTH);
                if(TRUE != copyStatus)
                {
                    I2C_log("\n Error: Bus recovery Data Mismatch \n");
                    retVal = -1;
                }
            }
        }
        else
        {
            I2C_log("\n Error: Bus recovery failed. \n");
            retVal = -1;
        }
    }

    if((retVal == 0) && (false == smbusEnable))
    {
        /* Read from EEPROM */
        memset(rxBuf, 0, I2C_EEPROM_TEST_LENGTH);
        I2C_transactionInit(&i2cTransaction);
        i2cTransaction.slaveAddress = slaveAddr;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
        i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
        i2cTransaction.readCount = 16*I2C_EEPROM_TEST_LENGTH;
        i2cTransaction.timeout   = 1;
        status = I2C_transfer(handle, &i2cTransaction);

        if(I2C_STS_ERR_TIMEOUT != status)
        {
            I2C_log("\n Error: Standard timeout test failed. \n");
            retVal = -1;
        }
    }

    I2C_close(handle);

    return retVal;
}

/*
 *  ======== CompareData ========
 */
bool CompareData(char *expData, char *rxData, unsigned int length)
{
    uint32_t idx = 0;
    uint32_t match = 1;
    bool retVal = false;

    for(idx = 0; ((idx < length) && (match != 0)); idx++)
    {
        if(*expData != *rxData) match = 0;
        expData++;
        rxData++;
    }

    if(match == 1) retVal = true;

    return retVal;
}

#if defined(idkAM437x)
/* Configure pin mux for unused I2C PRU GPI/GPO pins */
void pruGpioMuxConfigI2cUnused(void)
{
    uint32_t idx;
    uint32_t regVal;
    
#ifdef I2C_TEST_INSTANCE1    
    for (idx = 0; idx < I2C_NUM_PRU_GPIO_PINS_UNUSED_PER_I2C; idx++)
    {
        regVal = *(volatile uint32_t *)(i2cPruGpioPinsUnused[idx].baseRegAddr);        
        regVal &= I2C_PRU_GPI_SELECT_MASK;
        regVal |= I2C_PRU_GPI_INPUT_ENABLE;
        regVal |= (uint32_t)(i2cPruGpioPinsUnused[idx].inputModeVal);
        *(volatile uint32_t *)(i2cPruGpioPinsUnused[idx].baseRegAddr) = regVal;
    }
#endif

#ifdef I2C_TEST_INSTANCE2
    for (idx = I2C_NUM_PRU_GPIO_PINS_UNUSED_PER_I2C; idx < I2C_NUM_PRU_GPIO_PINS_UNUSED; idx++)
    {
        regVal = *(volatile uint32_t *)(i2cPruGpioPinsUnused[idx].baseRegAddr);        
        regVal &= I2C_PRU_GPI_SELECT_MASK;
        regVal |= I2C_PRU_GPI_INPUT_ENABLE;
        regVal |= (uint32_t)(i2cPruGpioPinsUnused[idx].inputModeVal);
        *(volatile uint32_t *)(i2cPruGpioPinsUnused[idx].baseRegAddr) = regVal;
    }
#endif
}
#endif // defined(idkAM437x)
