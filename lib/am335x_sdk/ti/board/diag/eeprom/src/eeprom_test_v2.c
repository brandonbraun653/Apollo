/******************************************************************************
 * Copyright (c) 2018-2019 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   eeprom_test_v2.c
 *
 *  \brief  eeprom application.
 *
 *  Targeted Functionality: Verifying board id contents.                          
 *
 *  Operation: This test display the board details by reading
 *			   Board id EEPROM
 *
 *  Supported SoCs: AM65XX, J721E.
 *
 *  Supported Platforms: am65xx_evm, am65xx_idk & j721e_evm.
 *
 */

#include "eeprom_test_v2.h"

#if defined(am65xx_evm) || defined(am65xx_idk)
boardProgInfo_t boardProgInfo[MAX_NUM_OF_BOARDS] = {
    {"CP Board\0",                  CP_EEPROM_SLAVE_ADDR,       true},
    {"Application Card\0",          APP_EEPROM_SLAVE_ADDR,      false},
    {"LCD Display Board\0",         LCD_EEPROM_SLAVE_ADDR,      false},
    {"SERDES Personality Card\0",   SERDES_EEPROM_SLAVE_ADDR,   false}
};
#else
boardProgInfo_t boardProgInfo[MAX_NUM_OF_BOARDS] = {
    {"SoM Board\0",                 SOM_EEPROM_SLAVE_ADDR,          true},
    {"CP Board\0",                  CP_EEPROM_SLAVE_ADDR,           true},
    {"GESI Board\0",                EXP_CONN_EEPROM_SLAVE_ADDR,     false},
    {"Infotainment board\0",        EXP_CONN_EEPROM_SLAVE_ADDR,     false},
    {"Fusion 2 Board\0",            CSI2_EXP_EEPROM_SLAVE_ADDR,     false},
    {"MV expansion\0",              CSI2_EXP_EEPROM_SLAVE_ADDR,     false},
    {"LI expansion\0",              CSI2_EXP_EEPROM_SLAVE_ADDR,     false},
    {"Quad ENET expansion\0",       ENET_EXP_EEPROM_SLAVE_ADDR,     false},
    {"Display adapter board\0",     DISPLAY_ADP_EEPROM_SLAVE_ADDR,  false}
};

Board_I2cInitCfg_t boardI2cInitCfg[MAX_NUM_OF_BOARDS] = {
    {0,     BOARD_SOC_DOMAIN_WKUP, false},
    {0,     BOARD_SOC_DOMAIN_WKUP, false},
    {0,     BOARD_SOC_DOMAIN_WKUP, false},
    {0,     BOARD_SOC_DOMAIN_WKUP, false},
    {6,     BOARD_SOC_DOMAIN_MAIN, false},
    {6,     BOARD_SOC_DOMAIN_MAIN, false},
    {6,     BOARD_SOC_DOMAIN_MAIN, false},
    {0,     BOARD_SOC_DOMAIN_WKUP, false},
    {0,     BOARD_SOC_DOMAIN_WKUP, false}
};
#endif

