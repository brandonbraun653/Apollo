/**
 *  \file   main.c
 *
 *  \brief  Example application main file. This application will toggle the led.
 *          The led toggling will be done inside an callback function, which
 *          will be called by Interrupt Service Routine. Interrupts are
 *          triggered manually and no external source is used to trigger
 *          interrupts.
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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/uart/UART_stdio.h>

#include "board.h"
#include "board_cfg.h"
#if defined(SOC_J721E)
#include "board_utils.h"
#endif

#if defined(SOC_J721E)
#include "diag_common_cfg.h"
#include <ti/csl/soc.h>
#endif

typedef struct pmic_data
{
    uint8_t   slaveAddr;
    uint8_t   i2cInstance;
    uint8_t   pmicIdReg;
    uint8_t   pmicIdPage;
    uint8_t   pmicReg;
    uint8_t   pmicVoltVal;
    uint8_t   pwdProtReg;
    uint8_t   pmicDevCtrl;
}pmic_data_t;

#if defined(SOC_J721E)
Board_I2cInitCfg_t boardI2cInitCfg = {0, BOARD_SOC_DOMAIN_WKUP, false};
#endif
int32_t numPmic = 0;

/*********************************  *************************************
 ************************** Internal functions ************************
 **********************************************************************/

pmic_data_t* Get_PmicData(char *pBoardName);
 
extern I2C_config_list I2C_config;

/* Board specific definitions */
#define I2C_INSTANCE                       (0U)
#if defined(SOC_J721E)
#define BOARD_NAME_LENGTH                  (16)
#else
#define BOARD_NAME_LENGTH                  (8)
#endif

/* TPS659037 Register values. */
#define TPS659037_I2C_SLAVE_ADDR           (0x59U)
#define TPS659037_PMICID_REG               (0x4FU)
#define TPS659037_PMIC_PAGEID              (0x02U)
#define TPS659037_PMIC_REG                 (0x23U)
#define TPS659037_PMIC_VOLTAGE_VAL         (0x44U)

/* TPS65910 Register values. */
#define TPS65910_I2C_SLAVE_ADDR            (0x2D)
#define TPS65910_PMICID_REG                (0x80)
#define TPS65910_PMIC_PAGEID               (0x00U)
#define TPS65910_PMIC_REG                  (0x22U)
#define TPS65910_PMIC_VOLTAGE_VAL          (0x27U)
#define TPS65910_PMIC_DEV_CTRL             (0x3F)

#define PMIC_DEVCTRL_REG_SR_CTL_I2C_SEL             (0x10u)
#define PMIC_DEVCTRL_REG_SR_CTL_I2C_SEL_SHIFT       (0x04u)
#define PMIC_DEVCTRL_REG_SR_CTL_I2C_SEL_SR_I2C      (0x0u)
#define PMIC_DEVCTRL_REG_SR_CTL_I2C_SEL_CTL_I2C     (0x1u)

/* TPS65218 Register values. */
#define TPS65218_I2C_SLAVE_ADDR            (0x24)
#define TPS65218_PMICID_REG                (0x00U)
#define TPS65218_PMIC_PAGEID               (0x00U)
#define TPS65218_PMIC_REG                  (0x16U)
#define TPS65218_PMIC_VOLTAGE_VAL          (0x19U)
#define TPS65218_PWD_REG                   (0x10)

#define TPS65218_PROT_PWD                  (0x7DU)

/* TPS65917 Register value. */
#define TPS65917_I2C_SLAVE_ADDR            (0x58U)
#define TPS65917_PMICID_REG                (0x4FU)
#define TPS65917_PMIC_PAGEID               (0x02U)
#define TPS65917_PMIC_REG                  (0x23U)
#define TPS65917_PMIC_VOLTAGE_VAL          (0x44U)

/* TPS65941 Register value */
#define TPS65941_PMICA_I2C_SLAVE_ADDR      (0x48U)
#define TPS65941_PMICB_I2C_SLAVE_ADDR      (0x4CU)
#define TPS65941_PMICID_REG                (0x01U)
#define TPS65941_PMIC_REG                  (0x0EU)
#define TPS65941_PMIC_VOLTAGE_VAL          (0x41U)

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

