/**
 *  \file   main_test.c
 *
 *  \brief  The application Demonstrate the I2C master/slave mode functionality.
 *          I2C data are transferred from master to slave and at the
 *          same instance data from slave are transferred to master.
 *
 *  \details
 *          To demonstrate the example two boards are needed one board
 *          acts as master and another as slave.
 *
 *          Following is the Pin connection information:
 *          MasterI2C_SCL-----SlaveI2C_SCL
 *          MasterI2C_SDA-----SlaveI2C_SDA
 *
 *  \Running the example
 *          1) Connect the master and slave boards as per above pin connections.
 *          2) Two consoles. One for master and another for slave.
 *          3) Run slave application binary and then master application binary.
 *
 *  \Output
 *          At slave end console:
 *              All tests have passed.
 *
 *          At master end console:
 *              All tests have passed.
 */

/*
 * Copyright (C) 2016-2017 Texas Instruments Incorporated - http://www.ti.com/
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
#include <string.h>

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <ti/sysbios/knl/Task.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Error.h>

/* CSL Header files */
#ifdef _TMS320C6X
#include <ti/csl/csl_chip.h>
#endif

/* OSAL Header files */
#include <ti/osal/osal.h>

/* TI-RTOS Header files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/i2c/src/I2C_osal.h>
#include <ti/drv/i2c/test/src/I2C_log.h>

/* Board Header files */
#include <ti/board/board.h>

/*
 * slave address for master/slave board to board test, by default,
 * all the AM boards own slave address is set to 0x70 and all the
 * Keystone boards own slave address is set to 0x10.
 */

/*
 * master own slave address and transaction slave address
 */
#define I2C_TEST_MASTER_OSA_7B              0x20
#define I2C_TEST_MASTER_OSA_10B             0x220
#define I2C_TEST_MASTER_SA_7B               0x30
#define I2C_TEST_MASTER_SA_10B              0x230

/*
 * slave own slave address is set to master transaction slave address
 */
#define I2C_TEST_SLAVE_OSA_7B               I2C_TEST_MASTER_SA_7B
#define I2C_TEST_SLAVE_OSA_10B              I2C_TEST_MASTER_SA_10B

/*
 * This address is the own slave address set on the master board,
 * it shoud not be the same as the own slave address set on the
 * slave board
 */
#define I2C_OWN_SLAVE_ADDR_MASTER      0x60

/* I2C Test definitions */

/* Unit test IDs */
#define I2C_TEST_ID_DMA         0   /* I2C DMA mode test */
#define I2C_TEST_ID_INT         1   /* I2C non-DMA interrupt mode test */
#define I2C_TEST_ID_CB          2   /* I2C callback mode test */
#define I2C_TEST_ID_XA          3   /* I2C 10-bit address mode test */

/* Define the I2C test interface */
typedef struct I2C_Tests_s
{
    bool     (*testFunc)(void *);
    int16_t  testId;
    bool     master;
    bool     pollMode;
    bool     cbMode;
    bool     dmaMode;
    uint32_t timeout;
    char     testDesc[80];

} I2C_Tests;

typedef struct I2C_XferLen_s
{
    uint32_t wrLen;
    uint32_t rdLen;

} I2C_XferLen;

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/
#define I2C_MSG_LENGTH      10
#define I2C_MSG_LENGTH2     75

#define I2C_NUM_XFERS       6
I2C_XferLen masterXferLen[I2C_NUM_XFERS] =
{
    {
        I2C_MSG_LENGTH, 0
    },
    {
        I2C_MSG_LENGTH2, 0
    },
    {
        0, I2C_MSG_LENGTH
    },
    {
        0, I2C_MSG_LENGTH2
    },
    /* For restart transfer test */
    {
        I2C_MSG_LENGTH, I2C_MSG_LENGTH
    },
    {
        I2C_MSG_LENGTH2, I2C_MSG_LENGTH2
    }
};

