/**
 *  \file   emmc_main.c
 *
 *  \brief  Test application main file. The test application demonstrates
 *          raw data write & read on a MMCSD device.
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


/* TI-RTOS Header files */
#include <ti/csl/cslr_device.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* GPIO Header files */
#if (!(defined(SOC_AM65XX) || defined(SOC_J721E)))
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#endif
#if (defined(am65xx_evm) || defined(am65xx_idk))
#include "board_i2c_io_exp.h"
#endif
#include "board.h"
#include "board_cfg.h"

#if (defined(SOC_K2G) || defined(SOC_AM65XX) || defined(SOC_J721E))
#include "diag_common_cfg.h"
#endif

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/

/* Global data pointers */
#define MMCSTARTSECTOR                  (0x300000U) //@1.5GB //100

#if defined(DIAG_COMPLIANCE_TEST)
#define MMCTESTSECTORS 					(0x1U)
#else
#define MMCTESTSECTORS 					(0x20U) //0x800 //0x5000  //10MB //512
#endif

#define DATA_PATTERN_00                 0
#define DATA_PATTERN_FF                 1
#define SDMMC_DATA_PATTERN_AA           2
#define SDMMC_DATA_PATTERN_55           3
#define SDMMC_DATA_PATTERN_AA_55		4
#define SDMMC_DATA_PATTERN_INC          8

#define SECTORSIZE                      (512U)
#ifdef DIAG_STRESS_TEST
#define TESTSECTORS    					(512U) //16 //1
#else
#define TESTSECTORS    					(1U) //16 //1
#endif

#if defined(SOC_AM65XX)
#define MAX_NUM_OF_MMCSD_SUPPORT_MODES  (4U)
uint32_t emmcSupportModes[MAX_NUM_OF_MMCSD_SUPPORT_MODES] = {MMCSD_SUPPORT_MMC_HS200, MMCSD_SUPPORT_MMC_HS_DDR, MMCSD_SUPPORT_MMC_HS_SDR, MMCSD_SUPPORT_MMC_DS};
#elif defined(SOC_J721E)
#define MAX_NUM_OF_MMCSD_SUPPORT_MODES  (5U)
uint32_t emmcSupportModes[MAX_NUM_OF_MMCSD_SUPPORT_MODES] = {MMCSD_SUPPORT_MMC_HS400, MMCSD_SUPPORT_MMC_HS200, MMCSD_SUPPORT_MMC_HS_DDR, MMCSD_SUPPORT_MMC_HS_SDR, MMCSD_SUPPORT_MMC_DS};
#endif

/* GPIO pin value definitions */
#if (!(defined(SOC_AM65XX) || defined(SOC_J721E)))
#define GPIO_PIN_VAL_LOW                (0U)
#define GPIO_PIN_VAL_HIGH               (1U)

/* ON Board LED pins which are connected to GPIO pins. */
typedef enum GPIO_PIN {
    GPIO_PIN_EMMC_RST      = 0U,
    GPIO_PIN_COUNT
}GPIO_PIN;

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Output pin : AM572X EMMC_RST */
    GPIO_DEVICE_CONFIG(GPIO_EMMC_RST_PORT_NUM, GPIO_EMMC_RST_PIN_NUM) | GPIO_CFG_OUTPUT,
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL
};

#ifdef SOC_K2G
GPIO_v0_Config GPIO_v0_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};
#else
/* GPIO Driver configuration structure */
GPIO_v1_Config GPIO_v1_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};
#endif
#endif

/* Enable the below macro to have prints on the IO Console */
//#define IO_CONSOLE

#ifndef IO_CONSOLE
#define MMCSD_log                       UART_printf
#else
#define MMCSD_log                       printf
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */
#if (!(defined(EVM_K2G) || defined(SOC_AM65XX) || defined(SOC_J721E)))
typedef CSL_control_core_pad_ioRegs *CSL_padRegsOvly;
#endif

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

static int8_t HSMMCSDReadWriteTest(MMCSD_Handle handle);

static int8_t fillMmcPageData(uint8_t *buf, int32_t length, uint8_t flag);

static void EmmcsReset(void);

/* Delay function */
static void delay(uint32_t delayValue);

