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

/**
 *  \file   lcd_touch_test.c
 *
 *  \brief  LCD touch detect test file
 *
 *  Targeted Functionality: Verifying the touch input by reading the
 *  touch co-ordinates.
 *
 *  Operation: This test is used to detect the touch taps and display the
 *  touch co-ordinates on to the serial console.
 *
 *  Supported SoCs: AM65x.
 *
 *  Supported Platforms: am65x_evm & am65x_idk.
 *
 */

#include "lcd_touch_test.h"

extern I2C_config_list I2C_config;

touch_init_t touch_init[NUM_OF_CONFIGS] = {
    {CMD_REG_ADDR, 0x0A},
    {X_OUTPUT_MAX_LOW_BYTE_REG_ADDR, 0x00},
    {X_OUTPUT_MAX_HIGH_BYTE_REG_ADDR, 0x05},
    {Y_OUTPUT_MAX_LOW_BYTE_REG_ADDR, 0x20},
    {Y_OUTPUT_MAX_HIGH_BYTE_REG_ADDR, 0x03},
    {TOUCH_NUMBER_REG_ADDR, 0x01},

    {MODULE_SWITCH1_REG_ADDR, 0x75},
    {MODULE_SWITCH2_REG_ADDR, 0x01},
    {SHAKE_COUNT_REG_ADDR,    0x01},
    {FILTER_REG_ADDR, 0x0f},
    {LARGE_TOCUH_REG_ADDR, 0x24},
    {NOISE_REDUCTION_REG_ADDR, 0x0f},
    {SCREEN_TOUCH_LEVEL_REG_ADDR, 0x64},
    {SCREEN_LEAVE_LEVEL_REG_ADDR, 0x3c},
    {LOW_POWER_CONTROL_REG_ADDR, 0x03},
    {REFRESH_RATE_REG_ADDR, 0x00},

    {BOARDER_SPACING1_REG_ADDR, 0x00},
    {BOARDER_SPACING2_REG_ADDR, 0x00},

    {STRETCH_RATE_REG_ADDR, 0x00},
    {STRETCH_R0_REG_ADDR, 0x16},
    {STRETCH_R1_REG_ADDR, 0x19},
    {STRETCH_R2_REG_ADDR, 0x1c},
    {STRETCH_RM_REG_ADDR, 0x14},

    {DRV_GROUPA_NUM_REG_ADDR, 0x8c},
    {DRV_GROUPB_NUM_REG_ADDR, 0x0e},
    {SENSOR_NUM_REG_ADDR, 0x0e},

    {FREQA_FACTOR_REG_ADDR, 0x24},
    {FREQB_FACTOR_REG_ADDR, 0x00},

    {PANEL_BITFREQL_REG_ADDR, 0x31},
    {PANEL_BITFREQH_REG_ADDR, 0xd0},

    {PANEL_SENSOR_TIMEL_REG_ADDR, 0X00},
    {PANEL_SENSOR_TIMEH_REG_ADDR, 0X00},

    {PANEL_TX_GAIN_REG_ADDR, 0x00},
    {PANEL_RX_GAIN_REG_ADDR, 0x83},
    {PANEL_DUMP_SHIFT_REG_ADDR, 0x33},
    {DRV_FRAME_CONTROL_REG_ADDR, 0x1D},

    {STYLUS_TX_GAIN_REG_ADDR, 0x00},
    {STYLUS_RX_GAIN_REG_ADDR, 0x3c},
    {STYLUS_DUMP_SHIFT_REG_ADDR, 0x0a},
    {STYLUS_DRIVER_TOUCH_LEVEL_REG_ADDR, 0x14},
    {STYLUS_SENSOR_TOUCH_LEVEL_REG_ADDR, 0x08},
    {STYLUS_STYLUS_CONTROL_REG_ADDR, 0x0a},
    {BASE_REDUCE_REG_ADDR, 0x00},

    {FREQ_HOPPING_START_REG_ADDR, 0x1c},
    {FREQ_HOPPING_END_REG_ADDR, 0x3c},
    {NOISE_DETECT_TIMES_REG_ADDR, 0x94},
    {HOPPING_FLAG_REG_ADDR, 0xd5},
    {HOPPING_THRESHOLD_REG_ADDR, 0x03},
    {NOISE_THRESHOLD_REG_ADDR, 0x08},

    {HOPPING_SEG1_BITFREQL_REG_ADDR, 0x04},
    {HOPPING_SEG1_BITFREQH_REG_ADDR, 0x93},
    {HOPPING_SEG1_FACTOR_REG_ADDR, 0x1e},

    {HOPPING_SEG2_BITFREQL_REG_ADDR, 0x00},
    {HOPPING_SEG2_BITFREQH_REG_ADDR, 0x82},
    {HOPPING_SEG2_FACTOR_REG_ADDR, 0x23},

    {HOPPING_SEG3_BITFREQL_REG_ADDR, 0x00},
    {HOPPING_SEG3_BITFREQH_REG_ADDR, 0x74},
    {HOPPING_SEG3_FACTOR_REG_ADDR, 0x29},

    {HOPPING_SEG4_BITFREQL_REG_ADDR, 0x00},
    {HOPPING_SEG4_BITFREQH_REG_ADDR, 0x69},
    {HOPPING_SEG4_FACTOR_REG_ADDR, 0x2f},

    {HOPPING_SEG5_BITFREQL_REG_ADDR, 0x00},
    {HOPPING_SEG5_BITFREQH_REG_ADDR, 0x5f},
    {HOPPING_SEG5_FACTOR_REG_ADDR, 0x37},

    {KEY1_REG_ADDR, 0x20},
    {KEY2_REG_ADDR, 0x40},
    {KEY3_REG_ADDR, 0x60},
    {KEY4_REG_ADDR, 0x00},
    {KEY_AREA_REG_ADDR, 0xf0},
    {KEY_TOUCH_LEVEL_REG_ADDR, 0x40},
    {KEY_LEAVE_LEVEL_REG_ADDR, 0x30},
    {KEY_SENS12_REG_ADDR, 0x55},
    {KEY_SENS34_REG_ADDR, 0x50},
    {KEY_RESTRAIN_REG_ADDR, 0x27},

    {SCAP_DIFF_UP_LEVEL_SENSE_REG_ADDR, 0x14},
    {SCAP_MERGE_TOUCH_LEVEL_SENSE_REG_ADDR, 0x19},

    {SENSOR_CH0_CNF_REG_ADDR, 0x01},
    {SENSOR_CH1_CNF_REG_ADDR, 0x02},
    {SENSOR_CH2_CNF_REG_ADDR, 0x03},
    {SENSOR_CH3_CNF_REG_ADDR, 0x04},
    {SENSOR_CH4_CNF_REG_ADDR, 0x05},
    {SENSOR_CH5_CNF_REG_ADDR, 0x06},
    {SENSOR_CH6_CNF_REG_ADDR, 0x07},
    {SENSOR_CH7_CNF_REG_ADDR, 0x08},
    {SENSOR_CH8_CNF_REG_ADDR, 0x09},
    {SENSOR_CH9_CNF_REG_ADDR, 0x0a},
    {SENSOR_CH10_CNF_REG_ADDR, 0x0b},
    {SENSOR_CH11_CNF_REG_ADDR, 0x0c},
    {SENSOR_CH12_CNF_REG_ADDR, 0x0d},
    {SENSOR_CH13_CNF_REG_ADDR, 0x0e},
    {SENSOR_CH14_CNF_REG_ADDR, 0x0f},
    {SENSOR_CH15_CNF_REG_ADDR, 0x10},
    {SENSOR_CH16_CNF_REG_ADDR, 0x11},
    {SENSOR_CH17_CNF_REG_ADDR, 0x12},
    {SENSOR_CH18_CNF_REG_ADDR, 0x13},
    {SENSOR_CH19_CNF_REG_ADDR, 0x14},
    {SENSOR_CH20_CNF_REG_ADDR, 0x15},
    {SENSOR_CH21_CNF_REG_ADDR, 0x16},
    {SENSOR_CH22_CNF_REG_ADDR, 0x17},
    {SENSOR_CH23_CNF_REG_ADDR, 0x18},

    {DRIVER_CH0_CNF_REG_ADDR, 0x1d},
    {DRIVER_CH1_CNF_REG_ADDR, 0x1e},
    {DRIVER_CH2_CNF_REG_ADDR, 0x1f},
    {DRIVER_CH3_CNF_REG_ADDR, 0x20},
    {DRIVER_CH4_CNF_REG_ADDR, 0x21},
    {DRIVER_CH5_CNF_REG_ADDR, 0x22},
    {DRIVER_CH6_CNF_REG_ADDR, 0x24},
    {DRIVER_CH7_CNF_REG_ADDR, 0x26},
    {DRIVER_CH8_CNF_REG_ADDR, 0x28},
    {DRIVER_CH9_CNF_REG_ADDR, 0x29},
    {DRIVER_CH10_CNF_REG_ADDR, 0x2a},
    {DRIVER_CH11_CNF_REG_ADDR, 0x1c},
    {DRIVER_CH12_CNF_REG_ADDR, 0x18},
    {DRIVER_CH13_CNF_REG_ADDR, 0x16},
    {DRIVER_CH14_CNF_REG_ADDR, 0x14},
    {DRIVER_CH15_CNF_REG_ADDR, 0x13},
    {DRIVER_CH16_CNF_REG_ADDR, 0x12},
    {DRIVER_CH17_CNF_REG_ADDR, 0x10},
    {DRIVER_CH18_CNF_REG_ADDR, 0x0f},
    {DRIVER_CH19_CNF_REG_ADDR, 0x0c},
    {DRIVER_CH20_CNF_REG_ADDR, 0x0a},
    {DRIVER_CH21_CNF_REG_ADDR, 0x08},
    {DRIVER_CH22_CNF_REG_ADDR, 0x06},
    {DRIVER_CH23_CNF_REG_ADDR, 0x04},
    {DRIVER_CH24_CNF_REG_ADDR, 0x02},
    {DRIVER_CH25_CNF_REG_ADDR, 0x00},
    {DRIVER_CH26_CNF_REG_ADDR, 0x00},
    {DRIVER_CH27_CNF_REG_ADDR, 0x00},
    {DRIVER_CH28_CNF_REG_ADDR, 0x00},
    {DRIVER_CH29_CNF_REG_ADDR, 0x00},
    {DRIVER_CH30_CNF_REG_ADDR, 0x00},
    {DRIVER_CH31_CNF_REG_ADDR, 0x00},

    {CONFIG_CHKSUM_REG_ADDR, 0x9c},
    {CONFIG_FRESH_REG_ADDR, 0x01}
};