I2C_XferLen slaveXferLen[I2C_NUM_XFERS] =
{
    {
        0, I2C_MSG_LENGTH
    },
    {
        0, I2C_MSG_LENGTH2
    },
    {
        I2C_MSG_LENGTH, 0
    },
    {
        I2C_MSG_LENGTH2, 0
    },
    /* For restart transfer test */
    {
        0, I2C_MSG_LENGTH
    },
    {
        0, I2C_MSG_LENGTH2
    }
};

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/
#if (defined(_TMS320C6X) || defined (__TI_ARM_V7M4__))
#pragma DATA_ALIGN (masterRxBuffer, 128)
unsigned char masterRxBuffer[I2C_MSG_LENGTH2 + 1];
#pragma DATA_ALIGN (slaveRxBuffer, 128)
unsigned char slaveRxBuffer[I2C_MSG_LENGTH2 + 1];
#else
unsigned char masterRxBuffer[I2C_MSG_LENGTH2 + 1] __attribute__ ((aligned (128)));
unsigned char slaveRxBuffer[I2C_MSG_LENGTH2 + 1] __attribute__ ((aligned (128)));
#endif


unsigned char masterTxBuffer[I2C_MSG_LENGTH2 + 1] = "Master Txd I2C Master Txd I2C Master Txd I2C Master Txd I2C Master Txd I2C ";
unsigned char slaveTxBuffer[I2C_MSG_LENGTH2 + 1] =  "Slave Txd I2C  Slave Txd I2C  Slave Txd I2C  Slave Txd I2C  Slave Txd I2C  ";

/* Transaction data */
I2C_Transaction   transaction;

/* Callback mode variables */
SemaphoreP_Params cbSemParams;
SemaphoreP_Handle cbSem = NULL;

/* Master callback mode function */
void I2C_callbackMaster(I2C_Handle handle, I2C_Transaction *transaction, int16_t transferStatus)
{
    I2C_osalPostLock(cbSem);
}

/* Slave callback mode function */
void I2C_callbackSlave(I2C_Handle handle, I2C_Transaction *transaction, int16_t transferStatus)
{
    if (transferStatus == I2C_STS_RESTART)
    {
        /* Restart condition */
        transaction->writeBuf = (void *)slaveTxBuffer;
        transaction->writeCount = I2C_MSG_LENGTH2;
    }
    else
    {
        I2C_osalPostLock(cbSem);
    }
}

/*
 *  ======== I2C init config ========
 */
static void I2C_initConfig(uint32_t instance, I2C_Tests *test)
{
    I2C_HwAttrs i2c_cfg;
    uint32_t    ownSlaveAddr;
    bool        master = test->master;
    bool        pollMode = test->pollMode;
#ifdef I2C_DMA_ENABLE
    bool        dmaMode = test->dmaMode;
#endif

    /* Get the default I2C init configurations */
    I2C_socGetInitCfg(instance, &i2c_cfg);

    /*
     * Set blocking mode (dma mode or non-dma interrupt mode)
     * or callback mode
     */
    if (pollMode == true)
    {
        /* polling mode */
        i2c_cfg.enableIntr = false;
    }
    else
    {
        /* interrupt enabled */
        i2c_cfg.enableIntr = true;
#ifdef I2C_DMA_ENABLE
        if (dmaMode == true)
        {
            /* Set the DMA related init config */
        }
#endif
    }

    if (master)
    {
        if (test->testId == I2C_TEST_ID_XA)
        {
            ownSlaveAddr = I2C_TEST_MASTER_OSA_10B;
        }
        else
        {
            ownSlaveAddr = I2C_TEST_MASTER_OSA_7B;
        }
    }
    else
    {
        if (test->testId == I2C_TEST_ID_XA)
        {
            ownSlaveAddr = I2C_TEST_SLAVE_OSA_10B;
        }
        else
        {
            ownSlaveAddr = I2C_TEST_SLAVE_OSA_7B;
        }
    }

#if defined (evmK2H) || defined (evmK2K) || defined (evmK2E) || defined (evmK2L) || defined (evmK2G) || defined (LCDK_OMAPL138)
    i2c_cfg.ownSlaveAddr = ownSlaveAddr;
#else
    i2c_cfg.ownSlaveAddr[0] = ownSlaveAddr;
#endif

    /* Set the I2C init configurations */
    I2C_socSetInitCfg(instance, &i2c_cfg);
}

bool I2C_verify_data(unsigned char *data1, unsigned char *data2, uint32_t length)
{
	uint32_t i;
	bool     ret = true;

    for (i = 0; i < length; i++)
    {
        if (data1[i] != data2[i])
        {
            ret = false;
            break;
        }
    }

	return (ret);
}

/*
 * Utility function which converts a local GEM L2 memory address
 * to global memory address.
 */