static int8_t runReadWriteTest(uint32_t startSector, uint32_t endSector);

static int8_t BoardDiag_socConfig(void);

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

MMCSD_Handle handle = NULL;
static uint8_t tx[SECTORSIZE * TESTSECTORS];
static uint8_t rx[SECTORSIZE * TESTSECTORS];

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
/**
 *  \brief    The function creates a delay.
 *
 */
static void delay(uint32_t delayValue)
{
    volatile uint32_t delay1 = delayValue*10000;
    while (delay1--);
}

/**
 *  \brief    The function sets the input clock.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t BoardDiag_socConfig(void)
{
#if (defined(SOC_AM571x) || defined(SOC_AM572x) || defined(SOC_AM574x))
    MMCSD_v1_HwAttrs hwAttrsConfig;
    if(MMCSD_socGetInitCfg(1,&hwAttrsConfig)!=0)
    {
        UART_printf ("\nUnable to obtain config.Exiting. TEST FAILED.\r\n");
        return -1;
    }

    /* SBL sets the input clock to 128 Mhz in the CM_L3INIT_MMC2_CLKCTRL */
    hwAttrsConfig.inputClk = 128000000;

    if(MMCSD_socSetInitCfg(1,&hwAttrsConfig)!=0)
    {
        UART_printf ("\nUnable to obtain config.Exiting. TEST FAILED.\r\n");
        return -1;
    }
#endif
    return 0;
}

/**
 *  \brief    The function resets the eMMC device.
 *
 */
static void EmmcsReset(void)
{
#if (!(defined(SOC_AM65XX) || defined(SOC_J721E)))
    /* EMMC reset */
    GPIO_init();
    GPIO_write(GPIO_PIN_EMMC_RST, GPIO_PIN_VAL_LOW);
    delay(100);
    GPIO_write(GPIO_PIN_EMMC_RST, GPIO_PIN_VAL_HIGH);
    delay(100);
#elif defined(SOC_AM65XX)
#if (!defined (__aarch64__))
    /* MCU I2C instance will be active by default for R5 core.
     * Need update HW attrs to enable MAIN I2C instance.
     */
    enableMAINI2C(0, CSL_I2C0_CFG_BASE);
#endif
    Board_i2cIoExpInit();
    /* Setting the pin direction as output */
    Board_i2cIoExpSetPinDirection(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                                  PORTNUM_0,
                                  PIN_NUM_0,
                                  PIN_DIRECTION_OUTPUT);

    /* Pulling the EMMC RST line to low for the reset to happen */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              PORTNUM_0,
                              PIN_NUM_0,
                              GPIO_SIGNAL_LEVEL_LOW);
    BOARD_delay(500U);
    /* Pulling the EMMC RST line to low for the reset to happen */
    Board_i2cIoExpPinLevelSet(BOARD_I2C_IOEXP_DEVICE2_ADDR,
                              PORTNUM_0,
                              PIN_NUM_0,
                              GPIO_SIGNAL_LEVEL_HIGH);
#endif
}