pmic_data_t tps65910 = {
    TPS65910_I2C_SLAVE_ADDR,
    I2C_INSTANCE,
    TPS65910_PMICID_REG,
    TPS65910_PMIC_PAGEID,
    TPS65910_PMIC_REG,
    TPS65910_PMIC_VOLTAGE_VAL,
    0U,
    TPS65910_PMIC_DEV_CTRL
};

pmic_data_t tps65218 = {
    TPS65218_I2C_SLAVE_ADDR,
    I2C_INSTANCE,
    TPS65218_PMICID_REG,
    TPS65218_PMIC_PAGEID,
    TPS65218_PMIC_REG,
    TPS65218_PMIC_VOLTAGE_VAL,
    TPS65218_PWD_REG,
    0U
};

pmic_data_t tps659037 = {
    TPS659037_I2C_SLAVE_ADDR,
    I2C_INSTANCE,
    TPS659037_PMICID_REG,
    TPS659037_PMIC_PAGEID,
    TPS659037_PMIC_REG,
    TPS659037_PMIC_VOLTAGE_VAL,
    0U,
    0U
};

pmic_data_t tps65917 = {
    TPS65917_I2C_SLAVE_ADDR,
    I2C_INSTANCE,
    TPS65917_PMICID_REG,
    TPS65917_PMIC_PAGEID,
    TPS65917_PMIC_REG,
    TPS65917_PMIC_VOLTAGE_VAL,
    0U,
    0U
};

pmic_data_t tps65941_pmicA = {
    TPS65941_PMICA_I2C_SLAVE_ADDR,
    I2C_INSTANCE,
    TPS65941_PMICID_REG,
    0U,
    TPS65941_PMIC_REG,
    TPS65941_PMIC_VOLTAGE_VAL,
    0U,
    0U
};

pmic_data_t tps65941_pmicB = {
    TPS65941_PMICB_I2C_SLAVE_ADDR,
    I2C_INSTANCE,
    TPS65941_PMICID_REG,
    0U,
    TPS65941_PMIC_REG,
    TPS65941_PMIC_VOLTAGE_VAL,
    0U,
    0U
};

void setPmicVoltage(I2C_Handle h, pmic_data_t *pPmicData, uint8_t val)
{
    uint8_t tx[2];
    I2C_Transaction t;

    memset(&t, 0, sizeof(t));
    t.slaveAddress = pPmicData->slaveAddr;
    t.writeBuf = tx;
    #if defined (SOC_AM437x)
        /* Unlock the password protected register. */
        tx[0] = pPmicData->pwdProtReg;
        tx[1] = (pPmicData->pmicReg ^ TPS65218_PROT_PWD);
        t.writeCount = 2;
        I2C_transfer(h, &t);
        /* Write the actual value. */
        tx[0] = pPmicData->pmicReg;
        tx[1] = val;
        I2C_transfer(h, &t);
    #else
    t.writeCount = 2;
    t.readCount = 0;
    tx[0] = pPmicData->pmicReg;
    tx[1] = val;
    I2C_transfer(h, &t);
    #endif
}

uint8_t readPmicVoltage(I2C_Handle h, uint8_t slaveAddr, uint8_t regOffset)
{
    uint8_t tx[1];
    uint8_t rx[1];
    I2C_Transaction t;

    memset(&t, 0, sizeof(t));

    t.slaveAddress = slaveAddr;
    t.writeBuf = tx;
    t.writeCount = 1;
    t.readBuf = rx;
    t.readCount = 1;
    tx[0] = regOffset;
    I2C_transfer(h, &t);
    return rx[0];
}

#if (defined (SOC_AM572x)) || (defined (SOC_AM571x)) || defined (SOC_AM574x)
uint32_t getPmicId(I2C_Handle h, pmic_data_t *pPmicData)
{
    uint32_t val = 0;
    uint8_t tx[2];
    uint8_t rx[1];
    uint8_t reg = pPmicData->pmicIdReg;
    I2C_Transaction t;

    memset(&t, 0, sizeof(t));

    t.slaveAddress = pPmicData->slaveAddr;
    t.writeBuf = tx;
    t.writeCount = 2;
    t.readBuf = rx;
    t.readCount = 1;
    tx[0] = reg;
    tx[1] = pPmicData->pmicIdPage;
    I2C_transfer(h, &t);
    val |= (rx[0] << 24);
    tx[0] = (reg + 1);
    tx[1] = pPmicData->pmicIdPage;
    I2C_transfer(h, &t);
    val |= (rx[0] << 16);
    tx[0] = (reg + 2);
    tx[1] = pPmicData->pmicIdPage;
    I2C_transfer(h, &t);
    val |= (rx[0] << 8);
    tx[0] = (reg + 3);
    tx[1] = pPmicData->pmicIdPage;
    I2C_transfer(h, &t);
    val |= (rx[0] << 0);
    return val;
}
#endif

