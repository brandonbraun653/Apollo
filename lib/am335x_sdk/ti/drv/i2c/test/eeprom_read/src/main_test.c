/**
 *  \file   main_test.c
 *
 *  \brief  Example application main file. This application will read the data
 *          from eeprom and compares it with the known data.
 *
 */

/*
 * Copyright (C) 2014 - 2020 Texas Instruments Incorporated - http://www.ti.com/
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

#ifdef USE_BIOS
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#endif /* #ifdef USE_BIOS */

#include <stdio.h>
#include <string.h>

/* TI-RTOS Header files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include "I2C_log.h"
#include "I2C_board.h"
#ifdef SOC_AM65XX
#include <ti/csl/soc.h>
#include <ti/drv/sciclient/sciclient.h>
#endif

#if defined (SOC_J721E) || defined(SOC_J7200)
#include <ti/csl/soc.h>
#if defined (BUILD_DSP_1) || defined (BUILD_DSP_2)
#include <ti/csl/csl_chipAux.h>
#endif
#include <ti/drv/sciclient/sciclient.h>
#endif

#include <ti/csl/csl_clec.h>

#include <ti/csl/arch/r5/csl_arm_r5.h>

#if defined (__C7100__)
#include <ti/csl/arch/csl_arch.h>
#endif

#if defined(UNITY_INCLUDE_CONFIG_H) && (defined(SOC_J721E) || defined(SOC_J7200))
#include <ti/build/unit-test/Unity/src/unity.h>
#include <ti/build/unit-test/config/unity_config.h>
#endif

void I2c_appC7xPreInit(void);

/* Define the I2C test interface */
typedef struct I2C_Tests_s
{
    bool     (*testFunc)(void *);
    int32_t  testId;
    bool     dmaMode;
    bool     intrMode;
    bool     cbMode;
    uint32_t timeout;
    char     testDesc[80];

} I2C_Tests;

/* I2C test ID definitions */
#define I2C_TEST_ID_BIT_RATE          0   /* I2C bit rate test in interrupt mode */
#define I2C_TEST_ID_PROBE_BUS_FREQ    1   /* I2C probe bus frequency Test in interrupt mode  */
#define I2C_TEST_ID_TIMEOUT_INT       2   /* I2C timeout test in interrupt mode */
#define I2C_TEST_ID_TIMEOUT_POLLING   3   /* I2C timeout test in polling mode */


#if defined (SOC_AM335X) || defined (SOC_AM437x)
/* EEPROM data -Board specific */
extern char eepromData[I2C_EEPROM_RX_LENGTH];
#endif

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/

#define I2C_TRANSACTION_TIMEOUT         (10000U)


/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

#if defined (idkAM572x)
char eepromData[I2C_EEPROM_TEST_LENGTH] = {0x55, 0x33, 0xEE, 0x41, 0x4D, 0x35, 0x37, 0x32,
                              0x49, 0x44};
#elif defined (idkAM574x)
char eepromData[I2C_EEPROM_TEST_LENGTH] = {0x55, 0x33, 0xEE, 0x41, 0x4D, 0x35, 0x37, 0x34,
                              0x49, 0x44};
#elif defined (idkAM571x)
char eepromData[I2C_EEPROM_TEST_LENGTH] = {0x55, 0x33, 0xEE, 0x41, 0x4D, 0x35, 0x37, 0x31,
                              0x49, 0x44};
#elif defined (evmAM572x)
char eepromData[I2C_EEPROM_TEST_LENGTH] = {0x55, 0x33, 0xEE, 0x41, 0x4d, 0x35, 0x37, 0x32,
                              0x50, 0x4d};
#elif defined (evmK2H) || defined (evmK2K) || defined (evmK2E) || defined (evmK2L) || defined (evmK2G) || defined (iceK2G) || defined (EVM_OMAPL137)
char eepromData[I2C_EEPROM_TEST_LENGTH] = {0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08,
                              0x09, 0x10};
