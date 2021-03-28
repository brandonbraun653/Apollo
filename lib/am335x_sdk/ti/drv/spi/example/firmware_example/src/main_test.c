/**
 *  \file   main_test.c
 *
 *  \brief  Example application main file. This application will read
 *          and write through spi interface by spi loopback enabled.
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

/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/cfg/global.h>
#include <xdc/runtime/System.h>
#include <xdc/runtime/Error.h>
#include <stdio.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <ti/sysbios/knl/Task.h>

/* SPI Header files */
#include <ti/drv/spi/soc/SPI_soc.h>
#include <ti/drv/spi/test/src/SPI_log.h>
#include <ti/drv/spi/test/src/SPI_test.h>

/* Board Header files */
#include <ti/board/board.h>
#include <ti/starterware/include/prcm.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* GPIO Header files */
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#include <ti/osal/HwiP.h>

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/
#ifndef IO_CONSOLE
#define SPI_log                UART_printf
#else
#define SPI_log                printf
#endif

#if defined (SOC_AM335x)
#define ESPI_INSTANCE 2
#elif defined (SOC_AM437x)
#define ESPI_INSTANCE 5
#endif



/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/
extern void UART_printf(const char *pcString, ...);

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

/*
 *  ======== Board_initSPI ========
 */
void Board_initSPI(void)
{
  Board_initCfg boardCfg;

  boardCfg = BOARD_INIT_PLL |
    BOARD_INIT_MODULE_CLOCK |
    BOARD_INIT_DDR |
    BOARD_INIT_ICSS_PINMUX |
    BOARD_INIT_UART_STDIO;


  Board_init(boardCfg);

  PRCMModuleEnable(CHIPDB_MOD_ID_PRU_ICSS, 1U, 0U);
  PRCMModuleEnable(CHIPDB_MOD_ID_UART, 1U, 0U);
}


/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
  0, /* Blank for now, will set in init() */
};
  
/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
  NULL, /* Blank for now, will set in open() */
};
  
/* GPIO Driver configuration structure */
GPIO_v1_Config GPIO_v1_config = {
  gpioPinConfigs,
  gpioCallbackFunctions,
  sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
  sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
  0,
};

/*
 *  ======== test function ========
 */