#if (defined (SOC_AM437x)) || (defined (SOC_AM335x))
uint32_t getPmicId(I2C_Handle h, pmic_data_t *pPmicData)
{
    uint8_t tx[2] = {0, 0};
    uint8_t rx;
    I2C_Transaction t;

    memset(&t, 0, sizeof(t));

    t.slaveAddress = pPmicData->slaveAddr;
    t.writeBuf = tx;
    t.readBuf = &rx;
    t.writeCount = 1;
    t.readCount = 0;

    /* Enable I2C access to the functional registers. */
    #if defined (SOC_AM335x)
    tx[0] = pPmicData->pmicDevCtrl;
    rx = readPmicVoltage(h, pPmicData->slaveAddr, pPmicData->pmicDevCtrl);
    rx |= (PMIC_DEVCTRL_REG_SR_CTL_I2C_SEL_CTL_I2C << PMIC_DEVCTRL_REG_SR_CTL_I2C_SEL_SHIFT);
    tx[1] = rx;
    t.writeCount = 2;
    rx = 0;
    I2C_transfer(h, &t);
    #endif

    /* Read the PMIC ID register. */
    tx[0] = pPmicData->pmicIdReg;
    t.writeCount = 1;
    t.readCount = 1;
    I2C_transfer(h, &t);

    return rx;
}
#endif

#if defined(SOC_J721E)
uint32_t getPmicId(I2C_Handle h, pmic_data_t *pPmicData)
{
    uint32_t val = 0;
    uint8_t tx[1];
    uint8_t rx[1];
    uint8_t reg = pPmicData->pmicIdReg;
    I2C_Transaction t;

    memset(&t, 0, sizeof(t));

    if(pPmicData->slaveAddr == TPS65917_I2C_SLAVE_ADDR)
    {
        t.slaveAddress = (pPmicData->slaveAddr + 1);
    }
    else /* TPS65941 */
    {
        t.slaveAddress = pPmicData->slaveAddr;
    }
    t.writeBuf = tx;
    t.writeCount = 1;
    t.readBuf = rx;
    t.readCount = 1;
    tx[0] = reg;
    I2C_transfer(h, &t);
    val |= (rx[0] << 24);

    if(pPmicData->slaveAddr == TPS65917_I2C_SLAVE_ADDR)
    {
        tx[0] = (reg + 1);
        I2C_transfer(h, &t);
        val |= (rx[0] << 16);
        tx[0] = (reg + 2);
        I2C_transfer(h, &t);
        val |= (rx[0] << 8);
        tx[0] = (reg + 3);
        I2C_transfer(h, &t);
        val |= (rx[0] << 0);
    }
    return val;
}
#endif