#elif defined (evmC6678) || defined (evmC6657) || defined (am65xx_evm) || defined (am65xx_idk) || defined (j721e_sim) || defined (j721e_evm) || defined(j7200_evm)
char eepromData[I2C_EEPROM_TEST_LENGTH] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                              0x00, 0x00};
#else
#endif

/*
 *  ======== Board_initI2C ========
 */
bool Board_initI2C(void)
{
    Board_initCfg boardCfg;
    Board_STATUS  boardStatus;
#if defined (idkAM571x)
    Board_IDInfo  id;
#endif
    I2C_HwAttrs   i2c_cfg;
#if defined (evmK2G)
    Board_SoCInfo socInfo;
#endif

#if defined(evmK2E) || defined(evmC6678)
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#endif
    boardStatus = Board_init(boardCfg);
    if (boardStatus != BOARD_SOK)
    {
        return (false);
    }
    
    I2C_init();

   /* Get the default I2C init configurations */
    I2C_socGetInitCfg(I2C_EEPROM_INSTANCE, &i2c_cfg);

    /* Modify the default I2C configurations if necessary */
#if defined(SOC_AM65XX)
    /* No I2C instanced connected to eeprom in main domain, use i2c instance in wakeup domain */
    i2c_cfg.baseAddr = CSL_WKUP_I2C0_CFG_BASE;
#if defined (__aarch64__)
    i2c_cfg.intNum = CSL_GIC0_INTR_WKUP_I2C0_BUS_POINTRPEND;
#else
    i2c_cfg.intNum = CSL_MCU0_INTR_I2C0_POINTRPEND;
#endif
#endif

#if defined (SOC_J721E) || defined(SOC_J7200)
    /* No I2C instanced connected to eeprom in main domain, use i2c instance in wakeup domain */
    i2c_cfg.baseAddr = CSL_WKUP_I2C0_CFG_BASE;
#if defined (BUILD_MPU)
    i2c_cfg.intNum = CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_WKUP_I2C0_POINTRPEND_0;
#endif
#if defined (BUILD_MCU)
    CSL_ArmR5CPUInfo info;

    CSL_armR5GetCpuID(&info);
    if (info.grpId != (uint32_t)CSL_ARM_R5_CLUSTER_GROUP_ID_0)
    {
        /*
         * Pulsar R5 core is on the Main domain, use the Main Pulsar
         * interrupt router
         */
        i2c_cfg.intNum = 256U; /* value 256 - 511 reserved for IR output */
    }
    else
    {
        /* Pulsar R5 core is on the MCU domain */
        i2c_cfg.intNum = CSLR_MCU_R5FSS0_CORE0_INTR_WKUP_I2C0_POINTRPEND_0;
    }
#endif
#if defined (BUILD_C7X_1)
    i2c_cfg.eventId = CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_WKUP_I2C0_POINTRPEND_0 + 992U, /* eventId, input event # to CLEC */
#endif
#endif

    /* Set the default I2C init configurations */
    I2C_socSetInitCfg(I2C_EEPROM_INSTANCE, &i2c_cfg);

/* --- TODO: move this into the board library --- */
/* For SYSBIOS only */
#ifndef BAREMETAL 
#if defined (SOC_J721E)
/* set up C7x CLEC for DMTimer0 */
#if defined (BUILD_C7X_1)
    CSL_ClecEventConfig   cfgClec;
    CSL_CLEC_EVTRegs     *clecBaseAddr = (CSL_CLEC_EVTRegs *)CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE;
    uint32_t input         = CSLR_COMPUTE_CLUSTER0_GIC500SS_SPI_TIMER0_INTR_PEND_0 + 992; /* Used for Timer Interrupt */

    /* Configure CLEC for DMTimer0, SYS/BIOS uses interrupt 14 for DMTimer0 by default */
    cfgClec.secureClaimEnable = FALSE;
    cfgClec.evtSendEnable     = TRUE;
    cfgClec.rtMap             = CSL_CLEC_RTMAP_CPU_ALL;
    cfgClec.extEvtNum         = 0;
    cfgClec.c7xEvtNum         = 14;
    CSL_clecConfigEvent(clecBaseAddr, input, &cfgClec);
#endif /* for C7X cores */

/* set up C66x Interrupt Router for DMTimer0 for C66x */
#if defined (BUILD_DSP_1) || defined (BUILD_DSP_2)
    int32_t                              retVal;
    struct tisci_msg_rm_irq_set_req      rmIrqReq;
    struct tisci_msg_rm_irq_set_resp     rmIrqResp;
    uint16_t                             dst_id;
    uint16_t                             dst_host_irq;

    /* Set up C66x interrupt router for DMTimer0 */
    memset (&rmIrqReq, 0, sizeof(rmIrqReq));
    rmIrqReq.secondary_host = TISCI_MSG_VALUE_RM_UNUSED_SECONDARY_HOST;
    rmIrqReq.src_id = TISCI_DEV_TIMER0;
    rmIrqReq.src_index = 0; /* set to 0 for non-event based interrupt */

    /* Set the destination interrupt */
    rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_ID_VALID;
    rmIrqReq.valid_params |= TISCI_MSG_VALUE_RM_DST_HOST_IRQ_VALID;

    if (CSL_chipReadDNUM() == 0U)
    {
        /* Set the destination for core0 */
       dst_id = TISCI_DEV_C66SS0_CORE0;
       /* rmIrqReq.dst_host_irq has to match the DMTimer.timerSettings[0].eventId defined in sysbios_c66.cfg */
       dst_host_irq = 21U;
    }
    else
    {
        /* Set the destination for core1 */
       dst_id = TISCI_DEV_C66SS1_CORE0;
       dst_host_irq = 20U;
    }
    rmIrqReq.dst_id       = dst_id;
    rmIrqReq.dst_host_irq = dst_host_irq; /* DMSC dest event, input to C66x INTC  */

    /* Config event */
    retVal = Sciclient_rmIrqSet(
                (const struct tisci_msg_rm_irq_set_req *)&rmIrqReq,
                &rmIrqResp,
                SCICLIENT_SERVICE_WAIT_FOREVER);
    if(0U != retVal)
    {
       return (false);
    }
#endif /* for C66X cores */
#endif /* for SOC_J721E */
#endif /* for SYSBIOS */
/* --- TODO: move this into the board library --- */

#if defined (idkAM571x)
    boardStatus = Board_getIDInfo(&id);
    if (boardStatus != BOARD_SOK)
    {
        return (false);
    }
    memcpy(eepromData, &id.header[I2C_EEPROM_TEST_ADDR],
           BOARD_EEPROM_HEADER_LENGTH - I2C_EEPROM_TEST_ADDR);
    memcpy(&eepromData[BOARD_EEPROM_HEADER_LENGTH - I2C_EEPROM_TEST_ADDR],
           id.boardName,
           I2C_EEPROM_TEST_LENGTH - BOARD_EEPROM_HEADER_LENGTH + I2C_EEPROM_TEST_ADDR);
#endif

#if defined (evmK2G)
    /* Read the SoC info to get the System clock value */
    Board_getSoCInfo(&socInfo);
    if(socInfo.sysClock != BOARD_SYS_CLK_DEFAULT)
    {
        /* Get the default I2C init configurations */
        I2C_socGetInitCfg(I2C_EEPROM_INSTANCE, &i2c_cfg);
        /* Update the I2C functional clock based on CPU clock - 1G or 600MHz */
        i2c_cfg.funcClk = socInfo.sysClock/6;
        /* Set the default I2C init configurations */
        I2C_socSetInitCfg(I2C_EEPROM_INSTANCE, &i2c_cfg);
    }
#endif

    return (true);
}

