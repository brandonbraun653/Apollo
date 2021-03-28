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
 *  \file   automation_header_test.c
 *
 *  \brief  automation header test file
 *
 *  Targeted Functionality: Verifying the access of I2C boot mode
 *                          buffer register.
 *
 *  Operation: This test is used to read the switch positions of available
 *             boot mode switches and display it on the serial console.
 *
 *  Supported SoCs: AM65xx & J721E.
 *
 *  Supported Platforms: am65xx_evm, am65xx_idk & j721e_evm.
 *
 */

#include "automation_header_test.h"

extern I2C_config_list I2C_config;

/**
 *  \brief    Used to read the input port registers of Boot mode
 *            switch i2c slave device.
 *
 *  \param    handle              [IN]       I2C Handler
 *            slaveAddress        [IN]       Slave address
 *            regAddr             [IN]       Register address
 *            *rdRegval           [OUT]      Pointer to store the
 *                                           read register value.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_read_register(I2C_Handle handle,
                                      uint8_t slaveAddr,
                                      uint8_t regAddr,
                                      uint8_t *rdRegval)
{
    int8_t  ret = 0;
    I2C_Transaction transaction;

    /* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = &regAddr;
    transaction.writeCount   = 1;
    transaction.readBuf      = NULL;
    transaction.readCount    = 0;

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        ret = -1;
        return ret;
    }

    BOARD_delay(500);

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
 *  \brief    Used to write the output port registers of Boot mode
 *            switch i2c slave device.
 *
 *  \param    handle              [IN]       I2C Handler
 *            slaveAddress        [IN]       Slave address
 *            regAddr             [IN]       Register address
 *            value               [IN]       Value to write
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_write_register(I2C_Handle handle,
                                       uint8_t slaveAddr,
                                       uint8_t regAddr,
                                       uint8_t value)
{
    int8_t  ret = 0;
    I2C_Transaction transaction;
    uint8_t dataBuff[2] = {0};

	/* Initializes the I2C transaction structure with default values */
    I2C_transactionInit(&transaction);

    dataBuff[0] = regAddr;
    dataBuff[1] = value;

    /* Control Byte followed by write bit */
    transaction.slaveAddress = slaveAddr;
    transaction.writeBuf     = dataBuff;
    transaction.writeCount   = 2; /* writes data size of 2 bytes */
    transaction.readCount    = 0;

    BOARD_delay(200);

    ret = I2C_transfer(handle, &transaction);
    if(ret != I2C_STS_SUCCESS)
    {
        return -1;
    }

    return 0;
}