uint16_t pointTouchRegAddr[NUM_OF_POINT_DATA_SETS][NUM_OF_REGS_IN_EACH_SET] = {
    {POINT1_X_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT1_X_COORDINATE_HIGH_BYTE_REG_ADDR,
     POINT1_Y_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT1_Y_COORDINATE_HIGH_BYTE_REG_ADDR},

    {POINT2_X_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT2_X_COORDINATE_HIGH_BYTE_REG_ADDR,
     POINT2_Y_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT2_Y_COORDINATE_HIGH_BYTE_REG_ADDR},

    {POINT3_X_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT3_X_COORDINATE_HIGH_BYTE_REG_ADDR,
     POINT3_Y_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT3_Y_COORDINATE_HIGH_BYTE_REG_ADDR},

    {POINT4_X_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT4_X_COORDINATE_HIGH_BYTE_REG_ADDR,
     POINT4_Y_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT4_Y_COORDINATE_HIGH_BYTE_REG_ADDR},

    {POINT5_X_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT5_X_COORDINATE_HIGH_BYTE_REG_ADDR,
     POINT5_Y_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT5_Y_COORDINATE_HIGH_BYTE_REG_ADDR},

    {POINT6_X_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT6_X_COORDINATE_HIGH_BYTE_REG_ADDR,
     POINT6_Y_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT6_Y_COORDINATE_HIGH_BYTE_REG_ADDR},

    {POINT7_X_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT7_X_COORDINATE_HIGH_BYTE_REG_ADDR,
     POINT7_Y_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT7_Y_COORDINATE_HIGH_BYTE_REG_ADDR},

    {POINT8_X_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT8_X_COORDINATE_HIGH_BYTE_REG_ADDR,
     POINT8_Y_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT8_Y_COORDINATE_HIGH_BYTE_REG_ADDR},

    {POINT9_X_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT9_X_COORDINATE_HIGH_BYTE_REG_ADDR,
     POINT9_Y_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT9_Y_COORDINATE_HIGH_BYTE_REG_ADDR},

    {POINT10_X_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT10_X_COORDINATE_HIGH_BYTE_REG_ADDR,
     POINT10_Y_COORDINATE_LOW_BYTE_REG_ADDR,
     POINT10_Y_COORDINATE_HIGH_BYTE_REG_ADDR}
};