/*
 *  ======== I2C init config ========
 */
static void I2C_initConfig(uint32_t instance, I2C_Tests *test)
{
    I2C_HwAttrs   i2c_cfg;

    /* Get the default SPI init configurations */
    I2C_socGetInitCfg(instance, &i2c_cfg);

#if defined (SOC_J721E)
#if defined (BUILD_DSP_1) || defined (BUILD_DSP_2)
    /*
     * There is no interrupt routing supported in sciclient to
     * route wakeup domain I2C0 interrupt to C66x cores due to
     * the hardware limitation, use polling mode for eeprom test
     */
    i2c_cfg.enableIntr = false;
#else
    i2c_cfg.enableIntr = test->intrMode;
#endif
#else
    i2c_cfg.enableIntr = test->intrMode;
#endif

    /* Set the SPI init configurations */
    I2C_socSetInitCfg(instance, &i2c_cfg);
}

/*
 *  ======== CompareData ========
 */
static bool CompareData(char *expData, char *rxData, uint32_t length)
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

static bool i2c_bitrate_test (I2C_BitRate bitRate, I2C_Tests *test)
{
    char            bitRateLog[4][10] = {"100Kbps", "400Kbps", "1Mbps", "3.4Mbps"};
    I2C_Params      i2cParams;
    I2C_Handle      handle = NULL;
    I2C_Transaction i2cTransaction;
    char            txBuf[I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE] = {0x00, };
    char            rxBuf[I2C_EEPROM_TEST_LENGTH];
    int16_t         status;
    bool            copyData = FALSE;
    bool            testStatus = true;

    /* Set the I2C EEPROM write/read address */
    txBuf[0] = (I2C_EEPROM_TEST_ADDR >> 8) & 0xff; /* EEPROM memory high address byte */
    txBuf[1] = I2C_EEPROM_TEST_ADDR & 0xff;        /* EEPROM memory low address byte */

    I2C_initConfig(I2C_EEPROM_INSTANCE, test);

    I2C_Params_init(&i2cParams);

    /* Set bitRate */
    i2cParams.bitRate = bitRate;
    handle = I2C_open(I2C_EEPROM_INSTANCE, &i2cParams);
    if (handle == NULL)
    {
        goto Err;
    }

#ifdef I2C_EEPROM_WRITE_ENABLE
    /* Write to EEPROM */
    memcpy(&txBuf[I2C_EEPROM_ADDR_SIZE], eepromData, I2C_EEPROM_TEST_LENGTH);
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = I2C_EEPROM_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE;
    i2cTransaction.readBuf = NULL;
    i2cTransaction.readCount = 0;
    i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
    status = I2C_transfer(handle, &i2cTransaction);

    if(I2C_STS_SUCCESS != status)
    {
        I2C_log("\n I2C Test: ");
        I2C_log(bitRateLog[bitRate]);
        I2C_log(": Write Data Transfer failed. \n");
        testStatus = false;
        goto Err;
    }

#if defined (evmK2H) || defined (evmK2K) || defined (evmK2E) || defined (evmK2L) || defined (evmK2G) || defined (iceK2G) || defined (am65xx_evm) || defined (am65xx_idk) || defined (j721e_sim) || defined (j721e_evm) || defined (j7200_evm)
    BOARD_delay(I2C_EEPROM_TEST_DELAY);
#endif
#else
#if defined (evmK2H) || defined (evmK2K) || defined (evmK2E) || defined (evmK2L) || defined (evmK2G) || defined (iceK2G) || defined (EVM_OMAPL137) || defined (am65xx_evm) || defined (am65xx_idk) || defined (j721e_sim) || defined (j721e_evm) || defined(j7200)
    /* EEPROM write disabled on K2, need copy data */
    copyData = TRUE;
#endif
#endif
    memset(rxBuf, 0, I2C_EEPROM_TEST_LENGTH);
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = I2C_EEPROM_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
    i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
    i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH;
    i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
    status = I2C_transfer(handle, &i2cTransaction);

    if(I2C_STS_SUCCESS != status)
    {
        I2C_log("\n I2C Test: ");
        I2C_log(bitRateLog[bitRate]);
        I2C_log(": Read Data Transfer failed. \n");
        testStatus = false;
        goto Err;
    }
    else
    {
#if defined (evmC6678) || defined (evmC6657) || defined (am65xx_evm) || defined (am65xx_idk) || defined (j721e_sim) || defined (j721e_evm) || defined (j7200_evm)
        copyData = TRUE;
#endif

        /* read only test, copy data from rx buffer to eepromData to pass the test */
        if (copyData)
            memcpy(eepromData, rxBuf, I2C_EEPROM_TEST_LENGTH);

        testStatus = CompareData(&eepromData[0], &rxBuf[0], I2C_EEPROM_TEST_LENGTH);
        if(false == testStatus)
        {
            I2C_log("\n I2C Test: ");
            I2C_log(bitRateLog[bitRate]);
            I2C_log(": Data Mismatch \n");
        }
    }

Err:
    if (handle)
    {
        I2C_close(handle);
    }

    return (testStatus);
}

