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
 * \file   leo_pmic_lib_test.c
 *
 * \brief  This file contains API's used for testing the Leo PMIC using the 
 *         Leo PMIC board library.
 *
 * Supported SoCs: J721E
 *
 * Supported Platforms: j721e_evm
 */

#include "leo_pmic_lib_test.h"

Board_Tps65941RtcDate dateCfg = 
{
    31,
    12,
    18,
    BOARD_TPS65941_SUNDAY
};

Board_Tps65941RtcTime timeCfg =
{
    59,
    59,
    11,
    BOARD_TPS65941_12_HOUR_MODE,
    BOARD_TPS65941_PM_MODE
};

static char *gdayOfWeek[] = 
{"Sunday",
 "Monday",
 "Tuesday",
 "Wednesday",
 "Thursday",
 "Friday",
 "Saturday"
};

leoPmicVoltCfg gpmicaVoltSetCfg[] =
{
    {BOARD_TPS65941_BUCK1_RESOURCE, 770},
    {BOARD_TPS65941_LDO1_RESOURCE , 1750},
    {0xFF, 0}
};

leoPmicVoltCfg gpmicbVoltSetCfg[] =
{
    {BOARD_TPS65941_BUCK1_RESOURCE, 770},
    {BOARD_TPS65941_LDO1_RESOURCE , 3150},
    {0xFF, 0}
};

leoPmicVoltCfg gpmicaVoltGetCfg[] =
{
    {BOARD_TPS65941_BUCK1_RESOURCE, 0},
    {BOARD_TPS65941_LDO1_RESOURCE , 0},
    {0xFF, 0}
};

leoPmicVoltCfg gpmicbVoltGetCfg[] =
{
    {BOARD_TPS65941_BUCK1_RESOURCE, 0},
    {BOARD_TPS65941_LDO1_RESOURCE , 0},
    {0xFF, 0}
};

/**
 * \brief   TPS65941 PMIC RTC test function.
 *
 * This function is used to test the RTC functionality present in the TPS65941
 * PMIC.
 *
 * \param   handle      [IN]    Low level I2C driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
static int32_t BoardDiag_leoPmicRtcTest(I2C_Handle handle, uint8_t slaveAddr)
{
    int32_t retStatus;
    int32_t count = 5;

    UART_printf("Testing the Leo PMIC RTC functionality\n");
    UART_printf("Setting the date and time to the RTC\n");
    UART_printf("Displaying RTC time: %02dH:%02dM:%02dS", timeCfg.hour, timeCfg.minutes, timeCfg.seconds);
    if(timeCfg.timeMode == BOARD_TPS65941_12_HOUR_MODE)
    {
        if(timeCfg.meridienMode)
        {
            UART_printf(" PM\n");
        }
        else
        {
            UART_printf(" AM\n");
        }
    }
    else
    {
        UART_printf("\n");
    }

    UART_printf("Displaying RTC day: %s\n", gdayOfWeek[dateCfg.week]);
    UART_printf("Displaying RTC date: %02d-%02d-20%02d\n", dateCfg.date, dateCfg.month, dateCfg.year);
    retStatus = Board_tps65941SetRtc(handle, slaveAddr,
                                     &timeCfg, &dateCfg);
    if(retStatus != BOARD_SOK)
    {
        UART_printf("Setting the date and time to RTC failed");
        retStatus = -1;
        return retStatus;
    }

    UART_printf("\nGetting the date and time from the RTC\n");
    while(count > 0)
    {
        BOARD_delay(5000000);   /* waiting for 5 sec */

        retStatus = Board_tps65941GetRtc(handle, slaveAddr,
                                        &timeCfg, &dateCfg);
        if(retStatus != BOARD_SOK)
        {
            UART_printf("Getting the date and time to RTC failed");
            retStatus = -1;
            return retStatus;
        }

        UART_printf("Displaying RTC time: %02dH:%02dM:%02dS", timeCfg.hour, timeCfg.minutes, timeCfg.seconds);
        if(timeCfg.timeMode == BOARD_TPS65941_12_HOUR_MODE)
        {
            if(timeCfg.meridienMode)
            {
                UART_printf(" PM\n");
            }
            else
            {
                UART_printf(" AM\n");
            }
        }
        else
        {
            UART_printf("\n");
        }

        UART_printf("Displaying RTC day: %s\n", gdayOfWeek[dateCfg.week]);
        UART_printf("Displaying RTC date: %02d-%02d-20%02d\n", dateCfg.date, dateCfg.month, dateCfg.year);
        count--;
    }

    return retStatus;
}