/**
 *  \brief    The function fills the buffer based on the flag.
 *
 *  \param    buf           [IN/OUT]   Buffer pointer to fill the pattern.
 *  \param    length        [IN]       Buffer length to fill data.
 *  \param    flag          [IN]       Flag to specify pattern.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t fillMmcPageData(uint8_t *buf, int32_t length, uint8_t flag)
{
    uint32_t i;
    uint32_t data = 0x00;
    uint8_t incFlag = 0x00;
    uint8_t checkerBoard = 0;

    switch(flag)
    {
        case DATA_PATTERN_00:
            data = 0;
            break;
        case DATA_PATTERN_FF:
            data = 0xFF;
            break;
        case SDMMC_DATA_PATTERN_AA:
            data = 0xAA;
            //MMCSD_log("\nSD Read/Write pattern 0xAA ");
            break;
        case SDMMC_DATA_PATTERN_55:
            data = 0x55;
            //MMCSD_log("\nSD Read/Write pattern 0x55 ");
            break;
		case SDMMC_DATA_PATTERN_AA_55:
            checkerBoard = 1;
            data = 0xAA;
            //MMCSD_log("\nSD Read/Write pattern 0x55 ");
            break;
        case 8:
             data = 0x00;
             incFlag = 0x01;
             //MMCSD_log("\nSD Read/Write incremental data");
             break;
        default:
            return -1;
    }

    for(i = 0; i < length; i++)
    {
        *(buf + i) = data;
        if(incFlag)
            data++;
		if(checkerBoard)
            data = ~data;
    }
    return 0;
}

/**
 *  \brief    The function fills the buffer based on the flag.
 *
 *  \param    startSector   [IN]       Start sector number to test.
 *  \param    endSector     [IN]       Total number of sector to test.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
static int8_t runReadWriteTest(uint32_t startSector, uint32_t endSector)
{
    uint32_t blockNum;
    uint32_t j, testIteration;
    int32_t retVal;
#if defined(DIAG_STRESS_TEST)
    char rdBuf = 'y';
#endif

#if defined(DIAG_COMPLIANCE_TEST)
    testIteration = SDMMC_DATA_PATTERN_AA_55;
#else
    testIteration = SDMMC_DATA_PATTERN_55;
#endif
    for(blockNum = startSector; blockNum < endSector; blockNum += TESTSECTORS)
    {
        fillMmcPageData(&tx[0], (SECTORSIZE * TESTSECTORS), testIteration);

        retVal = MMCSD_write(handle, &tx[0], blockNum, TESTSECTORS);

        if(retVal != MMCSD_OK)
        {
            MMCSD_log("FAIL: Write failed on sector %d", blockNum);
            return -1;
        }

        delay(100);

        /* Clear receive buffer */
        fillMmcPageData(&rx[0], (SECTORSIZE * TESTSECTORS), DATA_PATTERN_00);

        /* Read a page */
        retVal = MMCSD_read(handle, &rx[0], blockNum, TESTSECTORS);

        if(retVal != MMCSD_OK)
        {
            MMCSD_log("FAIL: Read failed on sector %d", blockNum);
            return -1;
        }

        /* Check the pattern */
        for ( j = 0; j < (SECTORSIZE * TESTSECTORS) ; j++)
        {
            /* Compare the data read against the expected */
            if ( tx[j] != rx[j])
            {
                MMCSD_log("FAIL: Data comparison failed @ ");
                MMCSD_log("sector %d", blockNum);
                MMCSD_log(" ,data %d", j);
                MMCSD_log(" ,rx = %x", rx[j]);
                MMCSD_log(" ,tx = %x", tx[j]);
                return -1;
            }
        }
        if(!(blockNum & 0xfff))
        {
            MMCSD_log ("\nPASS: Read/Write Success for this block-0x%x\r\n",
                                                                     blockNum);
        }

#if defined(DIAG_STRESS_TEST)
        /* Check if there a input from console to break the test */
        rdBuf = (char)BoardDiag_getUserInput(BOARD_UART_INSTANCE);
        if((rdBuf == 'b') || (rdBuf == 'B'))
        {
            UART_printf("Received Test Termination... Exiting the Test\n\n");
            UART_printf("EMMC Stress Test Status\n");
            UART_printf("============================================\n");
            UART_printf("PASS: Read/Write Success till the block-0x%x\r\n",blockNum);
            break;
        }
#endif
    }
    return 0;
}
  
/**
 *  \brief    The function performs emmc test.
 *
 *  \param    handle        [IN]       MMCSD handle.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t HSMMCSDReadWriteTest(MMCSD_Handle handle)
{
    int8_t retVal = 0;
#if (defined(DIAG_STRESS_TEST) || defined(SOC_AM65XX) || defined(SOC_J721E))
    /* Media configuration such as eMMC size, blocksize, blockCount */
    uint32_t blockCount;
    MMCSD_mediaParams  mediaParams;
    MMCSD_log("Getting eMMC parameters\n");
    if((retVal = MMCSD_control(handle, MMCSD_CMD_GETMEDIAPARAMS, (void *)&mediaParams)) != MMCSD_OK)
    {
    MMCSD_log("Getting eMMC parameters failed !!");
    return -1;
    }
    blockCount = (unsigned int)(mediaParams.blockCount & 0xFFFFFFFF);
    MMCSD_log("eMMC: BlockCount = 0x%x \n",(unsigned int)(mediaParams.blockCount & 0xFFFFFFFF));