static bool I2C_bitrate_test(void *arg)
{
    bool       testResult = true;
    uint32_t   i;

    for (i = 0; i < 2; i++)
    {
        testResult = i2c_bitrate_test((I2C_BitRate)i, (I2C_Tests *)arg);
        if (testResult == false)
        {
            break;
        }
    }

    return (testResult);
}


#if defined (SOC_AM335X) || defined (SOC_AM437x) || defined (SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_AM574x) || defined (SOC_AM65XX) || defined (SOC_J721E) || defined (SOC_J7200)
static bool I2C_Probe_BusFrequency_test(void *arg)
{
    I2C_Handle      handle;
    I2C_Params      i2cParams;
    uint32_t        busFrequency;
    bool            status = false;
    int16_t         transferStatus;
    I2C_Transaction i2cTransaction;
    uint32_t        slaveAddress;
    int32_t         controlStatus;
    char            txBuf[I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE] = {0x00, };
    char            rxBuf[I2C_EEPROM_TEST_LENGTH];
    uint32_t        delayValue;
    I2C_Tests      *test = (I2C_Tests *)arg;

    I2C_initConfig(I2C_EEPROM_INSTANCE, test);

    I2C_Params_init(&i2cParams);
    handle = I2C_open(I2C_EEPROM_INSTANCE, &i2cParams);
    if (handle == NULL)
    {
        goto Err;
    }

    /* Set the I2C EEPROM write/read address */
    txBuf[0] = (I2C_EEPROM_TEST_ADDR >> 8) & 0xff; /* EEPROM memory high address byte */
    txBuf[1] = I2C_EEPROM_TEST_ADDR & 0xff;        /* EEPROM memory low address byte */


    /* Test Runtime Configuration of Bus Frequency */

    /* Test runtime configuration of 400 kHz */
    busFrequency = I2C_400kHz;
    I2C_control(handle, I2C_CMD_SET_BUS_FREQUENCY, &busFrequency);

    memset(rxBuf, 0, I2C_EEPROM_TEST_LENGTH);
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = I2C_EEPROM_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
    i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
    i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH;
    i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
    transferStatus = I2C_transfer(handle, &i2cTransaction);

    if(I2C_STS_SUCCESS != transferStatus)
    {
        I2C_log("\n I2C Test: Dynamic configuration of bus Freq failed. \n");
        goto Err;
    }

    status = CompareData(&eepromData[0], &rxBuf[0], I2C_EEPROM_TEST_LENGTH);

    if(true == status)
    {
        /* Test runtime configuration of 100 kHz */
        busFrequency = I2C_100kHz;
        I2C_control(handle, I2C_CMD_SET_BUS_FREQUENCY, &busFrequency);

        memset(rxBuf, 0, I2C_EEPROM_TEST_LENGTH);
        I2C_transactionInit(&i2cTransaction);
        i2cTransaction.slaveAddress = I2C_EEPROM_ADDR;
        i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
        i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
        i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
        i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH;
        i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
        transferStatus = I2C_transfer(handle, &i2cTransaction);

        if(I2C_STS_SUCCESS != transferStatus)
        {
            I2C_log("\n I2C Test: Dynamic configuration of bus Freq failed. \n");
            goto Err;
        }

        status = CompareData(&eepromData[0], &rxBuf[0], I2C_EEPROM_TEST_LENGTH);
    }

    /* Test Probe functionality */

    if(true == status)
    {
        /* Probe test with valid slave address */
        slaveAddress = I2C_EEPROM_ADDR;
        controlStatus = I2C_control(handle, I2C_CMD_PROBE, &slaveAddress);

        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            status = true;
        }
        else
        {
            status = false;
            I2C_log("\n I2C Test: Probe test failed. \n");
            goto Err;
        }
    }

    if(true == status)
    {
        /* Probe test with invalid slave address */
        slaveAddress = 0x70U;
        controlStatus = I2C_control(handle, I2C_CMD_PROBE, &slaveAddress);

        if(I2C_STATUS_ERROR == controlStatus)
        {
            status = true;
        }
        else
        {
            status = false;
            I2C_log("\n I2C Test: Probe test failed. \n");
            goto Err;
        }
    }

    if(true == status)
    {
        /* Test bus recovery functionality */
        delayValue = 2000U;
        controlStatus = I2C_control(handle, I2C_CMD_RECOVER_BUS, &delayValue);

        if(I2C_STATUS_SUCCESS == controlStatus)
        {
            memset(rxBuf, 0, I2C_EEPROM_TEST_LENGTH);
            I2C_transactionInit(&i2cTransaction);
            i2cTransaction.slaveAddress = I2C_EEPROM_ADDR;
            i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
            i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
            i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
            i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH;
            i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
            transferStatus = I2C_transfer(handle, &i2cTransaction);

            if(I2C_STS_SUCCESS != transferStatus)
            {
                I2C_log("\n I2C Test: Bus recovery test failed. \n");
                goto Err;
            }

            status = CompareData(&eepromData[0], &rxBuf[0], I2C_EEPROM_TEST_LENGTH);
        }
        else
        {
            status = false;
        }
    }