/**
 * \brief   TPS65941 PMIC RTC Interrupt test function.
 *
 * This function is used to test the RTC Interrupt functionality present in the
 * TPS65941 PMIC.
 *
 * \param   handle      [IN]    Low level I2C driver handle
 * \param   slaveAddr   [IN]    TPS65941 slave address
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
static int32_t BoardDiag_leoPmicRtcIntrTest(I2C_Handle handle, uint8_t slaveAddr)
{
    int32_t retStatus;
    uint8_t intrStatus;
    uint8_t regData = 0x00;
    Board_Tps65941RtcDate alarmDate = {
        01,
        01,
        19,
        BOARD_TPS65941_MONDAY
    };
    Board_Tps65941RtcTime alarmTime = {
        22,
        00,
        12,
        BOARD_TPS65941_12_HOUR_MODE,
        BOARD_TPS65941_AM_MODE
    };

    UART_printf("\nTesting Leo PMIC RTC Interrupt functionality\n");

    /* Clearing RTC Alarm Interrupt */
    retStatus = Board_i2c8BitRegRd(handle,
                                   slaveAddr,
                                   BOARD_TPS65941_RTC_STATUS,
                                   &regData,
                                   BOARD_I2C_NUM_OF_BYTES_01,
                                   BOARD_I2C_TRANSACTION_TIMEOUT);
    if(retStatus != BOARD_SOK)
    {
        return BOARD_I2C_TRANSFER_FAIL;
    }
    if((regData & BOARD_TPS65941_ALRM_STAT_BIT_MASK) >> BOARD_TPS65941_ALRM_STAT_SHIFT)
    {
        regData &= ~(BOARD_TPS65941_ALRM_STAT_BIT_MASK);
        regData |= (1 << BOARD_TPS65941_ALRM_STAT_SHIFT);
        retStatus = Board_i2c8BitRegWr(handle,
                                       slaveAddr,
                                       BOARD_TPS65941_RTC_STATUS,
                                       &regData,
                                       BOARD_I2C_NUM_OF_BYTES_01,
                                       BOARD_I2C_TRANSACTION_TIMEOUT);
        if(retStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }
    }

    retStatus = Board_tps65941SetAlarmIntr(handle, slaveAddr, 
                                           &alarmTime, &alarmDate);
    if(retStatus != BOARD_SOK)
    {
        UART_printf("Setting alarm Interrupt failed\n");
        retStatus = -1;
        return retStatus;
    }

    BOARD_delay(35000000);   /* waiting for 35 sec */

    retStatus = Board_tps65941GetIntrStatus(handle, slaveAddr,
                                            BOARD_TPS65941_INTR_ID_RTC, &intrStatus);
    if(retStatus != BOARD_SOK)
    {
        UART_printf("Getting the interrupt status failed\n");
        retStatus = -1;
        return retStatus;
    }

    if(intrStatus == BOARD_TPS65941_INTR_SET)
    {
        retStatus = Board_i2c8BitRegRd(handle,
                                         slaveAddr,
                                         BOARD_TPS65941_RTC_STATUS,
                                         &regData,
                                         BOARD_I2C_NUM_OF_BYTES_01,
                                         BOARD_I2C_TRANSACTION_TIMEOUT);
        if(retStatus != BOARD_SOK)
        {
            return BOARD_I2C_TRANSFER_FAIL;
        }

        if((regData & BOARD_TPS65941_ALRM_STAT_BIT_MASK) >> BOARD_TPS65941_ALRM_STAT_SHIFT)
        {
            UART_printf("Alarm Interrupt has been set\n");
        }
        else
        {
            UART_printf("Alarm Interrupt has not been set\n");
        }
    }
    else
    {
        UART_printf("Alarm Interrupt has not been set\n");
    }
    return retStatus;
}

/**
 * \brief   TPS65941 PMIC set voltage test function.
 *
 * This function is used to test dynamic voltage setting functionality to the
 * TPS65941 PMIC.
 *
 * \param   handle          [IN]    Low level I2C driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   voltageSetCfg   [IN]    TPS65941 power resource voltage details
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
static int32_t BoardDiag_leoPmicSetVoltage(I2C_Handle handle, uint8_t slaveAddr,
                                           leoPmicVoltCfg voltageSetCfg[])
{
    int32_t retStatus = 0;
    int32_t index = 0;

    while(voltageSetCfg[index].powerResource != 0xFF)
    {
        UART_printf("Setting Power Resource %d Millivolts %d\n", voltageSetCfg[index].powerResource,
                                                                 voltageSetCfg[index].millivolts);
        retStatus = Board_tps65941SetVoltage(handle,
                                             slaveAddr,
                                             voltageSetCfg[index].powerResource,
                                             voltageSetCfg[index].millivolts);
        if(retStatus != BOARD_SOK)
        {
            UART_printf("Failed to set the voltage for Power resource %d\n", voltageSetCfg[index].powerResource);
            retStatus = -1;
            return retStatus;
        }
        index++;
    }

    return retStatus;
}

/**
 * \brief   TPS65941 PMIC get voltage test function.
 *
 * This function is used to dynamically get the voltage of the each power
 * resource in TPS65941 PMIC.
 *
 * \param   handle          [IN]    Low level I2C driver handle
 * \param   slaveAddr       [IN]    TPS65941 slave address
 * \param   voltageSetCfg   [IN]    TPS65941 power resource voltage details
 *
 * \return  BOARD_SOK in case of success or appropriate error code.
 */