static uint32_t l2_global_address (uint32_t addr)
{
    if ((addr >= 0x800000) && (addr < 0x1000000))
    {
#ifdef _TMS320C6X
        uint32_t coreNum;

        /* Get the core number. */
        coreNum = CSL_chipReadReg(CSL_CHIP_DNUM);

#if defined(SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM574x)
        /* Compute the global address. */
        return ((1 << 30) | (coreNum << 24) | (addr & 0x00ffffff));

#else
  /* Compute the global address. */
        return ((1 << 28) | (coreNum << 24) | (addr & 0x00ffffff));
#endif
#else
        return addr;
#endif
    }
    else
    {
        /* non-L2 address range */
        return addr;
    }
}

static bool I2C_test_mst_slv_xfer(I2C_Handle i2c, I2C_Tests *test, uint32_t wrLen, uint32_t rdLen)
{
    bool            transferOK;
    uint32_t        addrMasterRxBuf, addrSlaveRxBuf;
    bool            ret = false;
    bool            master = test->master;
    bool            cbMode = test->cbMode;
    bool            dmaMode = test->dmaMode;
    uint32_t        timeout = test->timeout;
    uint32_t        slaveAddr;

    if (dmaMode)
    {
        addrMasterRxBuf = l2_global_address((uint32_t)masterRxBuffer);
        addrSlaveRxBuf = l2_global_address((uint32_t)slaveRxBuffer);
    }
    else
    {
        addrMasterRxBuf = (uint32_t)masterRxBuffer;
        addrSlaveRxBuf = (uint32_t)slaveRxBuffer;
    }

    memset(masterRxBuffer, 0, sizeof(masterRxBuffer));
    memset(slaveRxBuffer, 0, sizeof(slaveRxBuffer));
    if (dmaMode)
    {
        CacheP_wbInv((void *)addrMasterRxBuf, (int32_t)sizeof(masterRxBuffer));
        CacheP_wbInv((void *)slaveRxBuffer, (int32_t)sizeof(slaveRxBuffer));
    }

    /* Initialize slave I2C transaction structure */
    I2C_transactionInit(&transaction);
    transaction.writeCount = wrLen;
    transaction.readCount  = rdLen;
    transaction.timeout    = timeout;
    if (test->testId == I2C_TEST_ID_XA)
    {
        /* 10-bit slave address */
        slaveAddr = I2C_TEST_MASTER_SA_10B;
        transaction.expandSA = true;
    }
    else
    {
        /* 7-bit slave address */
        slaveAddr = I2C_TEST_MASTER_SA_7B;
        transaction.expandSA = false;
    }
    if (master == true)
    {
        transaction.masterMode   = true;
        transaction.slaveAddress = slaveAddr;
        transaction.writeBuf     = (Ptr)masterTxBuffer;
        transaction.readBuf      = (Ptr)addrMasterRxBuf;
    }
    else
    {
        transaction.masterMode   = false;
        transaction.slaveAddress = 0;
        transaction.writeBuf     = (Ptr)slaveTxBuffer;
        transaction.readBuf      = (Ptr)addrSlaveRxBuf;
        if (rdLen != 0)
        {
            /* for restart transfer, slave sends the data in callback mode */
            transaction.writeCount = 0;
        }
    }

    /* Initiate I2C transfer */
    transferOK = I2C_transfer(i2c, &transaction);

    if(transferOK)
    {
        if (cbMode)
        {
            if (I2C_osalPendLock(cbSem, timeout) != SemaphoreP_OK)
            {
                goto Err;
            }
        }

        if (master == true)
        {
            /* master mode, verify master recieved data match with slave sent data */
            if (I2C_verify_data(masterRxBuffer, slaveTxBuffer, rdLen) == false)
            {
                goto Err;
            }

            /* Print contents of master receive buffer */
            I2C_log("Master: %s\n", masterRxBuffer);
        }
        else
        {
            /* slave mode, verify slave recieved data match with master sent data */
            if (I2C_verify_data(slaveRxBuffer, masterTxBuffer, rdLen) == false)
            {
                goto Err;
            }
            /* Print contents of slave receive buffer */
            I2C_log("Slave: %s\n", slaveRxBuffer);
        }
    }
    else
    {
        I2C_log("Unsuccessful slave I2C transfer");
        goto Err;
    }

    ret = true;

Err:
    return (ret);
}