Err:
    if (handle)
    {
        I2C_close(handle);
    }
    return status;
}

static bool I2C_timeout_test(void *arg)
{
    I2C_Handle      handle;
    I2C_Params      i2cParams;
    uint32_t        busFrequency;
    bool            status = false;
    int16_t         transferStatus;
    I2C_Transaction i2cTransaction;
    char            txBuf[I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE] = {0x00, };
    char            rxBuf[I2C_EEPROM_TEST_LENGTH];
    I2C_Tests      *test = (I2C_Tests *)arg;

    /* Set the I2C EEPROM write/read address */
    txBuf[0] = (I2C_EEPROM_TEST_ADDR >> 8) & 0xff; /* EEPROM memory high address byte */
    txBuf[1] = I2C_EEPROM_TEST_ADDR & 0xff;        /* EEPROM memory low address byte */

    I2C_initConfig(I2C_EEPROM_INSTANCE, test);

    I2C_Params_init(&i2cParams);
    handle = I2C_open(I2C_EEPROM_INSTANCE, &i2cParams);
    if (handle == NULL)
    {
        goto Err;
    }

    /* Test Runtime Configuration of Bus Frequency */

    /* Test runtime configuration of 400 kHz */
    busFrequency = I2C_100kHz;
    I2C_control(handle, I2C_CMD_SET_BUS_FREQUENCY, &busFrequency);

    memset(rxBuf, 0, I2C_EEPROM_TEST_LENGTH);
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = I2C_EEPROM_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
    i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
    i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH;
    i2cTransaction.timeout   = test->timeout;
    transferStatus = I2C_transfer(handle, &i2cTransaction);

    if(I2C_STS_ERR_TIMEOUT == transferStatus)
    {
        status = true;
    }

Err:
    if (handle)
    {
        I2C_close(handle);
    }

    return status;
}
#endif

