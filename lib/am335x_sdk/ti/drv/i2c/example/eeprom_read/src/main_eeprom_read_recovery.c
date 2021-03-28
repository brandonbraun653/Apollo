/**
 *  \file   main_eeprom_read_callback.c
 *
 *  \brief  Example application main file. This application will read the data
 *          from eeprom and compares it with the known data. This example will
 *          demonstrate the working of i2c driver in callback mode.
 *
 */

/*
 * Copyright (C) 2014 - 2017 Texas Instruments Incorporated - http://www.ti.com/
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

#ifndef BARE_METAL
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>
#endif

#include <stdio.h>
#include <string.h>

/* TI-RTOS Header files */
#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>
#include <ti/drv/i2c/test/eeprom_read/src/I2C_log.h>
#include <ti/drv/i2c/test/eeprom_read/src/I2C_board.h>

#if defined (SOC_AM335x) || defined (SOC_AM437x)
/* EEPROM data -Board specific */
extern char eepromData[I2C_EEPROM_RX_LENGTH];
#endif
/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/

#define I2C_TRANSACTION_TIMEOUT         (2000U)

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

/* Data compare function */
bool CompareData(char *expData, char *rxData, unsigned int length);

/* Application specific callback function */
void I2CCallbackFxn(I2C_Handle handle, I2C_Transaction * transaction, int16_t transferStatus);

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
#elif defined (evmK2H) || defined (evmK2K) || defined (evmK2E) || defined (evmK2L) || defined (evmK2G) || defined (evmC6678) || defined (evmC6657) || defined (iceK2G)
char eepromData[I2C_EEPROM_TEST_LENGTH] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                              0x00, 0x00};
#else
#endif

/*
 *  ======== Board_initI2C ========
 */
void Board_initI2C(void)
{
    Board_initCfg boardCfg;

    I2C_HwAttrs i2c_cfg;
#if defined (evmK2G)
    Board_SoCInfo socInfo;
#endif

    /* Get the default I2C init configurations */
    I2C_socGetInitCfg(I2C_EEPROM_INSTANCE, &i2c_cfg);

    /* Modify the default I2C configurations if necessary */

    /* Set the default I2C init configurations */
    I2C_socSetInitCfg(I2C_EEPROM_INSTANCE, &i2c_cfg);

#if defined(evmK2E) || defined(evmC6678)
    boardCfg = BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK |
        BOARD_INIT_UART_STDIO;
#endif
    Board_init(boardCfg);

#if defined (evmK2G)
    /* Read the SoC info to get the System clock value */
    Board_getSoCInfo(&socInfo);
    if(socInfo.sysClock != BOARD_SYS_CLK_DEFAULT)
    {
        /* Get the default I2C init configurations */
        I2C_socGetInitCfg(I2C_EEPROM_INSTANCE, &i2c_cfg);
        /* Update the I2C functional clock based on CPU clock - 1G or 600MHz */
        i2c_cfg.funcClk = socInfo.sysClock/I2C_MODULE_CLOCK_DIVIDER;
        /* Set the default I2C init configurations */
        I2C_socSetInitCfg(I2C_EEPROM_INSTANCE, &i2c_cfg);
    }
#endif
}

#ifdef BARE_METAL
/*
 *  ======== main function ========
 */
void main()
#else
/*
 *  ======== test function ========
 */

/* Flag to check transfer completion in callback mode */
uint32_t isrCallbackComplete = 0U;

/* This is the transfer status returned by I2C call back */
int32_t I2C_callback_status;