/**
 *  \brief    Reads the specified touch register of a capacitive
 *            touch controller.
 *
 *  \param    handle              [IN]       I2C Handler
 *            slaveAddress        [IN]       Touch device slave Address
 *            regAddr             [IN]       Register address of a touch slave
 *                                           device
 *            *rdRegval           [OUT]      Pointer to store the read register
 *                                           value.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_read_register(I2C_Handle handle,
                                      uint8_t slaveAddress,
                                      uint16_t regAddr,
                                      uint8_t *rdRegval)
{
    int8_t  ret = 0;
    uint8_t tx[2];
    I2C_Transaction transaction;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddress;
    transaction.writeBuf     = &tx[0];
    transaction.writeCount   = 2;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;

    /* Sending High byte of the register address first followed by Low
       byte of register address */
    tx[0] = (uint8_t)((regAddr & 0xFF00) >> 8);
    tx[1] = (uint8_t)(regAddr & 0x00FF);

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = -1;
        return ret;
    }

    /* One milli sec delay */
    BOARD_delay(1000);

    transaction.writeBuf     = NULL;
    transaction.writeCount   = 0;
    transaction.readBuf      = rdRegval;
    transaction.readCount    = 1;

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }

    return ret;
}

/**
 *  \brief    Writes the specified touch register of a capacitive
 *            touch controller.
 *
 *  \param    handle              [IN]   I2C Handler
 *            slaveAddress        [IN]   Touch Slave Address
 *            regAddr             [IN]   Register address of a touch slave device
 *            regData             [IN]   Data to be configured into the
 *                                       register.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_write_register(I2C_Handle handle,
                                       uint8_t slaveAddress,
                                       uint16_t regAddr,
                                       uint8_t regData)
{
    int8_t ret = 0;
    uint8_t tx[3];
    I2C_Transaction transaction;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddress;
    transaction.writeBuf     = &tx[0];
    transaction.writeCount   = 3;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;

    /* Sending High byte of the register address first followed by Low
       byte of register address */
    tx[0] = (uint8_t)((regAddr & 0xFF00) >> 8);
    tx[1] = (uint8_t)(regAddr & 0x00FF);
    tx[2] = regData;

    /* One milli sec delay */
    BOARD_delay(1000);

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }

    return ret;
}