static bool I2C_test_master_slave(void *arg)
{
    I2C_Handle        i2c;
    I2C_Params        i2cParams;
    uint32_t          instance, i;
    I2C_XferLen      *xferLen;
    uint32_t          testNum;
    bool              ret = false;
    I2C_Tests        *test = (I2C_Tests *)arg;
    bool              master = test->master;
    bool              cbMode = test->cbMode;

    if (cbMode == true)
    {
        /* Create call back semaphore */
        I2C_osalSemParamsInit(&cbSemParams);
        cbSemParams.mode = SemaphoreP_Mode_BINARY;
        cbSem = I2C_osalCreateBlockingLock(0, &cbSemParams);
    }

    /* Soc configuration structures indexing starts from 0. If the IP
     * instances start with 1, to address proper Configuration
     * structure index, I2C Instance should be substracted with 1
     */
    if (master == true)
    {
        instance = BOARD_I2C_MASTER_INSTANCE;
    }
    else
    {
        instance = BOARD_I2C_SLAVE_INSTANCE;
    }

    I2C_initConfig(instance, test);

    /* Initialize I2C handle */
    I2C_Params_init(&i2cParams);

    if (cbMode == true)
    {
        i2cParams.transferMode = I2C_MODE_CALLBACK;
        if (master == true)
        {
            i2cParams.transferCallbackFxn = I2C_callbackMaster;
        }
        else
        {
            i2cParams.transferCallbackFxn = I2C_callbackSlave;
        }
    }
    i2c = I2C_open(instance, &i2cParams);

    if (i2c == NULL)
    {
        I2C_log("Error initializing I2C\n");
        goto Err;
    }
    else
    {
        I2C_log("I2C initialized\n");
    }

    if (cbMode == true)
    {
        testNum = I2C_NUM_XFERS;
    }
    else
    {
        /* do not test restart transfer in non-callback mode */
        testNum = I2C_NUM_XFERS - 2;
    }

    for (i = 0; i < testNum; i++)
    {
        if (master == true)
        {
            xferLen = &masterXferLen[i];
        }
        else
        {
            xferLen = &slaveXferLen[i];
        }
        if (I2C_test_mst_slv_xfer(i2c, test, xferLen->wrLen,
                                  xferLen->rdLen) == false)
        {
            goto Err;
        }

        if (master == true)
        {
            /*
             * master sleep for 1 second after each transfer
             * to sync with slave transfer
             */
            Task_sleep(1000);
        }
    }

    ret = true;

Err:
    if (i2c)
    {
        I2C_close(i2c);
    }

    if (cbSem)
    {
        I2C_osalDeleteBlockingLock(cbSem);
        cbSem = NULL;
    }
    return (ret);
}

void I2C_test_print_test_desc(I2C_Tests *test)
{
    char        testId[16] = {0, };

    /* Print unit test ID */
    sprintf(testId, "%d", test->testId);
	I2C_log("\r\n I2C UT %s\r\n", testId);

	/* Print test description */
	I2C_log("\r\n %s\r\n", test->testDesc);
}

#ifdef I2C_DMA_ENABLE
#define I2C_NUM_TESTS   4
#else
#define I2C_NUM_TESTS   3
#endif

I2C_Tests I2c_tests_master[I2C_NUM_TESTS] =
{
    /* testFunc             testID         master pollMode cbMode dmaMode timeout              testDesc */
#ifdef I2C_DMA_ENABLE
    {I2C_test_master_slave, I2C_TEST_ID_DMA, true, false, false, true, SemaphoreP_WAIT_FOREVER, "\r\n I2C master slave test master in dma mode"},
#endif
    {I2C_test_master_slave, I2C_TEST_ID_INT, true, false, false, false, SemaphoreP_WAIT_FOREVER, "\r\n I2C master slave test master in non-dma interrupt mode"},
    {I2C_test_master_slave, I2C_TEST_ID_CB, true, false, true, false, SemaphoreP_WAIT_FOREVER, "\r\n I2C master slave test master in callback mode"},
    {I2C_test_master_slave, I2C_TEST_ID_XA, true, false, false, false, SemaphoreP_WAIT_FOREVER, "\r\n I2C master slave test master 10-bit address mode"},
};