static int32_t BoardDiag_leoPmicGetVoltage(I2C_Handle handle, uint8_t slaveAddr,
                                           leoPmicVoltCfg voltageSetCfg[])
{
    int32_t retStatus = 0;
    int32_t index = 0;

    if(slaveAddr == BOARD_I2C_LEO_PMIC_A_ADDR)
    {
        UART_printf("\nReading Power Resource voltage from the Leo PMIC A\n");
    }
    else
    {
        UART_printf("\nReading Power Resource voltage from the Leo PMIC B\n");
    }

    while(voltageSetCfg[index].powerResource != 0xFF)
    {
        retStatus = Board_tps65941GetVoltage(handle,
                                             slaveAddr,
                                             voltageSetCfg[index].powerResource,
                                             &voltageSetCfg[index].millivolts);
        if(retStatus != BOARD_SOK)
        {
            UART_printf("Failed to set the voltage for Power resource %d\n", voltageSetCfg[index].powerResource);
            retStatus = -1;
            return retStatus;
        }
        else
        {
            UART_printf("Power Resource %d Millivolts %d\n", voltageSetCfg[index].powerResource,
                                                             voltageSetCfg[index].millivolts);
        }
        index++;
    }
    return retStatus;
}

/**
 * \brief   This function is runs the RTC, RTC Interrupt and voltage
 *          switching functionality tests in TPS65941 PMIC.
 *
 * \return  int8_t
 *              0  - in case of success
 *              -1 - in case of failure.
 */
static int32_t BoardDiag_leoPmicTest()
{
    int32_t status;
    uint8_t input;
    I2C_Handle handle = NULL;

    handle = Board_getI2CHandle(BOARD_SOC_DOMAIN_WKUP,
                                BOARD_I2C_PMIC_INSTANCE);

    if(handle == NULL)
    {
        UART_printf("I2C Open failed!\n");
        status = -1;
        return status;
    }

    status = BoardDiag_leoPmicRtcTest(handle, BOARD_I2C_LEO_PMIC_A_ADDR);

    status = BoardDiag_leoPmicRtcIntrTest(handle, BOARD_I2C_LEO_PMIC_A_ADDR);

    status = BoardDiag_leoPmicGetVoltage(handle, BOARD_I2C_LEO_PMIC_A_ADDR, gpmicaVoltGetCfg);
    if(status != 0)
    {
        UART_printf("Failed the read voltage from Leo PMIC A\n");
        status = -1;
        return status;
    }
    status = BoardDiag_leoPmicGetVoltage(handle, BOARD_I2C_LEO_PMIC_B_ADDR, gpmicbVoltGetCfg);
    if(status != 0)
    {
        UART_printf("Failed the read voltage from Leo PMIC B\n");
        status = -1;
        return status;
    }

    UART_printf("\nSetting Leo PMIC A VDD_CPU_AVS to 0.77 V\n");
    UART_printf("Setting Leo PMIC A VDD1_LPDDR4_1V8 to 1.725 V\n");
    status = BoardDiag_leoPmicSetVoltage(handle, BOARD_I2C_LEO_PMIC_A_ADDR, gpmicaVoltSetCfg);
    if(status != 0)
    {
        UART_printf("Failed the set voltage to Leo PMIC A\n");
        status = -1;
        return status;
    }
    UART_printf("\nSetting Leo PMIC B VDD_CPU to 0.77 V\n");
    UART_printf("Setting Leo PMIC B VDD_SD_DV to 3.150 V\n");
    status = BoardDiag_leoPmicSetVoltage(handle, BOARD_I2C_LEO_PMIC_B_ADDR, gpmicbVoltSetCfg);
    if(status != 0)
    {
        UART_printf("Failed the set voltage to Leo PMIC B\n");
        status = -1;
        return status;
    }
    Board_delay(1000);

    UART_printf("Press Enter after probing the voltage\n");
	UART_scanFmt("%d", &input);
    UART_printf("Reverting back to previous voltage\n");
    status = BoardDiag_leoPmicSetVoltage(handle, BOARD_I2C_LEO_PMIC_A_ADDR, gpmicaVoltGetCfg);
    if(status != 0)
    {
        UART_printf("Failed the read voltage from Leo PMIC A\n");
        status = -1;
        return status;
    }
    status = BoardDiag_leoPmicSetVoltage(handle, BOARD_I2C_LEO_PMIC_B_ADDR, gpmicbVoltGetCfg);
    if(status != 0)
    {
        UART_printf("Failed the read voltage from Leo PMIC B\n");
        status = -1;
        return status;
    }

    return status;
}

/**
 *  \brief   Leo PMIC test main function
 *
 *  \return  int - Leo PMIC test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    int32_t status;
    Board_initCfg boardCfg;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        status = -1;
        return status;
    }

    UART_printf("\n*********************************************\n");
    UART_printf  ("*               Leo PMIC Test               *\n");
    UART_printf  ("*********************************************\n");

    status = BoardDiag_leoPmicTest();
    if(status == 0)
    {
        UART_printf("Leo PMIC test completed successfully\n");
        status = -1;
    }

    return 0;

}