/**
 *  \brief    This function is used to read the contents of Board id EEPROM
 *            and display in uart console
 *
 *  \param    slaveAddress      [IN]    Slave Address of Board id EEPROM
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t eepromTest(uint8_t slaveAddress)
{
    Board_STATUS status;
    Board_IDInfo_v2 info = {0};
    uint8_t index = 0, count = 0, i;

    status = Board_getIDInfo_v2(&info, slaveAddress);
    if(status != BOARD_SOK)
    {
        return -1;
    }

    UART_printf("\nDisplaying Header Fields");
    UART_printf("\n========================\n");
    UART_printf("\tHeader ID: 0x%02x\n", info.headerInfo.magicNumber);

    UART_printf("\nDisplaying Board Info Fields");
    UART_printf("\n============================");
    UART_printf("\n\tBoard Name: ");
    UART_dataWrite((char *)&info.boardInfo.boardName, BOARD_BOARD_NAME_LEN);
    UART_printf("\n\tDesign Revision: ");
    UART_dataWrite((char *)&info.boardInfo.designRev, BOARD_DESIGN_REV_LEN);
    UART_printf("\n\tPROC Number: ");
    UART_dataWrite((char *)&info.boardInfo.procNum, BOARD_PROC_NUM_LEN);
    UART_printf("\n\tVariant: ");
    UART_dataWrite((char *)&info.boardInfo.variant, BOARD_VARIANT_LEN);
    UART_printf("\n\tPCB Revision: ");
    UART_dataWrite((char *)&info.boardInfo.pcbRev, BOARD_PCBREV_LEN);
#if defined(SOC_AM65XX)
    UART_printf("\n\tSchematic and BOM Revision: ");
    UART_dataWrite((char *)&info.boardInfo.schbomRev, BOARD_SCHMBOM_REV_LEN);
#else
    UART_printf("\n\tSchematic Revision: ");
    UART_dataWrite((char *)&info.boardInfo.pcbRev, BOARD_PCBREV_LEN);
    UART_dataWrite((char *)&info.boardInfo.schbomRev, BOARD_SCHMBOM_REV_LEN);
#endif
    UART_printf("\n\tSoftware Revision: ");
    UART_dataWrite((char *)&info.boardInfo.swRev, BOARD_SWREV_LEN);
    UART_printf("\n\tVendor ID: ");
    UART_dataWrite((char *)&info.boardInfo.vendorID, BOARD_VENDORID_LEN);
    UART_printf("\n\tBuild Week: ");
    UART_dataWrite((char *)&info.boardInfo.buildWeek, BOARD_BUILD_WEEK_LEN);
    UART_printf("\n\tBuild Year: ");
    UART_dataWrite((char *)&info.boardInfo.buildYear, BOARD_BUILD_YEAR_LEN);
    UART_printf("\n\tBoard ID: ");
    UART_dataWrite((char *)&info.boardInfo.boardID, BOARD_BOARDID_LEN);
    UART_printf("\n\tSerial Number: ");
    UART_dataWrite((char *)&info.boardInfo.serialNum, BOARD_SERIAL_NUM_LEN);

    /* Displaying DDR fields, if it is there */
    if(info.ddrInfo.ddrStructType == BOARD_DDR_FIELD_TYPE)
    {
        UART_printf("\nDisplaying DDR Fields");
        UART_printf("\n=====================");
        UART_printf("\n\tDDR Control Word: %02x\n", info.ddrInfo.ddrCtrl);
    }

    /* Displaying MAC id fields, if it is there */
    if(info.macInfo.macStructType == BOARD_MACINFO_FIELD_TYPE)
    {
        UART_printf("\nDisplaying MAC Info Fields");
        UART_printf("\n==========================\n");
        UART_printf("\tMAC Control Word: %02x", info.macInfo.macControl);

        do
        {
            UART_printf("\n\tMAC ADDR%d: %x", count, info.macInfo.macAddress[index]);
            index++;
            for(i = 1; i < 6; i++)
            {
                UART_printf("-%x", info.macInfo.macAddress[index]);
                index++;
            }
            count++;
        }while(info.macInfo.macAddress[index] != '\0');
    }

    return 0;
}

#if defined(am65xx_evm) || defined(am65xx_idk)
/**
 *  \brief   This function is used to enabling 
 *           I2C wakeup domain
 *
 */
static void enableWKUPI2C(void)
{
    I2C_HwAttrs i2cCfg;

    I2C_socGetInitCfg(I2C_INSTANCE, &i2cCfg);

    i2cCfg.baseAddr = CSL_WKUP_I2C0_CFG_BASE;
    i2cCfg.enableIntr = 0;

    I2C_socSetInitCfg(I2C_INSTANCE, &i2cCfg);
}
#endif

/**
 *  \brief   eeprom read test main function.
 *
 *  \return  int - Board ID Programming test status
 *             0     - in case of success
 *            -1     - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
#if defined(SOC_AM65XX)
    boardPresDetect_t isBoardDetect = APP_CARD_DETECT;
#else
    uint8_t isBoardDetect = 0U;
#endif
    uint8_t index;
    int8_t ret = 0;
    int8_t testSts = 0;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG;
#endif
    status = Board_init(boardCfg);
    if (status != BOARD_SOK)
    {
        return -1;
    }

    UART_printf("\n*********************************************\n"); 
	UART_printf  ("*              EEPROM Test                  *\n");
	UART_printf  ("*********************************************\n");

#if defined(am65xx_evm) || defined(am65xx_idk)
    /* Detecting Boards */
    enableWKUPI2C();
#endif
	for(index = STARTING_BOARD_NUM; index < MAX_NUM_OF_BOARDS; index++)
    {
        boardProgInfo[index].isBoardPresent = Board_detectBoard(isBoardDetect);
		isBoardDetect++;
    }

    for(index = 0; index < MAX_NUM_OF_BOARDS; index++)
    {
        if (boardProgInfo[index].isBoardPresent)
        {
#if !((defined(am65xx_evm) || defined(am65xx_idk)))
            Board_setI2cInitConfig(&boardI2cInitCfg[index]);
#endif
            UART_printf("\n%s:", boardProgInfo[index].boardName);
            ret = eepromTest(boardProgInfo[index].slaveAddr);
			if (ret != 0)
			{
                UART_printf("\nTest Failed");
				testSts = -1;
			}
        }
    }
    if (testSts != 0)
    {
        UART_printf("\nEEPROM Test Failed");
        return -1;
    }
    else
    {
        UART_printf("\nEEPROM Test Passed");
        return 0;
    }
}