int pmic_test()
{
    int ret = 0;
    int i;
    uint8_t voltage, val;
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;
#if defined(SOC_J721E)
    Board_IDInfo_v2 info = {0};
#else
    Board_IDInfo boardInfo;
#endif
    pmic_data_t *pPmicData;
    int32_t stat = BOARD_SOK;

#if defined(SOC_J721E)
    Board_setI2cInitConfig(&boardI2cInitCfg);
    stat = Board_getIDInfo_v2(&info, BOARD_I2C_EEPROM_ADDR);
#else
    stat = Board_getIDInfo(&boardInfo);
#endif

    if(stat == BOARD_SOK)
    {
#if defined(SOC_J721E)
        pPmicData = Get_PmicData(info.boardInfo.boardName);
#else
        pPmicData = Get_PmicData(boardInfo.boardName);
#endif

#if defined(SOC_J721E)
        enableI2C(CSL_WKUP_I2C0_CFG_BASE);
#endif
        for (i=0; I2C_config[i].fxnTablePtr != NULL; i++)
        {
            ((I2C_HwAttrs *)I2C_config[i].hwAttrs)->enableIntr = false;
        }

        I2C_init();

        I2C_Params_init(&i2cParams);

        handle = I2C_open(pPmicData->i2cInstance, &i2cParams);

        UART_printf("\n*********************************************\n"); 
        UART_printf  ("*                PMIC Test                  *\n");
        UART_printf  ("*********************************************\n");
#if defined(SOC_J721E)
        while(numPmic)
        {
#endif
            val = pPmicData->pmicVoltVal;
            UART_printf("Testing PMIC module... \n");
            UART_printf("PMIC ID = 0x%08x\n", getPmicId(handle, pPmicData));
            voltage = readPmicVoltage(handle, pPmicData->slaveAddr, pPmicData->pmicReg);
            UART_printf("Initial PMIC voltage = 0x%x\n", voltage);
            UART_printf("Setting PMIC voltage to 0x%x\n", val);
            setPmicVoltage(handle, pPmicData, val);
            UART_printf("done!\n");
            UART_printf("PMIC voltage after = 0x%x\n", readPmicVoltage(handle, pPmicData->slaveAddr, pPmicData->pmicReg));
            UART_printf("Setting PMIC voltage to original value\n");
            setPmicVoltage(handle, pPmicData, voltage);
            UART_printf("Final voltage value = 0x%x\n", readPmicVoltage(handle, pPmicData->slaveAddr, pPmicData->pmicReg));
#if defined(SOC_J721E)
            pPmicData = &tps65941_pmicB;
            numPmic--;
        }
#endif
        UART_printf("Test PASSED!\n");
        I2C_close(handle);
    }
    return ret;
}

/* Fetch the PMIC data structure. */
pmic_data_t* Get_PmicData(char *pBoardName)
{
    pmic_data_t *pPmicData = NULL;

    /* Check if the board is GPEVM by comparing the string read from EEPROM. */
    if (strncmp("AM572PM_", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps659037;
    }
    /* Check if the board is AM572xIDK by comparing the string read from EEPROM. */
    else if (strncmp("AM572IDK", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps659037;
    }
    /* Check if the board is AM574xIDK by comparing the string read from EEPROM. */
    else if (strncmp("AM574IDK", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps659037;
    }
    /* Check if the board is AM571xIDK by comparing the string read from EEPROM. */
    else if (strncmp("AM571IDK", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps659037;
    }
    /* Check if the board is AM437x GPEVM by comparing the string read from EEPROM. */
    else if (strncmp("AM43__GP", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps65218;
    }
    /* Check if the board is AM437x HSEVM by comparing the string read from EEPROM. */
    else if (strncmp("AM43XXHS", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps65218;
    }
    /* Check if the board is SKAM437x by comparing the string read from EEPROM. */
    else if (strncmp("AM43__SK", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps65218;
    }
    /* Check if the board is AM335x GPEVM by comparing the string read from EEPROM. */
    else if (strncmp("A33515BB", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps65910;
    }
    /* Check if the board is BBBAM335x by comparing the string read from EEPROM. */
    else if (strncmp("A335BNLT", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps65910;
    }
    /* Check if the board is ICEV2AM335x by comparing the string read from EEPROM. */
    else if (strncmp("A335_ICE", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps65910;
    }
    /* Check if the board is SKAM335x by comparing the string read from EEPROM. */
    else if (strncmp("A335X_SK", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps65910;
    }
    /* Check if the board is J721E SoM with Alt PMIC by comparing the string read from EEPROM. */
    else if (strncmp("J721EX-PM1-SOM", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps65917;
        numPmic = 1;
    }
    /* Check if the board is J721E SoM with Dual PMIC by comparing the string read from EEPROM. */
    else if (strncmp("J721EX-PM2-SOM", pBoardName, BOARD_NAME_LENGTH) == 0U)
    {
        pPmicData = &tps65941_pmicA;
        numPmic = 2;
    }
    else
    {
        /* If the board is not one of these, then the PmicData returns NULL. */
    }

    return pPmicData;
}

/*
 *  ======== main ========
 */
int main(void)
{
    Board_initCfg boardCfg;
#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG | 
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);
    
	return pmic_test();
}

void AppDelay(uint32_t delayVal)
{
	uint32_t cnt = 0;
    while(cnt < delayVal)
    {
		asm("");
        cnt++;
    }
}