I2C_Tests I2c_tests_slave[I2C_NUM_TESTS] =
{
#ifdef I2C_DMA_ENABLE
    {I2C_test_master_slave, I2C_TEST_ID_DMA, false, false, false, true, SemaphoreP_WAIT_FOREVER, "\r\n I2C master slave test slave in dma mode"},
#endif
    {I2C_test_master_slave, I2C_TEST_ID_INT, false, false, false, false, SemaphoreP_WAIT_FOREVER, "\r\n I2C master slave test slave in non-dma interrupt mode"},
    {I2C_test_master_slave, I2C_TEST_ID_CB, false, false, true, false, SemaphoreP_WAIT_FOREVER, "\r\n I2C master slave test slave in callback mode"},
    {I2C_test_master_slave, I2C_TEST_ID_XA, false, false, false, false, SemaphoreP_WAIT_FOREVER, "\r\n I2C master slave test slave 10-bit address mode"},
};

/*
 *  ======== slaveTaskFxn ========
 *  The task is part of separate slave example project.
 *  To test slave mode example, slave task has to be
 *  ready for master. Slave I2C sends a message to master
 *  while receiving message from master.
 */
Void slaveTaskFxn (UArg arg0, UArg arg1)
{
    uint32_t  i;
    bool      testFail = false;
    I2C_Tests *test;

    I2C_init();

    for (i = 0; i < I2C_NUM_TESTS; i++)
    {
        test = &I2c_tests_slave[i];
        I2C_test_print_test_desc(test);
        if (test->testFunc((void *)test) == true)
        {
            I2C_log("\r\n %s have passed\r\n", test->testDesc);
        }
        else
        {
            I2C_log("\r\n %s have failed\r\n", test->testDesc);
            testFail = true;
            break;
        }
    }

    if(testFail == true)
    {
        UART_printStatus("\n Some tests have failed. \n");
    }
    else
    {
        UART_printStatus("\n All tests have passed. \n");
    }

    I2C_log("Done\n");

    Task_exit();
}

/*
 *  ======== masterTaskFxn ========
 *  This task is part of master example project.
 *  Slave task has to ensure transaction ready.
 *  Master I2C sends a message to slave and
 *  receives message from slave.
 */
Void masterTaskFxn (UArg arg0, UArg arg1)
{
    uint32_t  i;
    bool      testFail = false;
    I2C_Tests *test;

    I2C_init();

    for (i = 0; i < I2C_NUM_TESTS; i++)
    {
        test = &I2c_tests_master[i];
        I2C_test_print_test_desc(test);
        if (test->testFunc((void *)test) == true)
        {
            I2C_log("\r\n %s have passed\r\n", test->testDesc);
        }
        else
        {
            I2C_log("\r\n %s have failed\r\n", test->testDesc);
            testFail = true;
            break;
        }
    }

    if(testFail == true)
    {
        UART_printStatus("\n Some tests have failed. \n");
    }
    else
    {
        UART_printStatus("\n All tests have passed. \n");
    }

    I2C_log("Done\n");

    Task_exit();
}

/*
 *  ======== main ========
 */
int main(void)
{
    /* Call board init functions */
    Board_initCfg boardCfg;
#if defined (evmK2G)
    I2C_HwAttrs i2c_cfg;
    uint8_t instance;
    Board_SoCInfo socInfo;
#endif

#if defined(SOC_AM335x) || defined (SOC_AM437x)
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);
#if defined (I2C_SLAVE_TASK)
    task = Task_create(slaveTaskFxn, NULL, &eb);
#elif defined (I2C_MASTER_TASK)
    task = Task_create(masterTaskFxn, NULL, &eb);
#endif /* Task type */

    if (task == NULL)
    {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
#endif /* Soc type */

    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

#if defined (evmK2G)
    /* Read the SoC info to get the System clock value */
    Board_getSoCInfo(&socInfo);
    if(socInfo.sysClock != BOARD_SYS_CLK_DEFAULT)
    {
        for (instance = 0; instance < CSL_I2C_CNT; instance++)
        {
            /* Get the default I2C init configurations */
            I2C_socGetInitCfg(instance, &i2c_cfg);
            /* Update the I2C functional clock based on CPU clock - 1G or 600MHz */
            i2c_cfg.funcClk = socInfo.sysClock/I2C_MODULE_CLOCK_DIVIDER;
            /* Set the default I2C init configurations */
            I2C_socSetInitCfg(instance, &i2c_cfg);
        }
    }
#endif

    /* Start BIOS */
    BIOS_start();
    return (0);
}