/**
 *  \brief    This function is used is to initialize the touch interface.
 *
 *  \param    handle              [IN]       I2C Handler
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_lcd_touch_init(I2C_Handle handle)
{
    int8_t ret = 0;
    uint8_t index;

    for(index = 0; index < NUM_OF_CONFIGS; index++)
    {
        ret = BoardDiag_write_register(handle,
                                       BOARD_I2C_TOUCH_SLAVE_ADDR,
                                       touch_init[index].regAddr,
                                       touch_init[index].regData);
        if(ret != 0)
        {
            break;
        }
    }

    return ret;
}

/**
 *  \brief    This function is used to read the firmware version.
 *
 *  \param    handle              [IN]       I2C Handler
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_read_fw_version(I2C_Handle handle)
{
    int8_t ret = 0;
    uint8_t rdByteCount = 0;
    uint8_t firmwareVer[VERSION_SIZE] = {'\0'};
    uint16_t firmwareVerAddr[VERSION_SIZE] = {FIRMWARE_VERSION_LOW_BYTE_ADDR,
                                              FIRMWARE_VERSION_HIGH_BYTE_ADDR};

    UART_printf("Reading the firmware version...\n\r");

    while(rdByteCount < VERSION_SIZE)
    {
        ret = BoardDiag_read_register(handle,
                                      BOARD_I2C_TOUCH_SLAVE_ADDR,
                                      firmwareVerAddr[rdByteCount],
                                      &firmwareVer[rdByteCount]);
        if(ret != 0)
        {
            UART_printf("Reading the firmware version failed\n");
            ret = -1;
            break;
        }

        rdByteCount++;
    }

    if(rdByteCount == VERSION_SIZE)
    {
        UART_printf("The firmware version read is - %s\n\r", (char *)firmwareVer);
    }

    return ret;
}

/**
 *  \brief    This function is used to read the product Id.
 *
 *  \param    handle              [IN]       I2C Handler
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_read_productId(I2C_Handle handle)
{
    int8_t ret = 0;
    uint8_t rdByteCount = 0;
    uint8_t productId[PROD_ID_SIZE] = {'\0'};
    uint16_t productIdAddr[PROD_ID_SIZE] = {PRODUCT_ID_FIRST_BYTE_REG_ADDR,
                                           PRODUCT_ID_SECOND_BYTE_REG_ADDR,
                                           PRODUCT_ID_THIRD_BYTE_REG_ADDR,
                                           PRODUCT_ID_FOURTH_BYTE_REG_ADDR};

    UART_printf("Reading the product ID...\n\r");

    while(rdByteCount < PROD_ID_SIZE)
    {
        ret = BoardDiag_read_register(handle,
                                      BOARD_I2C_TOUCH_SLAVE_ADDR,
                                      productIdAddr[rdByteCount],
                                      &productId[rdByteCount]);
        if(ret != 0)
        {
            UART_printf("Reading the product Id failed\n");
            ret = -1;
            break;
        }

        rdByteCount++;
    }

    if(rdByteCount == PROD_ID_SIZE)
    {
        UART_printf("The prod Id read is - %s\n\r", (char *)productId);
    }

    return ret;
}

/**
 *  \brief    This function is used to read the touch device details.
 *
 *  \param    handle              [IN]       I2C Handler
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_read_device_deatils(I2C_Handle handle)
{
    int8_t ret = 0;

    ret = BoardDiag_read_productId(handle);
    if(ret != 0)
    {
        return ret;
    }

    ret = BoardDiag_read_fw_version(handle);

    return ret;

}

/**
 *  \brief    The function clear the buffer status register.
 */