/**
 *  \brief    The function performs the automation header verification test
 *            by reading the boot mode switch's input port registers and display
 *            the ON-OFF state of switch on to the serial console.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_run_automation_header_test(void)
{
    int8_t   ret = 0;
    uint8_t  index;
    uint8_t  port0RegData;
    uint8_t  port1RegData;

    I2C_Params i2cParams;
    I2C_HwAttrs i2cConfig;
    I2C_Handle handle = NULL;

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
    handle = I2C_open(BOARD_TEST_HEADER_I2C_INSTANCE, &i2cParams);
    if(handle == NULL)
    {
        UART_printf("\nI2C Open failed!\n");
        ret = -1;
        return ret;
    }

    UART_printf("\n\n\rRunning the Automation Header test...\n\r");

    UART_printf("\n\rReading the input PORT0 register value "
                "of I2C Boot mode buffer...\n\r");
    ret = BoardDiag_read_register(handle,
                                  BOARD_I2C_BOOT_MODE_SW_ADDR,
                                  CMD_INPUT_PORT0_REG_ACCESS,
                                  &port0RegData);
    if(ret != 0)
    {
        UART_printf("Reading the input PORT0 register of "
                    "I2C Boot mode buffer failed\n\r");
        /* Closing the boot mode buffer i2c instance */
        I2C_close(handle);
        return -1;
    }

    UART_printf("\n\rReading the input PORT1 register value "
                "of I2C Boot mode buffer...\n\r");
    ret = BoardDiag_read_register(handle,
                                  BOARD_I2C_BOOT_MODE_SW_ADDR,
                                  CMD_INPUT_PORT1_REG_ACCESS,
                                  &port1RegData);
    if(ret != 0)
    {
        UART_printf("Reading the input PORT1 register of "
                    "I2C Boot mode buffer failed\n\r");
        /* Closing the boot mode buffer i2c instance */
        I2C_close(handle);
        return -1;
    }

    UART_printf("\n\rWriting the output PORT0 register value "
                "of I2C Boot mode buffer...\n\r");
    ret = BoardDiag_write_register(handle,
                                   BOARD_I2C_BOOT_MODE_SW_ADDR,
                                   CMD_CFG_PORT0_REG_ACCESS,
                                   0x0);
    if(ret != 0)
    {
        UART_printf("Reading the input PORT0 register of "
                    "I2C Boot mode buffer failed\n\r");
        /* Closing the boot mode buffer i2c instance */
        I2C_close(handle);
        return -1;
    }

    UART_printf("\n\rWriting the output PORT1 register value "
                "of I2C Boot mode buffer...\n\r");
    ret = BoardDiag_write_register(handle,
                                   BOARD_I2C_BOOT_MODE_SW_ADDR,
                                   CMD_CFG_PORT1_REG_ACCESS,
                                   0x0);
    if(ret != 0)
    {
        UART_printf("Reading the input PORT1 register of "
                    "I2C Boot mode buffer failed\n\r");
        /* Closing the boot mode buffer i2c instance */
        I2C_close(handle);
        return -1;
    }

#if (!(defined(am65xx_som) || defined(j7es_som) || defined(SOC_J721E)))
    UART_printf("\n\rWriting the output PORT2 register value "
                "of I2C Boot mode buffer...\n\r");
    ret = BoardDiag_write_register(handle,
                                   BOARD_I2C_BOOT_MODE_SW_ADDR,
                                   CMD_CFG_PORT2_REG_ACCESS,
                                   0x0);
    if(ret != 0)
    {
        UART_printf("Reading the input PORT2 register of "
                    "I2C Boot mode buffer failed\n\r");
        /* Closing the boot mode buffer i2c instance */
        I2C_close(handle);
        return -1;
    }
#endif

    UART_printf("\n\rWriting the output PORT0 register value "
                "of I2C Boot mode buffer...\n\r");
    ret = BoardDiag_write_register(handle,
                                   BOARD_I2C_BOOT_MODE_SW_ADDR,
                                   CMD_OUTPUT_PORT0_REG_ACCESS,
                                   BOOTMODE_CFG_SET1_PIN_POS);
    if(ret != 0)
    {
        UART_printf("Reading the input PORT0 register of "
                    "I2C Boot mode buffer failed\n\r");
        /* Closing the boot mode buffer i2c instance */
        I2C_close(handle);
        return -1;
    }

    UART_printf("\n\rWriting the output PORT1 register value "
                "of I2C Boot mode buffer...\n\r");
    ret = BoardDiag_write_register(handle,
                                   BOARD_I2C_BOOT_MODE_SW_ADDR,
                                   CMD_OUTPUT_PORT1_REG_ACCESS,
                                   BOOTMODE_CFG_SET2_PIN_POS);
    if(ret != 0)
    {
        UART_printf("Reading the input PORT1 register of "
                    "I2C Boot mode buffer failed\n\r");
        /* Closing the boot mode buffer i2c instance */
        I2C_close(handle);
        return -1;
    }

    ret = BoardDiag_read_register(handle,
                                  BOARD_I2C_BOOT_MODE_SW_ADDR,
                                  CMD_INPUT_PORT0_REG_ACCESS,
                                  &port0RegData);
    if(ret != 0)
    {
        UART_printf("Reading the input PORT0 register of "
                    "I2C Boot mode buffer failed\n\r");
        /* Closing the boot mode buffer i2c instance */
        I2C_close(handle);
        return -1;
    }

    UART_printf("\n\rReading the input PORT1 register value "
                "of I2C Boot mode buffer...\n\r");
    ret = BoardDiag_read_register(handle,
                                  BOARD_I2C_BOOT_MODE_SW_ADDR,
                                  CMD_INPUT_PORT1_REG_ACCESS,
                                  &port1RegData);
    if(ret != 0)
    {
        UART_printf("Reading the input PORT1 register of "
                    "I2C Boot mode buffer failed\n\r");
        /* Closing the boot mode buffer i2c instance */
        I2C_close(handle);
        return -1;
    }

    /* Closing the boot mode buffer i2c instance */
    I2C_close(handle);

    return ret;
}