void I2C_test_print_test_desc(I2C_Tests *test)
{
    char        testId[16] = {0, };

    /* Print unit test ID */
    sprintf(testId, "%d", test->testId);
    I2C_log("\n I2C UT %s\n", testId);

    /* Print test description */
    I2C_log("\n %s\n", test->testDesc);
}

I2C_Tests I2c_tests[] =
{
    /* testFunc                   testID                       dma    intr   cbMode timeout                  testDesc */
    {I2C_bitrate_test,            I2C_TEST_ID_BIT_RATE,        false, true,  false, SemaphoreP_WAIT_FOREVER, "\r\n I2C bit rate test in interrupt mode"},
#if defined (SOC_AM335X) || defined (SOC_AM437x) || defined (SOC_AM571x) || defined (SOC_AM572x) || defined (SOC_AM574x) || defined (SOC_AM65XX) || defined (SOC_J721E) || defined (SOC_J7200)
    {I2C_Probe_BusFrequency_test, I2C_TEST_ID_PROBE_BUS_FREQ,  false, true,  false, SemaphoreP_WAIT_FOREVER, "\r\n I2C probe bus freq test in interrupt mode"},
    {I2C_timeout_test,            I2C_TEST_ID_TIMEOUT_INT,     false, true,  false, 1,                       "\r\n I2C timeout test in interrupt mode"},
    {I2C_timeout_test,            I2C_TEST_ID_TIMEOUT_POLLING, false, false, false, 1,                       "\r\n I2C timeout test in polling mode"},
#endif
    {NULL, },
};