void bufferclear(I2C_Handle handle)
{
    uint16_t index;

    BOARD_delay(100000);

    for(index = 0; index < 50; index++)
    {
        BoardDiag_write_register(  handle,
								   BOARD_I2C_TOUCH_SLAVE_ADDR,
								   BUFFER_STATUS_REG_ADDR,
								   0U);
    }
}

/**
 *  \brief    The function performs the LCD touch test by reading
 *            the touch taps and displaying the position of touch
 *              co-ordinates on to the serial console.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_lcd_touch_detect_test(void)
{
    int8_t ret = 0;
    uint16_t index;
    uint8_t rdRegData;
    uint8_t touchCount = 0;
    uint16_t xCoordinateData;
    uint16_t yCoordinateData;
    uint8_t numOfTouchPoints;
    uint8_t touchLimitCnt = 0;
    bool touchExitStatusFlag = false;
    uint8_t cfgRegCount = 0;
    uint8_t pointData[4] = {'\0'};

    I2C_Params i2cParams;
    I2C_HwAttrs i2cConfig;
    I2C_Handle handle = NULL;

#if defined(SOC_AM65XX) && !defined (__aarch64__)
    /* MCU I2C instance will be active by default for R5 core.
     * Need update HW attrs to enable MAIN I2C instance.
     */
    enableMAINI2C(1, CSL_I2C1_CFG_BASE);