void espi_test(UArg arg0, UArg arg1)
{
  MCSPI_Params      mcspiParams; /* MCSPI params structure */
  bool            testPassed = true;
  MCSPI_Handle      fwHandle;  /* MCSPI handle */
  SPI_Transaction transaction;     /* SPI transaction structure */
  uint8_t rxBuf[ESPI_PACKET_MAX_SIZE], txBuf[ESPI_PACKET_MAX_SIZE];
  bool            retVal;
  ESPI_SwIPAttrs espi_cfg;

  uint8_t data_len = 0;
  bool txFlag = false;
  bool invalidAddrFlag = false;
  bool errFlag = false;
  int8_t sign = 1; 

  /* Initialize the ESPI fw configuration */
  ESPI_socInitFwCfg();

  /* Get the default ESPI init configurations */
  ESPI_socGetFwCfg(ESPI_INSTANCE, &espi_cfg);

  /* Modify the default ESPI configurations if necessary */

  /* Set the default ESPI init configurations */
  ESPI_socSetFwCfg(ESPI_INSTANCE, &espi_cfg);

  /* Set GPIO pin configurations */
  GPIO_setConfig(ESPI_GPIO_PIN_RESET, GPIO_DEVICE_CONFIG(espi_cfg.resetPin.port,
						    espi_cfg.resetPin.pinNum) |
		 GPIO_CFG_IN_INT_RISING | GPIO_CFG_INPUT);

  /* Initialize GPIO */
  GPIO_init();


  /* Open the Board flash NOR device with the test SPI port
     and use the default SPI configurations */
  MCSPI_Params_init(&mcspiParams);

  /* Init SPI driver */
  MCSPI_init();

  HwiP_enableInterrupt(espi_cfg.intNum);
  fwHandle = (MCSPI_Handle)MCSPI_open(ESPI_INSTANCE, 0, &mcspiParams);

  while (errFlag != true) {
    /* Read ESPI Packet */
    transaction.txBuf = NULL;
    transaction.rxBuf = (uint8_t*) rxBuf;
    transaction.count = ESPI_PACKET_MAX_SIZE;

    retVal = MCSPI_transfer(fwHandle, &transaction);  

    if (retVal == false) {
      testPassed = false;
      goto err;
    }

    /* Prepare TX response */
    transaction.txBuf = (uint8_t*) txBuf;
    transaction.rxBuf = NULL;
    transaction.count = ESPI_PACKET_MAX_SIZE;
    data_len = 0;
    txFlag = false;
    invalidAddrFlag = false;
    sign = 1; 

    /*** PUT_IORD_SHORT ***/
    if (rxBuf[0] == 0x40 || rxBuf[0] == 0x41 || rxBuf[0] == 0x43) {
      data_len = rxBuf[0] - 0x3F;

      SPI_log("\nGOT PUT_IORD_SHORT%d\n", data_len);

      txFlag = true;
      /* Send back dummy data if the address is good */

      if (rxBuf[1] == 0xDE && rxBuf[2] == 0xAD) {	
	/* Expected address */
      } else {
	/* Invalid address */
	SPI_log("Invalid address: %d%d", rxBuf[1],rxBuf[2]);
	invalidAddrFlag = true;
      }

      /*** PUT_IOWR_SHORT ***/
    } else if (rxBuf[0] == 0x44 || rxBuf[0] == 0x45 || rxBuf[0] == 0x47) {
      data_len = rxBuf[0] - 0x43;

      SPI_log("\nGOT PUT_IOWR_SHORT%d\n", data_len);

      /* Expected address */
      if (rxBuf[1] == 0xDE && rxBuf[2] == 0xAD) {
	if (data_len == 1 && rxBuf[3] == 0x1)
	  { /* Good 1B */}
	else if (data_len == 2 &&
		   rxBuf[3] == 0x1 && rxBuf[4] == 0x2 )
	  { /* Good 2B */}
	else if (data_len == 4 &&
		   rxBuf[3] == 0x1 && rxBuf[4] == 0x2 && rxBuf[5] == 0x3 && rxBuf[6] == 0x4 )
	  { /* Good 4B */}
	else {
	  /* Bad */
	  testPassed = false;
	  errFlag = true;
	}

	/* Invalid address */
      } else {
	SPI_log("Invalid address: %d%d", rxBuf[1],rxBuf[2]);
	invalidAddrFlag = true;
      }

      /*** PUT_MEMRD32_SHORT ***/
    } else if (rxBuf[0] == 0x48 || rxBuf[0] == 0x49 || rxBuf[0] == 0x4B) {
      data_len = rxBuf[0] - 0x47;

      SPI_log("\nGOT PUT_MEMRD32_SHORT%d\n", data_len);

      txFlag = true;
      /* Send back dummy data if the address is good */
      if (rxBuf[1] == 0x0D && rxBuf[2] == 0x0E && rxBuf[3] == 0x0A && rxBuf[4] == 0x0D) {
	/* Expected address */
      } else {
	/* Invalid address */
	SPI_log("Invalid address: %d%d%d%d", rxBuf[1],rxBuf[2],rxBuf[3],rxBuf[4]);
	invalidAddrFlag = true;
      }

      /*** PUT_MEMWR32_SHORT ***/
    } else if (rxBuf[0] == 0x4C || rxBuf[0] == 0x4D || rxBuf[0] == 0x4F) {
      data_len = rxBuf[0] - 0x4B;

      SPI_log("\nGOT PUT_MEMWR32_SHORT%d\n", data_len);

      if (rxBuf[1] == 0x0D && rxBuf[2] == 0x0E && rxBuf[3] == 0x0A && rxBuf[4] == 0x0D) {
	/* Expected address */
	if (data_len == 1 && rxBuf[5] == 0x1) {
	  /* Good */
	} else if (data_len == 2 &&
		   rxBuf[5] == 0x1 &&
		   rxBuf[6] == 0x2 ) {
	  /* Good */
	} else if (data_len == 4 &&
		   rxBuf[5] == 0x1 &&
		   rxBuf[6] == 0x2 &&
		   rxBuf[7] == 0x3 &&
		   rxBuf[8] == 0x4 ){
	  /* Good */
	} else {
	  /* Bad */
	  testPassed = false;
	  errFlag = true;
	}
      } else {
	/* Invalid address */
	SPI_log("Invalid address: %d%d%d%d", rxBuf[1],rxBuf[2],rxBuf[3],rxBuf[4]);
	invalidAddrFlag = true;
      }
    } else {
      SPI_log("\nGOT unexpected command: 0x%x\n", rxBuf[0]);
      errFlag = true;
    }

    /* Prepare TX */
    if (txFlag) {
      /* Prepare TX packet */
      txBuf[0] = 0b00001111;	/* Cycle Type */
      txBuf[1] = 0;		/* Tag + Length[11:8] */
      txBuf[2] = data_len;	/* Length[7:0] */
      transaction.count = data_len + 3;
      
      /* Return CMD+n on valid address, CMD-n on invalid address (checking packet integrity) */
      if (invalidAddrFlag) {
	sign = -1;
      }

      if (data_len == 1) {
	txBuf[3] = rxBuf[0] + 1 * sign;
	SPI_log("TX: %d\n", txBuf[0]);
      } else if (data_len == 2) {
	txBuf[3] = rxBuf[0] + 1 * sign;
	txBuf[4] = rxBuf[0] + 2 * sign;
	SPI_log("TX: %d%d\n", txBuf[0], txBuf[1]);
      } else if (data_len == 4) { 
	txBuf[3] = rxBuf[0] + 1 * sign;
	txBuf[4] = rxBuf[0] + 2 * sign;
	txBuf[5] = rxBuf[0] + 3 * sign;
	txBuf[6] = rxBuf[0] + 4 * sign;
	SPI_log("TX: %d%d%d%d\n", txBuf[0], txBuf[1], txBuf[2], txBuf[3]);
      } else {
	/* Shouldn't be possible to get here... */
      }

      /* Put response in TX queue */
      retVal = MCSPI_transfer(fwHandle, &transaction);  
      
      if (retVal == false) {
	testPassed = false;
	errFlag = true;
      }
    } else { /* is a write */
      
    }
  }
	
  MCSPI_close(fwHandle);



 err:
  if(true == testPassed)
    {
      SPI_log("\n All tests have passed. \n");
    }
  else
    {
      SPI_log("\n Some tests have failed. \n");
    }
	
  while(1);
}

/*
 *  ======== main ========
 */
int main(void)
{
  Task_Handle       task;
  Error_Block       eb;
  Task_Params       taskParams;

  Error_init(&eb);
  Board_initSPI();

  Task_Params_init(&taskParams);
  taskParams.instance->name = "espiTest1";
  task = Task_create(espi_test, &taskParams, &eb);
  if (task == NULL) {
    System_printf("Task_create() failed!\n");
    BIOS_exit(0);
  }

  /* Start BIOS */
  BIOS_start();
  return (0);
}