#if defined(UNITY_INCLUDE_CONFIG_H) && (defined(SOC_J721E) || defined(SOC_J7200))
/*
 *  ======== Unity set up and tear down ========
 */
void setUp(void)
{
    /* Do nothing */
}

void tearDown(void)
{
    /* Do nothing */
}

bool test_I2C_Eeprom_common(void)
{
    bool       testResult = true;
    uint32_t   i;
    I2C_Tests *test;

    if (Board_initI2C() == false)
    {
        I2C_log("\r\n %s Board_initI2C failed\r\n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_FAIL();
#endif
        while(1);
    }

    for (i = 0; ; i++)
    {
        test = &I2c_tests[i];
        if (test->testFunc == NULL)
        {
            break;
        }
        I2C_test_print_test_desc(test);
        if (test->testFunc((void *)test) == true)
        {
            I2C_log("\r\n %s have passed\r\n", test->testDesc);
        }
        else
        {
            I2C_log("\r\n %s have failed\r\n", test->testDesc);
            testResult = false;
            break;
        }
    }
    return testResult;
}

void test_I2C_Eeprom_TestApp(void)
{
    bool       testResult = true;
    testResult = test_I2C_Eeprom_common();

    if(testResult == true)
    {
        I2C_log("\n All tests have passed. \n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_PASS();
#endif
    }
    else
    {
        I2C_log("\n Some tests have failed. \n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_FAIL();
#endif
    }

    while (true)
    {
    }
}

void test_I2C_Eeprom_BareMetal_TestApp(void)
{
    bool       testResult = true;
    testResult = test_I2C_Eeprom_common();

    if(testResult == true)
    {
        I2C_log("\n All tests have passed. \n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_PASS();
#endif
    }
    else
    {
        I2C_log("\n Some tests have failed. \n");
#ifdef UNITY_INCLUDE_CONFIG_H
        TEST_FAIL();
#endif
    }

    while (true)
    {
    }
}

void test_I2C_Eeprom_TestApp_runner(void)
{
    /* @description: Test runner for I2C_Eeprom Test App
                     and I2C_Eeprom BareMetal Test App

       @requirements:PRSDK-6918, PRSDK-6919, PRSDK-6922,
                     PRSDK-6924, PRSDK-6930

       @cores: mpu1_0, mcu1_0 */

    UNITY_BEGIN();
#ifdef USE_BIOS
    RUN_TEST(test_I2C_Eeprom_TestApp);
#else
    RUN_TEST(test_I2C_Eeprom_BareMetal_TestApp);
#endif
    UNITY_END();
    /* Function to print results defined in our unity_config.h file */
    print_unityOutputBuffer_usingUARTstdio();
}
#endif

#ifdef USE_BIOS
/*
 *  ======== test function ========
 */
void i2c_test(UArg arg0, UArg arg1)
#else
int main ()
#endif
{
#if defined(UNITY_INCLUDE_CONFIG_H) && (defined(SOC_J721E) || defined(SOC_J7200))
    test_I2C_Eeprom_TestApp_runner();
#else
    bool       testResult = true;
    uint32_t   i;
    I2C_Tests *test;

    if (Board_initI2C() == false)
    {
#ifdef USE_BIOS
        return;
#else
        return(0);
#endif        
    }

    for (i = 0; ; i++)
    {
        test = &I2c_tests[i];
        if (test->testFunc == NULL)
        {
            break;
        }
        I2C_test_print_test_desc(test);
        if (test->testFunc((void *)test) == true)
        {
            I2C_log("\r\n %s have passed\r\n", test->testDesc);
        }
        else
        {
            I2C_log("\r\n %s have failed\r\n", test->testDesc);
            testResult = false;
            break;
        }
    }
    if(testResult == true)
    {
        I2C_log("\n All tests have passed. \n");
    }
    else
    {
        I2C_log("\n Some tests have failed. \n");
    }
    while (true)
    {
    }
#endif
}

#ifdef USE_BIOS
/*
 *  ======== main ========
 */
int main(void)
{
    I2c_appC7xPreInit();
    
#if defined (SOC_AM335X) || defined (SOC_AM437x) || defined (SOC_OMAPL137)
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);

    task = Task_create(i2c_test, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
#endif

#if defined (SOC_J721E) || defined(SOC_J7200)
    Task_Handle task;
    Error_Block eb;
    Task_Params taskParams;

    Error_init(&eb);

    /* Initialize the task params */
    Task_Params_init(&taskParams);

    /* Set the task priority higher than the default priority (1) */
    taskParams.priority = 2;
    taskParams.stackSize = 0x8000;

    task = Task_create(i2c_test, &taskParams, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
#endif

    /* Start BIOS */
    BIOS_start();
    return (0);
}
#endif /* #ifdef USE_BIOS */

#if defined(BUILD_MPU) || defined (__C7100__)
extern void Osal_initMmuDefault(void);
void InitMmu(void)
{
    Osal_initMmuDefault();
}
#endif

void I2c_appC7xPreInit(void)
{
#if defined (__C7100__)
    CSL_ClecEventConfig cfgClec;
	CSL_CLEC_EVTRegs   *clecBaseAddr = (CSL_CLEC_EVTRegs*) CSL_COMPUTE_CLUSTER0_CLEC_REGS_BASE;   
    uint32_t            i, maxInputs = 2048U;

    /* make secure claim bit to FALSE so that after we switch to non-secure mode
     * we can program the CLEC MMRs
     */
    cfgClec.secureClaimEnable = FALSE;
    cfgClec.evtSendEnable     = FALSE;
    cfgClec.rtMap             = CSL_CLEC_RTMAP_DISABLE;
    cfgClec.extEvtNum         = 0U;
    cfgClec.c7xEvtNum         = 0U;
    for(i = 0U; i < maxInputs; i++)
    {
        CSL_clecConfigEvent(clecBaseAddr, i, &cfgClec);
    }
#endif

    return;
}