#endif

    for(index = 0; index < I2C_HWIP_MAX_CNT; index++)
    {
        I2C_socGetInitCfg(index, &i2cConfig);
        i2cConfig.enableIntr = false;
        I2C_socSetInitCfg(index, &i2cConfig);
    }

    /* Initializes the I2C */
    I2C_init();

    /* Initializes the I2C Parameters */
    I2C_Params_init(&i2cParams);
    i2cParams.bitRate = I2C_400kHz;

    /* Configures the I2C instance with the passed parameters*/
    handle = I2C_open(BOARD_I2C_TOUCH_INSTANCE, &i2cParams);
    if(handle == NULL)
    {
        UART_printf("\nI2C Open failed!\n");
        ret = -1;
        return ret;
    }

    UART_printf("\n\n\rRunning the LCD touch detect test...\n\r");

    UART_printf("\n\rReading the touch device details\n\r");

    ret = BoardDiag_read_device_deatils(handle);
    if(ret != 0)
    {
        return ret;
    }

    ret = BoardDiag_lcd_touch_init(handle);
    if(ret != 0)
    {
        UART_printf("Touch initialization failed\n\r");
        return ret;
    }
	UART_printf("Clearing the buffer status register...\n\r");
	bufferclear(handle);
    /* Continuously wait for a touch to be detected or test to be timed-out */
    //while((!touchExitStatusFlag) && (delayCycleCount != DELAY_CYCLES))
    UART_printf("\n\n\rWaiting for user to provide 20 single point touches...\n\r");
    while(touchExitStatusFlag != true)
    {
        ret = BoardDiag_read_register(handle,
                                      BOARD_I2C_TOUCH_SLAVE_ADDR,
                                      BUFFER_STATUS_REG_ADDR,
                                      &rdRegData);
        if(ret != 0)
        {
            UART_printf("Reading the touch data failed\n\r");
            return ret;
        }

        /* Check if the buffer status is set */
        if(rdRegData & BUFFER_STATUS_MASK)
        {
            numOfTouchPoints = (rdRegData & NUM_OF_TOUCH_POINTS_MASK);
            touchLimitCnt = touchLimitCnt + numOfTouchPoints;
            for(touchCount = 0; touchCount < numOfTouchPoints; touchCount++)
            {
                for(cfgRegCount = 0; cfgRegCount < NUM_OF_REGS_IN_EACH_SET; cfgRegCount++)
                {
                    ret = BoardDiag_read_register(handle,
                                                  BOARD_I2C_TOUCH_SLAVE_ADDR,
                                                  pointTouchRegAddr[touchCount][cfgRegCount],
                                                  &pointData[cfgRegCount]);
                    if(ret != 0)
                    {
                        UART_printf("Reading the touch data failed\n\r");
                        return ret;
                    }
                }

                /* The High Byte is left shifted by '8' and add to the Low Byte */
                xCoordinateData = ((uint16_t)pointData[0] | \
                                  (((uint16_t)pointData[1]) << 8));

                /* The High Byte is left shifted by '8' and add to the Low Byte */
                yCoordinateData = ((uint16_t)pointData[2] | \
                                  (((uint16_t)pointData[3]) << 8));

                UART_printf("(x - %d, y - %d)\n\r",
                             xCoordinateData, yCoordinateData);
            }

            if(touchLimitCnt >= TOUCH_LIMIT_CNT)
            {
                touchExitStatusFlag = true;
            }

             bufferclear(handle);
        }

        //delayCycleCount++;
    }
    /* Closing the Board presence detect i2c instance */
    I2C_close(handle);

    return ret;
}