#endif

#if (!defined(DIAG_STRESS_TEST))
    retVal = runReadWriteTest(MMCSTARTSECTOR, MMCSTARTSECTOR + MMCTESTSECTORS);
#else
    retVal = runReadWriteTest(MMCSTARTSECTOR, blockCount);
#endif

#if (!defined(DIAG_STRESS_TEST) && (defined(SOC_AM65XX) || defined(SOC_J721E)))
    /* For boundary verification, verifying last sectors */
    retVal = runReadWriteTest(blockCount - MMCTESTSECTORS - 1, blockCount - 1);
#endif

    if (!retVal)
    {
#if defined(DIAG_STRESS_TEST)
        UART_printf("eMMC Stress Test Passed!\n");
#else
        MMCSD_log ("\nPASS: eMMC Read/Write Success for this pattern\r\n");
#endif
    }

    return 0;
}

/**
 *  \brief   emmc test main function
 *
 *  \return  int - emmc test status.
 *             0 - in case of success
 *            -1 - in case of failure.
 *
 */
int main(void)
{
    Board_STATUS status;
    Board_initCfg boardCfg;
    int8_t retVal;

#ifdef SOC_K2G
    DIAG_IntrInit();
#endif

#if ((defined(SOC_AM65XX) || defined(SOC_J721E)) && (!defined(DIAG_STRESS_TEST)))
    uint8_t index=0;
    MMCSD_v2_HwAttrs           hwAttrsConfig;
#endif

#if defined(SOC_AM65XX) && !defined (__aarch64__)
    /* MCU I2C instance will be active by default for R5 core.
     * Need update HW attrs to enable MAIN I2C instance.
     */
    enableMAINI2C(0, CSL_I2C0_CFG_BASE);
#endif

    boardCfg = BOARD_INIT_UART_STDIO | BOARD_INIT_PINMUX_CONFIG;
    status = Board_init(boardCfg);
    if(status != BOARD_SOK)
    {
        return -1;
    }
#if defined(DIAG_STRESS_TEST)
	UART_printf("\n*********************************************\n");
    UART_printf("*                 eMMC Stress Test            *\n");
    UART_printf("***********************************************\n");
#else
    UART_printf("\n*********************************************\n");
    UART_printf  ("*                 eMMC Test                 *\n");
    UART_printf  ("*********************************************\n");
#endif

    EmmcsReset();

    retVal = BoardDiag_socConfig();
    if(retVal != 0)
    {
        return -1;
    }

    MMCSD_init();

    MMCSD_open(BOARD_MMCSD_EMMC_INSTANCE, NULL, &handle);

    retVal = HSMMCSDReadWriteTest(handle);
    if (retVal)
    {
        UART_printf("eMMC Read/Write test Failed\n");
        return -1;
    }

    MMCSD_close(handle);

#if ((defined(SOC_AM65XX) || defined(SOC_J721E)) && (!defined(DIAG_STRESS_TEST)))
    for(index=0; index<MAX_NUM_OF_MMCSD_SUPPORT_MODES; index++)
    {
        if(MMCSD_socGetInitCfg(BOARD_MMCSD_EMMC_INSTANCE,&hwAttrsConfig)!=0) {
           UART_printf ("\nUnable to obtain MMCSD config.Exiting. TEST FAILED.\r\n");
           return -1;
        }
        hwAttrsConfig.supportedModes = emmcSupportModes[index];
        if(MMCSD_socSetInitCfg(BOARD_MMCSD_EMMC_INSTANCE,&hwAttrsConfig)!=0)
        {
            UART_printf ("\nUnable to set speed: TEST FAILED.\r\n");
            return -1;
        }
        else
        {
            UART_printf("\n\nSetting EMMC Support Mode%d configuration...\n",emmcSupportModes[index]);
        }

        MMCSD_init();

        MMCSD_open(BOARD_MMCSD_EMMC_INSTANCE, NULL, &handle);

        retVal = HSMMCSDReadWriteTest(handle);
        if (retVal)
        {
            UART_printf("\neMMC Read/Write Failed\n");
            return -1;
        }

        MMCSD_close(handle);
    }
#endif

    return retVal;
}