/**
 *  \brief    The function performs the Automation header test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_automationHeaderTest(void)
{
    int8_t ret = 0;
#if defined(am65xx_som) || defined(j7es_som) || defined(SOC_J721E)
    i2cIoExpSignalLevel_t signalLev = GPIO_SIGNAL_LEVEL_LOW;
    Board_I2cInitCfg_t i2cCfg;
#endif
    UART_printf("\n***************************************************\n");
    UART_printf  ("*              Automation Header Test             *\n");
    UART_printf  ("***************************************************\n");

#if defined(j7es_som)
    enableI2C(CSL_WKUP_I2C0_CFG_BASE);
#endif
#if (defined(am65xx_som) || defined(j7es_som) || defined(SOC_J721E))
    /* I2C Mux select */
    i2cCfg.i2cInst   = BOARD_I2C_IOEXP_DEVICE2_INSTANCE;
    i2cCfg.socDomain = BOARD_SOC_DOMAIN_MAIN;
    Board_setI2cInitConfig(&i2cCfg);

    Board_i2cIoExpInit();
#if defined(SOC_J721E)
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  THREE_PORT_IOEXP,
                                  PORTNUM_1,
                                  PIN_NUM_0, /* CTRL_PM_I2C_OE# */
                                  PIN_DIRECTION_OUTPUT);

    /* Pulling PM bus switch to high for accessing the INA devices */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              THREE_PORT_IOEXP,
                              PORTNUM_1,
                              PIN_NUM_0,
                              (i2cIoExpSignalLevel_t) GPIO_SIGNAL_LEVEL_HIGH);
#endif
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  THREE_PORT_IOEXP,
                                  PORTNUM_1,
                                  PIN_NUM_3, /* MLB_MUX_SEL */
                                  PIN_DIRECTION_OUTPUT);

    /* Pulling the select input line to low to select port 1 */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              THREE_PORT_IOEXP,
                              PORTNUM_1,
                              PIN_NUM_3,
                              signalLev);

    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  THREE_PORT_IOEXP,
                                  PORTNUM_1,
                                  PIN_NUM_4, /* MCAN_MUX_SEL */
                                  PIN_DIRECTION_OUTPUT);

    /* Pulling the select input line to low to select port 1 */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              THREE_PORT_IOEXP,
                              PORTNUM_1,
                              PIN_NUM_4,
                              signalLev);
    Board_i2cIoExpDeInit();

    GPIO_init();
    /* Selecting PM1 I2C */
    GPIO_write(0U, SIGNAL_LEVEL_LOW);
#endif
#if defined(j7es_som)
    enableI2C(CSL_I2C0_CFG_BASE);
#endif
    ret = BoardDiag_run_automation_header_test();
    if(ret != 0)
    {
        UART_printf("Automation header test failed!\n");
    }
    else
    {
        UART_printf("Automation header test passed!\n");
    }

    return ret;
}

/**
 *  \brief   automation header test main function
 *
 *  \return  int - automation header test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
               BOARD_INIT_PINMUX_CONFIG |
               BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }
#if (defined(SOC_J721E) || defined(SOC_AM65XX)) && !defined (__aarch64__)
    /* MCU I2C instance will be active by default for R5 core.
     * Need update HW attrs to enable MAIN I2C instance.
     */
    enableMAINI2C(2, CSL_I2C2_CFG_BASE);
#endif

    return BoardDiag_automationHeaderTest();
}