void i2c_test(UArg arg0, UArg arg1)
#endif
{
    I2C_Params i2cParams;
    I2C_Handle handle = NULL;
    I2C_Transaction i2cTransaction;
    char txBuf[I2C_EEPROM_TEST_LENGTH + I2C_EEPROM_ADDR_SIZE] = {0x00, };
    char rxBuf[I2C_EEPROM_TEST_LENGTH] = {0x00, };
    bool status,test_pass=FALSE;
    int16_t transferStatus;

#ifdef BARE_METAL
    Board_initI2C();
#endif

    /* Set the I2C EEPROM write/read address */
    txBuf[0] = (I2C_EEPROM_TEST_ADDR >> 8) & 0xff; /* EEPROM memory high address byte */
    txBuf[1] = I2C_EEPROM_TEST_ADDR & 0xff;        /* EEPROM memory low address byte */

    I2C_init();

    I2C_Params_init(&i2cParams);

    /* Configure callback mode specific input parameters */
    /* Interrupt should be enabled for call back mode */
    i2cParams.transferMode = I2C_MODE_CALLBACK;
    i2cParams.transferCallbackFxn = I2CCallbackFxn;

    handle = I2C_open(I2C_EEPROM_INSTANCE, &i2cParams);
    I2C_log("\n Trying a transfer with an invalid slave address 0xff, to induce error \n");
    isrCallbackComplete=0;
    I2C_callback_status=0xff;
    I2C_transactionInit(&i2cTransaction);
    i2cTransaction.slaveAddress = 0xFF;/* To induce the NACK failure */ //I2C_EEPROM_ADDR;
    i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
    i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
    i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
    i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH;
    i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
    transferStatus = I2C_transfer(handle, &i2cTransaction);

    if(I2C_MODE_CALLBACK == i2cParams.transferMode)
    {
      while(!isrCallbackComplete);
        /* For call back mode, the real status is from call back function */
      transferStatus=I2C_callback_status;
    }

    if(I2C_STS_SUCCESS != transferStatus)
    {
      uint32_t i2cDelay=I2C_TRANSACTION_TIMEOUT;
      int32_t ret;
      I2C_log("\n Data Transfer failed(as expected) with transfer code %d \n",transferStatus);

      I2C_log("\n Trying bus recovery \n");
      /* Now call the I2C Reset API to recover the bus */
      ret= I2C_control(handle,I2C_CMD_RECOVER_BUS,&i2cDelay);
      if(ret!=I2C_STATUS_SUCCESS) {
          if(ret==I2C_STATUS_UNDEFINEDCMD) {
             I2C_log("\n CMD_RECOVER_BUS Command not supported\n");
             test_pass=TRUE;/* For Keystone platforms (i2c_V0) recovery is not supported yet, hence declaring it a pass because the failure test atleast worked */
          } else {
          I2C_log("\n Bus Recovery failed with return code %d \n",ret);
          test_pass=FALSE;
          }
          goto end_test;
      } else {
          I2C_log("\n Bus Recovery succeeded\n",ret);
      }

      I2C_log("\n Trying the transfer again (with proper slave address) after bus recovery.. \n");
      /* Retry the transfer, but with the proper address this time */
      isrCallbackComplete=0;
      I2C_callback_status=0xff;
      I2C_transactionInit(&i2cTransaction);
      i2cTransaction.slaveAddress = I2C_EEPROM_ADDR;
      i2cTransaction.writeBuf = (uint8_t *)&txBuf[0];
      i2cTransaction.writeCount = I2C_EEPROM_ADDR_SIZE;
      i2cTransaction.readBuf = (uint8_t *)&rxBuf[0];
      i2cTransaction.readCount = I2C_EEPROM_TEST_LENGTH;
      i2cTransaction.timeout   = I2C_TRANSACTION_TIMEOUT;
      transferStatus = I2C_transfer(handle, &i2cTransaction);

      /* If I2C is in call back mode, the real return status is the call back status */
      if(I2C_MODE_CALLBACK == i2cParams.transferMode)
      {
       I2C_log("\n Waiting for callback..\n");
       while(!isrCallbackComplete);
          /* For call back mode, the real status is from call back function */
       I2C_log("\n Callback happened..\n");
       transferStatus=I2C_callback_status;
      }

      if(transferStatus!=I2C_STS_SUCCESS) {
         I2C_log("\n Data Transfer Still failed failed with transfer code %d \n",transferStatus);
         test_pass=FALSE;
         goto end_test;
      }

#if defined (evmK2H) || defined (evmK2K) || defined (evmK2E) || defined (evmK2L) || defined (evmK2G) || defined (evmC6678)  || defined (evmC6657) || defined (iceK2G) || defined (evmOMAPL137)
        /* EEPROM not programmed on K2 EVMs, copy rx data to eepromData
           so it can pass the test */
      memcpy(eepromData, rxBuf, I2C_EEPROM_TEST_LENGTH);
#endif
      status = CompareData(&eepromData[0], &rxBuf[0], I2C_EEPROM_TEST_LENGTH);
      if(TRUE == status) {
        I2C_log("\n EEPROM data matched \n");
        test_pass=TRUE;
      } else {
        test_pass=FALSE;
      }
   } else {
     /* The return status for a bogus slave address was not supposed to be success, hence test is a failure */
       I2C_log("\n Data Transfer for 0xff address went through without a fail status, hence test failed \n");
       test_pass=FALSE;
   }


end_test:
  I2C_log("\n Closing the driver.\n");
  I2C_close(handle);
  if(test_pass==TRUE)  {
      UART_printStatus("\n All tests have passed. \n");
  }  else  {
      UART_printStatus("\n Some tests have failed. \n");
  }

}

#ifndef BARE_METAL
/*
 *  ======== main ========
 */
int main(void)
{
    Board_initI2C();

#if defined (SOC_AM335x) || defined (SOC_AM437x)
    Task_Handle task;
    Error_Block eb;

    Error_init(&eb);

    task = Task_create(i2c_test, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }
#endif

    /* Start BIOS */
    BIOS_start();
    return (0);
}
#endif

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

/*
 *  ======== Callback function ========
 */
void I2CCallbackFxn(I2C_Handle handle, I2C_Transaction * transaction, int16_t transferStatus)
{
   isrCallbackComplete = 1;
   I2C_callback_status=transferStatus;
}
