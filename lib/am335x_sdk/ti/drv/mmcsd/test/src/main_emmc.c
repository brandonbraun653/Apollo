/**
 *  \file   main.c
 *
 *  \brief  Test application main file. The test application demonstrates
 *          raw data write & read on a MMCSD device.
 *
 */

/*
 * Copyright (C) 2014-2017 Texas Instruments Incorporated - http://www.ti.com/
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
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <string.h>
#include <ti/sysbios/knl/Task.h>
/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#include <xdc/runtime/Error.h>
#if defined (__aarch64__)
#include <ti/sysbios/family/arm/v8a/Mmu.h>
#endif

#else

#include <ti/csl/soc.h>
#include <ti/csl/csl_timer.h>
#include <ti/csl/arch/csl_arch.h>

#endif

#include <ti/osal/osal.h>
#ifdef MMCSD_EDMA_ENABLED
#include <ti/sdo/edma3/drv/edma3_drv.h>
#include <ti/sdo/edma3/rm/edma3_rm.h>
#include <ti/sdo/edma3/drv/sample/bios6_edma3_drv_sample.h>
#define MMCSD_DMA_ENABLED 1
#endif
#ifdef MMCSD_ADMA_ENABLED
#define MMCSD_DMA_ENABLED 1
#endif

/* TI-RTOS Header files */
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_chip.h>
#include "MMCSD_log.h"
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/src/MMCSD_osal.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

#include <ti/board/board.h>

/* Example/Board Header files */
#if defined (evmAM437x)
#include <ti/starterware/include/hw/am437x.h>
#include <ti/starterware/board/am43xx/am43xx_pinmux.h>
#endif


#if !defined(SOC_AM65XX) && !defined(SOC_J721E) && !defined(SOC_J7200)
#define GPIO_ENABLED 1
#endif

#ifdef GPIO_ENABLED
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>
#endif

#include "profiling.h"

#if defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
#include <ti/csl/src/ip/intr_router/V0/csl_intr_router.h>
#endif
/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/

/* Global data pointers */
#define HSMMCSD_DATA_SIZE               512

#define PAGE_OFFSET   0x0
#if defined (SOC_OMAPL137)
/* MMC card is used for testing the example on OMAPL137.
 * Setting the start sector to 8MB offset on OMAPL137 to support small size MMC cards. */
#define MMCSTARTSECTOR  0x4000  //@8MB
#else
#ifdef SIMULATOR
#define MMCSTARTSECTOR  0x4000 //@8MB for VLAB
#else
#define MMCSTARTSECTOR  0x300000 //@1.5GB //100
#endif
#endif

#define DATA_PATTERN_00     0
#define DATA_PATTERN_FF     1
#define SDMMC_DATA_PATTERN_AA 2
#define SDMMC_DATA_PATTERN_55 3
#define SDMMC_DATA_PATTERN_RAMP32 4
#define SDMMC_DATA_PATTERN_INC  8

#define SECTORSIZE    (512) /* Size of a block */
#ifndef BARE_METAL
#define MMCSD_TEST_NUM_SIZES (5U) /* 0.25 MB, 0.5 MB, 1 MB , 2MB , 5MB*/
uint32_t mmcsd_test_sizes[MMCSD_TEST_NUM_SIZES]={(1024*256),(1024*512),(1024*1024),(1024*1024*2),(1024*1024*5)};
#else
#define MMCSD_TEST_NUM_SIZES (1U) /* 32K */
uint32_t mmcsd_test_sizes[MMCSD_TEST_NUM_SIZES]={(1024*32)};
#endif

#if defined (SOC_OMAPL137) || defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
#define MMCSD_INSTANCE_EMMC    (0U)
#else
#define MMCSD_INSTANCE_EMMC    (1U)
#endif


#ifdef GPIO_ENABLED
/* GPIO pin value definitions */
#define GPIO_PIN_VAL_LOW     (0U)
#define GPIO_PIN_VAL_HIGH    (1U)

#define GPIO_MUX_SEL 4

#endif

#ifdef MMCSD_EDMA_ENABLED
#if defined(SOC_K2G)
/* MMCSD is connected to EDMA_1 for K2G */
#define MMCSD_EDMACC_NUM 1
#else
#define MMCSD_EDMACC_NUM 0
#endif
#endif


#ifdef GPIO_ENABLED

#if !defined(SOC_OMAPL137)
/* ON Board LED pins which are connected to GPIO pins. */
typedef enum GPIO_PIN {
    GPIO_PIN_EMMC_RST      = 0U,
    GPIO_PIN_COUNT
}GPIO_PIN;

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Output pin : EMMC_RST */
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
GPIO_v1_Config GPIO_v1_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
};
#endif

#endif
#endif

/* ========================================================================== */
/*                         Structures and Enums                               */
/* ========================================================================== */

#if !defined(SOC_AM65XX) && !defined(SOC_J721E) && !defined(SOC_J7200)
typedef CSL_control_core_pad_ioRegs *CSL_padRegsOvly;
#endif

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/

static int32_t fillMmcPageData(uint8_t *buf, int32_t length, uint8_t flag,uint32_t *rampBase);


#if !defined(SOC_AM65XX) && !defined(SOC_J721E) && !defined(SOC_J7200)
static void EmmcsReset(void);
/* Delay function */
#endif

#if !defined(SOC_OMAPL137) && defined(GPIO_ENABLED)
static void delay(unsigned int delayValue);
#endif

/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

MMCSD_Handle handle = NULL;
#define DATA_BUF_ALIGN               (256)

#ifndef BARE_METAL
#define MMCSD_TEST_MAX_BUFSIZE       (5*1024*1024)
#else
#define MMCSD_TEST_MAX_BUFSIZE       (32*1024)
#endif

uint8_t tx[MMCSD_TEST_MAX_BUFSIZE] __attribute__((aligned(DATA_BUF_ALIGN))) __attribute__((section (".benchmark_buffer")));
uint8_t rx[MMCSD_TEST_MAX_BUFSIZE] __attribute__((aligned(DATA_BUF_ALIGN))) __attribute__((section (".benchmark_buffer")));

#if (defined(_TMS320C6X) || defined (__TI_ARM_V7M4__))
#pragma DATA_ALIGN(tx, DATA_BUF_ALIGN)
#pragma DATA_ALIGN(rx, DATA_BUF_ALIGN)
#endif
#ifndef BARE_METAL

#if (defined(SOC_J721E) || defined(SOC_J7200)) && (defined(BUILD_MPU) || defined (__C7100__))
extern void Osal_initMmuDefault(void);
void InitMmu(void)
{
    Osal_initMmuDefault();
}
#elif defined(SOC_AM65XX) && defined (BUILD_MPU)
volatile int emuwait_mmu=1;
Void InitMmu()
{
    bool ret= false;
    Mmu_MapAttrs attrs;

    Mmu_initMapAttrs(&attrs);

   /* TODO: Check if the return value is non zero, then raise error and exit TODO!!!!!*/
    attrs.attrIndx = 0;


    ret=Mmu_map(0x0100000, 0x0100000, 0x00900000, &attrs); /* PLL_MMR_CFG registers regs       */

    if(ret==false) {
		goto mmu_exit;
	}

	/* GTC registers */
	ret=Mmu_map(0x0A80000, 0x0A80000, 0x00080000, &attrs); /* GTC registers       */

    if(ret==false) {
		goto mmu_exit;
	}
	    /* MCU_CTRL_MMR */
	 ret = Mmu_map(0x40f00000ul, 0x40f00000ul, 0x00020000ul, &attrs);
     if (ret == FALSE)
    {
         goto mmu_exit;
    }

	    /* PSC WKUP*/

     ret = Mmu_map(0x42000000ul, 0x42000000ul, 0x00001000ul, &attrs);
     if (ret == FALSE)
    {
         goto mmu_exit;
    }
   /* WKUP_CTRL_MMR */
     ret = Mmu_map(0x43000000ul, 0x43000000ul, 0x00020000ul, &attrs);
     if (ret == FALSE)
    {
         goto mmu_exit;
    }

    ret = Mmu_map(0x00400000, 0x00400000, 0x00001000, &attrs); /* PSC0          */
    if(ret == FALSE)
    {
        goto mmu_exit;
    }

#if defined(SOC_J721E) || defined(SOC_J7200)
    ret=Mmu_map(0x01800000, 0x01800000, 0x00200000, &attrs); /* gicv3       */

    if(ret==false) {
		goto mmu_exit;
	}

	/* SCICLIENT UDMA */
	ret = Mmu_map(0x20000000ul, 0x20000000ul, 0x10000000ul, &attrs);
    if (ret == false)
    {
         goto mmu_exit;
    }
#else
    ret=Mmu_map(0x01800000, 0x01800000, 0x00100000, &attrs); /* gicv3       */

    if(ret==false) {
		goto mmu_exit;
	}
#endif

    ret=Mmu_map(0x02400000, 0x02400000, 0x000c0000, &attrs); /* dmtimer     */

    if(ret==false) {

		goto mmu_exit;
	}

    ret=Mmu_map(0x02800000, 0x02800000, 0x00001000, &attrs); /* uart        */

    if(ret==false) {
		goto mmu_exit;
	}

    ret=Mmu_map(0x2A430000, 0x2A430000, 0x00001000, &attrs); /* ctrcontrol0 */

     if(ret==false) {

		goto mmu_exit;
	}

    ret=Mmu_map(0x02B00000, 0x02B00000, 0x00030000, &attrs); /* uart        */

    if(ret==false) {

		goto mmu_exit;
	}

    ret=Mmu_map(0x02C40000, 0x02C40000, 0x00100000, &attrs); /* pinmux ctrl  */

    if(ret==false) {

		goto mmu_exit;
	}


   ret=Mmu_map(0x030800000, 0x030800000, 0xC000000, &attrs); /* navss        */

    if(ret==false) {

		goto mmu_exit;
	}

   ret=Mmu_map(0x04F80000, 0x04F80000, 0x80000, &attrs); /* mmcsd        */

    if(ret==false) {

		goto mmu_exit;
	}


    attrs.attrIndx = 7;

    ret=Mmu_map(0x70000000, 0x70000000, 0x00200000, &attrs); /* msmc        */
     if(ret==false) {

		goto mmu_exit;
	}

    ret=Mmu_map(0x80000000, 0x80000000, 0x080000000, &attrs); /* ddr        */

    if(ret==false) {

		goto mmu_exit;
	}



mmu_exit:
    if(ret==false) {
		 System_printf("Mmu_map returned error %d",ret);
		 while(emuwait_mmu);
	 }

    return;
}

#endif
#endif

Uint32 readWriteTestFlag = 0;
/*
 *  ======== Board specific GPIO init ========
 */
#ifdef GPIO_ENABLED
 void board_initGPIO(void)
{

#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2E) || defined(SOC_K2L) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657)
    GPIO_v0_HwAttrs gpio_cfg;

    /* Get the default SPI init configurations */
    GPIO_socGetInitCfg(GPIO_EMMC_RST_PORT_NUM, &gpio_cfg);

    /* Modify the default GPIO configurations if necessary */

    /* Set the default GPIO init configurations */
    GPIO_socSetInitCfg(GPIO_EMMC_RST_PIN_NUM, &gpio_cfg);

#if defined(SOC_K2G)
    /* Setup GPIO interrupt configurations */
    GPIO_socSetIntMux(GPIO_EMMC_RST_PORT_NUM, GPIO_EMMC_RST_PIN_NUM, NULL, GPIO_MUX_SEL);
#endif
#endif

}
#endif

#ifdef evmAM437x

 void pinmux_emmc_AM437x(void)
{
  *((volatile unsigned int *)(SOC_CONTROL_MODULE_REG + PIN_GPMC_AD0))=(PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(1)); /* gpmc_ad0.mmc1_dat0 */
  *((volatile unsigned int *)(SOC_CONTROL_MODULE_REG + PIN_GPMC_AD1))=(PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(1)); /* gpmc_ad1.mmc1_dat1 */
  *((volatile unsigned int *)(SOC_CONTROL_MODULE_REG + PIN_GPMC_AD2))=(PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(1)); /* gpmc_ad2.mmc1_dat2 */
  *((volatile unsigned int *)(SOC_CONTROL_MODULE_REG + PIN_GPMC_AD3))=(PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(1)); /* gpmc_ad3.mmc1_dat3 */
  *((volatile unsigned int *)(SOC_CONTROL_MODULE_REG + PIN_GPMC_AD4))=(PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(1)); /* gpmc_ad4.mmc1_dat4 */
  *((volatile unsigned int *)(SOC_CONTROL_MODULE_REG + PIN_GPMC_AD5))=(PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(1)); /* gpmc_ad5.mmc1_dat5 */
  *((volatile unsigned int *)(SOC_CONTROL_MODULE_REG + PIN_GPMC_AD6))=(PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(1)); /* gpmc_ad6.mmc1_dat6 */
  *((volatile unsigned int *)(SOC_CONTROL_MODULE_REG + PIN_GPMC_AD7))=(PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(1)); /* gpmc_ad6.mmc1_dat7 */
  *((volatile unsigned int *)(SOC_CONTROL_MODULE_REG + PIN_GPMC_CSN1))=(PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(2)); /* gpmc_csn1.mmc1_clk  */
  *((volatile unsigned int *)(SOC_CONTROL_MODULE_REG + PIN_GPMC_CSN2))=(PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(2)); /* gpmc_csn2.mmc1_cmd  */
}
#endif

typedef enum {
   MMCSD_REGRESSION_INTRMODE_TEST,
   MMCSD_REGRESSION_POLLINGMODE_TEST,
   MMCSD_REGRESSION_EMMC_DS_1BIT_TEST,
   MMCSD_REGRESSION_EMMC_DS_4BIT_TEST,
   MMCSD_REGRESSION_EMMC_DS_8BIT_TEST,
   MMCSD_REGRESSION_EMMC_HS_SDR_TEST,
   MMCSD_REGRESSION_EMMC_HS_DDR_TEST,
   MMCSD_REGRESSION_EMMC_HS200_TEST,
   MMCSD_REGRESSION_EMMC_HS400_TEST,
   MMCSD_REGRESSION_DEFAULT_TEST,
   MMCSD_REGRESSION_DEFAULT_1BIT_TEST,
   MMCSD_REGRESSION_DEFAULT_4BIT_TEST,
   MMCSD_REGRESSION_TEST_MAX,
   MMCSD_REGRESSION_ALL_NON_POWERCYCLE_TESTS= -1,
   MMCSD_REGRESSION_TEST_EXIT = -2,
} mmcsdMMCTestIDs_e;


typedef struct {
  /* Test Details */
  mmcsdMMCTestIDs_e testID;
  char testDescription[50];
  bool powerCycleRequired; /* if the test needs power cycle before/after the test */
  /* Device Config details */
  MMCSD_SupportedMMCModes_e mode;
  MMCSD_BusVoltage_e  busVoltage;
  uint32_t busWidth; /* MMCSD_BUS_WIDTH_1BIT/4BIT/8BIT */
  uint32_t  intr;
  mmcsdTestBenchmarks_t *benchmarks;
} mmcsdTestMMCProfile_t;

mmcsdTestBenchmarks_t EMMCProfiles_DS_1BIT_benchmarks;
mmcsdTestMMCProfile_t EMMCProfiles_DS_1BIT = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_EMMC_DS_1BIT_TEST,  /* testID */
	                                        "DS Mode 1-bit Test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedMMCModes_e)MMCSD_SUPPORT_MMC_DS, /* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_1_8V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_1BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
                                            &EMMCProfiles_DS_1BIT_benchmarks
										   };

mmcsdTestBenchmarks_t EMMCProfiles_DS_4BIT_benchmarks;
mmcsdTestMMCProfile_t EMMCProfiles_DS_4BIT = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_EMMC_DS_4BIT_TEST,  /* testID */
	                                        "DS Mode 4-bit Test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedMMCModes_e)MMCSD_SUPPORT_MMC_DS, /* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_1_8V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_4BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
                                            &EMMCProfiles_DS_4BIT_benchmarks
										   };


mmcsdTestBenchmarks_t EMMCProfiles_DS_8BIT_benchmarks;
mmcsdTestMMCProfile_t EMMCProfiles_DS_8BIT = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_EMMC_DS_8BIT_TEST,  /* testID */
	                                        "DS Mode 8-bit Test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedMMCModes_e)MMCSD_SUPPORT_MMC_DS, /* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_1_8V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_8BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
                                            &EMMCProfiles_DS_8BIT_benchmarks
										   };

mmcsdTestBenchmarks_t EMMCProfiles_HS_SDR_benchmarks;
mmcsdTestMMCProfile_t EMMCProfiles_HS_SDR = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_EMMC_HS_SDR_TEST,  /* testID */
	                                        "HS-SDR Mode Test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedMMCModes_e)MMCSD_SUPPORT_MMC_HS_SDR ,/* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_1_8V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_8BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
                                            &EMMCProfiles_HS_SDR_benchmarks
										   };

mmcsdTestBenchmarks_t EMMCProfiles_HS_DDR_benchmarks;
mmcsdTestMMCProfile_t EMMCProfiles_HS_DDR = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_EMMC_HS_DDR_TEST,  /* testID */
	                                        "HS-DDR Mode Test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedMMCModes_e)MMCSD_SUPPORT_MMC_HS_DDR, /* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_1_8V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_8BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
                                            &EMMCProfiles_HS_DDR_benchmarks
										   };

mmcsdTestBenchmarks_t EMMCProfiles_HS200_benchmarks;
mmcsdTestMMCProfile_t EMMCProfiles_HS200 = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_EMMC_HS200_TEST,  /* testID */
	                                        "HS200 Mode Test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedMMCModes_e)MMCSD_SUPPORT_MMC_HS200, /* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_1_8V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_8BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
                                            &EMMCProfiles_HS200_benchmarks
										   };
mmcsdTestBenchmarks_t EMMCProfiles_HS400_benchmarks;
mmcsdTestMMCProfile_t EMMCProfiles_HS400 = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_EMMC_HS400_TEST,  /* testID */
	                                        "HS400 Mode Test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedMMCModes_e)MMCSD_SUPPORT_MMC_HS400, /* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_1_8V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_8BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
                                            &EMMCProfiles_HS400_benchmarks
										   };


mmcsdTestBenchmarks_t EMMCProfiles_Default_benchmarks;
/* Default test profile which runs at the default configuration allowed in MMCSD_soc.c */
mmcsdTestMMCProfile_t EMMCProfiles_Default = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_DEFAULT_TEST,  /* testID */
	                                        "Default Unit Test (Max speed)",  /* testDescription */
	                                        TRUE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedMMCModes_e)MMCSD_SUPPORT_MMC_ALL, /* mode */
	                                       (MMCSD_BusVoltage_e)(MMCSD_BUS_VOLTAGE_3_3V | MMCSD_BUS_VOLTAGE_1_8V), /* bus Voltage */
	                                       (MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_4BIT | MMCSD_BUS_WIDTH_8BIT), /* busWidth */
	                                        0, /* Interrupt Enabled/Disabled */
                                            &EMMCProfiles_Default_benchmarks
										   };
#if defined (SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM437x) || defined(SOC_AM335x)
mmcsdTestBenchmarks_t EMMCProfiles_Default_1bit_benchmarks;
mmcsdTestMMCProfile_t EMMCProfiles_Default_1bit = {
                                            /*** Test Config details ***/
                                            MMCSD_REGRESSION_DEFAULT_1BIT_TEST,  /* testID */
                                            "1bit Unit Test (Max speed)",  /* testDescription */
                                            TRUE, /* powerCycleRequired */
                                            /*** Device config details ***/
                                           (MMCSD_SupportedMMCModes_e)MMCSD_SUPPORT_MMC_ALL, /* mode */
                                           (MMCSD_BusVoltage_e)(MMCSD_BUS_VOLTAGE_3_3V | MMCSD_BUS_VOLTAGE_1_8V), /* bus Voltage */
                                           (MMCSD_BUS_WIDTH_1BIT), /* busWidth */
                                            0, /* Interrupt Enabled/Disabled */
                                            &EMMCProfiles_Default_1bit_benchmarks
                                           };


mmcsdTestBenchmarks_t EMMCProfiles_Default_4bit_benchmarks;
mmcsdTestMMCProfile_t EMMCProfiles_Default_4bit = {
                                            /*** Test Config details ***/
                                            MMCSD_REGRESSION_DEFAULT_4BIT_TEST,  /* testID */
                                            "4bit Unit Test (Max speed)",  /* testDescription */
                                            TRUE, /* powerCycleRequired */
                                            /*** Device config details ***/
                                           (MMCSD_SupportedMMCModes_e)MMCSD_SUPPORT_MMC_ALL, /* mode */
                                           (MMCSD_BusVoltage_e)(MMCSD_BUS_VOLTAGE_3_3V | MMCSD_BUS_VOLTAGE_1_8V), /* bus Voltage */
                                           (MMCSD_BUS_WIDTH_4BIT), /* busWidth */
                                            0, /* Interrupt Enabled/Disabled */
                                            &EMMCProfiles_Default_4bit_benchmarks
                                           };


#endif
mmcsdTestMMCProfile_t EMMCProfiles_All_NonPowerCycleTests = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_ALL_NON_POWERCYCLE_TESTS,  /* testID */
	                                        " All non powercycle tests",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedMMCModes_e)0, /*  mode: Irrelevant. */
	                                       (MMCSD_BusVoltage_e)0, /* bus Voltage. Irrelevant. */
	                                        0, /* busWidth. Irrelevant. */
	                                        0, /* Interrupt Enabled/Disabled .Irrelevant. */
                                            NULL
										   };


mmcsdTestMMCProfile_t EMMCProfiles_Exit = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_TEST_EXIT,  /* testID */
	                                        " Exit the regression test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedMMCModes_e)-1, /* mode */
	                                       (MMCSD_BusVoltage_e)-1, /* bus Voltage */
	                                        0, /* busWidth */
	                                        0, /* Interrupt Enabled/Disabled */
                                            NULL

										   };
mmcsdTestMMCProfile_t * mmcsdTestProfiles[] = {
#ifdef MMCSD_REGRESSION_TEST
	&EMMCProfiles_DS_1BIT,
	&EMMCProfiles_DS_4BIT,
	&EMMCProfiles_DS_8BIT,
	&EMMCProfiles_HS_SDR,
	&EMMCProfiles_HS_DDR,
	&EMMCProfiles_HS200,
#if !defined(SOC_AM65XX)
    /* HS400 mode for AM65x has been descoped for AM65x */
	&EMMCProfiles_HS400,
#endif
    &EMMCProfiles_Default,
    &EMMCProfiles_All_NonPowerCycleTests,
    &EMMCProfiles_Exit,
#else
    &EMMCProfiles_Default,
#if defined (SOC_AM572x) || defined(SOC_AM571x) || defined(SOC_AM437x) || defined(SOC_AM335x)
    /* EMMC 4 bit is supported for non OMAP devices */
    &EMMCProfiles_Default_1bit,
    &EMMCProfiles_Default_4bit,
#endif
    &EMMCProfiles_Exit,
#endif
	NULL,
};

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
static int32_t HSMMCSDReadWriteTest_RAW(mmcsdTestMMCProfile_t *testProfilePtr);

/******************************************************************************************/
/* Displays a test profile */
/******************************************************************************************/
void display_testProfile(mmcsdTestMMCProfile_t *testProfilePtr)
{
   	char modeString[50]={"SOC Default"};
   	char busVoltageString[50]={"SOC Default"};
   	char busWidthString[50]={"SOC Default"};
   	char intrString[50]={"SOC Default"};
   	char powerCycleRequiredString[50];

   	if(testProfilePtr->testID!=MMCSD_REGRESSION_DEFAULT_TEST)
   	{
   	switch(testProfilePtr->mode)
   	{
  	   case MMCSD_SUPPORT_MMC_DS:
	     snprintf(modeString, sizeof(modeString),"%s","DS");
		 break;
	  case MMCSD_SUPPORT_MMC_HS_SDR:
  	     snprintf(modeString, sizeof(modeString),"%s","HS-SDR");
  	     break;

	  case MMCSD_SUPPORT_MMC_HS_DDR:
  	     snprintf(modeString, sizeof(modeString),"%s","HS-DDR");
  	     break;

	  case MMCSD_SUPPORT_MMC_HS200:
  	     snprintf(modeString, sizeof(modeString),"%s","HS200");
  	     break;

	  case MMCSD_SUPPORT_MMC_HS400:
  	     snprintf(modeString, sizeof(modeString),"%s","HS400");
  	     break;

	  case MMCSD_SUPPORT_MMC_ALL:
   	      snprintf(modeString, sizeof(modeString),"%s","MMCSD_SUPPORT_MMC_ALL (Default)");
   	      break;
      default:
          break;

	}

	switch((int)testProfilePtr->busVoltage)
   	{
  	   case MMCSD_BUS_VOLTAGE_3_3V:
		  snprintf(busVoltageString, sizeof(busVoltageString),"%s","3.3V");
		  break;
	   case MMCSD_BUS_VOLTAGE_1_8V:
   	      snprintf(busVoltageString, sizeof(busVoltageString),"%s","1.8V");
		  break;
	   case (MMCSD_BUS_VOLTAGE_1_8V | MMCSD_BUS_VOLTAGE_3_3V):
   	      snprintf(busVoltageString, sizeof(busVoltageString),"%s","Default");
		  break;
       default:
          break;

	}

	switch(testProfilePtr->busWidth)
   	{
  	   case MMCSD_BUS_WIDTH_1BIT:
		  snprintf(busWidthString, sizeof(busWidthString),"%s","1-bit");
		  break;
	   case MMCSD_BUS_WIDTH_4BIT:
   	      snprintf(busWidthString, sizeof(busWidthString),"%s","4-bit");
		  break;
	   case MMCSD_BUS_WIDTH_8BIT:
   	      snprintf(busWidthString, sizeof(busWidthString),"%s","8-bit");
		  break;
	   case (MMCSD_BUS_WIDTH_4BIT | MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_8BIT):
   	      snprintf(busWidthString, sizeof(busWidthString),"%s","Default (1-bit & 4-bit & 8-bit)");
		  break;
       default:
          break;

	}

	switch(testProfilePtr->intr)
   	{
  	   case 0:
		  snprintf(intrString, sizeof(intrString),"%s","Disabled (Polling)");
		  break;
	   case 1:
   	      snprintf(intrString, sizeof(intrString),"%s","Enabled (Interrupt)");
		  break;
       default:
          break;

	  }
	}

	switch((int)testProfilePtr->powerCycleRequired)
   	{
  	   case 0:
		  snprintf(powerCycleRequiredString, sizeof(powerCycleRequiredString),"%s","Not required");
		  break;
	   case 1:
   	      snprintf(powerCycleRequiredString, sizeof(powerCycleRequiredString),"%s","Required");
		  break;
       default:
          break;
	}

   MMCSD_log ("\n-----------------------------------------------------------\n");
   MMCSD_log ("Test Details for test ID      = %d \n",testProfilePtr->testID);
   MMCSD_log ("Test Profile[%d]: Description = %s\n",testProfilePtr->testID,testProfilePtr->testDescription);
   MMCSD_log ("Test Profile[%d]: PowerCyle   = %s\n",testProfilePtr->testID,powerCycleRequiredString);

   if((testProfilePtr->testID >=0) && (testProfilePtr->testID < MMCSD_REGRESSION_TEST_MAX))
   {
      MMCSD_log ("Test Profile[%d] Device Config : Mode        = %s\n",testProfilePtr->testID,modeString);
      MMCSD_log ("Test Profile[%d] Device Config : BusVoltage  = %s\n",testProfilePtr->testID,busVoltageString);
      MMCSD_log ("Test Profile[%d] Device Config : BusWidth    = %s\n",testProfilePtr->testID,busWidthString);
      MMCSD_log ("Test Profile[%d] Device Config : Interrupt   = %s\n",testProfilePtr->testID,intrString);
      MMCSD_log ("------------------------------------------------------------\n");
   }

}
/******************************************************************************************/
/* Displays a Regression Test menu */
/******************************************************************************************/

int32_t mmcsd_regression_seek_testID()
{
   mmcsdTestMMCProfile_t *testProfilePtr;
   uint32_t testprofile;
   bool validInput=FALSE;
   int32_t			selection;


   char Response[10];

  do
  {
   MMCSD_log ("\n\n\n\n\n\n");
   MMCSD_log ("MMCSD Regression Test Menu\n");
   MMCSD_log ("--------------------------\n");

   MMCSD_log (" Test ID:   Description    Powercycle Required?\n");

     /* Display the menu*/
     for(testprofile=0;testprofile<sizeof(mmcsdTestProfiles)/sizeof(mmcsdTestMMCProfile_t *);testprofile++)
     {
        testProfilePtr = mmcsdTestProfiles[testprofile];

        if(testProfilePtr==NULL)
        {  /* End of test profiles */
	      break;
	    }
        MMCSD_log ("%5d         %20s           %4s \n",testProfilePtr->testID,testProfilePtr->testDescription,((testProfilePtr->powerCycleRequired==TRUE)?"Yes":"No"));
	 }

    MMCSD_log ("\n\n");
    MMCSD_log ("Please enter a test ID from the above list: ");


#ifdef IO_CONSOLE
	 scanf("%s",Response);
#else
	 UART_scanFmt("%s", Response);
#endif
	 selection = atoi(Response);

      if(selection >= 0  && selection <MMCSD_REGRESSION_TEST_MAX) {
		 validInput=TRUE;
	  } else {

         if( !((selection == MMCSD_REGRESSION_ALL_NON_POWERCYCLE_TESTS) ||
             (selection == MMCSD_REGRESSION_TEST_EXIT)) ) {
             MMCSD_log ("Invalid selection: %d !! Please enter a valid test ID from the table!!!\n", selection);
         } else {
		   validInput=TRUE;
		 }
	  }

  } while(validInput==FALSE);

  return(selection);
}


#if defined (SOC_OMAPL137)
MMCSD_v0_HwAttrs           hwAttrsConfigDefault;
#elif defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
MMCSD_v2_HwAttrs           hwAttrsConfigDefault;
#else
MMCSD_v1_HwAttrs hwAttrsConfigDefault;
#endif
uint32_t hwAttrsConfigDefaultSaved=0;
/*
 *  ======== test function ========
 */
#ifdef BARE_METAL
void mmcsd_test()
#else
void mmcsd_test(UArg arg0, UArg arg1)
#endif
{
    MMCSD_Error ret;
	uint32_t testprofile;
	mmcsdTestMMCProfile_t *testProfilePtr;
	int32_t testID=0; /* Default */
    uint32_t num_tests_passed=0,num_tests_run=0;
#ifndef MMCSD_REGRESSION_TEST
    uint32_t defaults_test_index=0;
#endif

#if defined (SOC_OMAPL137)
    MMCSD_v0_HwAttrs           hwAttrsConfig;
#elif defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
    MMCSD_v2_HwAttrs           hwAttrsConfig;
#else
    MMCSD_v1_HwAttrs hwAttrsConfig;
#endif

#ifdef MMCSD_EDMA_ENABLED
    EDMA3_DRV_Result edmaResult = 0;
    EDMA3_RM_Handle gEdmaHandle = NULL;
    gEdmaHandle = (EDMA3_RM_Handle)edma3init(MMCSD_EDMACC_NUM, &edmaResult);
#endif

#ifdef MEASURE_TIME
	 profile_init();
#endif

  while(testID!=MMCSD_REGRESSION_TEST_EXIT)
  {

#ifdef MMCSD_REGRESSION_TEST
     /* Display the menu & find out the testID */
      testID = mmcsd_regression_seek_testID();
      MMCSD_log (" Test ID Entered = %d\n",testID);
#else
      testProfilePtr= mmcsdTestProfiles[defaults_test_index];
       /* No Menu required in case of the default unit test. */
      testID = testProfilePtr->testID;
      /* Fetch the next test profile */
      defaults_test_index++;

#endif

      if(testID==MMCSD_REGRESSION_TEST_EXIT) {
         break;
      }

   /* Valid test ID entered. Now search for the test containing the testID in the list of test profiles */

   for(testprofile=0;testprofile<sizeof(mmcsdTestProfiles)/sizeof(mmcsdTestMMCProfile_t *);testprofile++)
   {
     testProfilePtr = mmcsdTestProfiles[testprofile];

     if(testProfilePtr==NULL) {
		MMCSD_log("\nEnd of test profiles");
		break;
	 }

	 if((testProfilePtr->testID == MMCSD_REGRESSION_ALL_NON_POWERCYCLE_TESTS) ||
	     (testProfilePtr->testID == MMCSD_REGRESSION_TEST_EXIT)) {
		 /* No test to run in this profile */
		  continue;
	 }

     if(testID == MMCSD_REGRESSION_ALL_NON_POWERCYCLE_TESTS) {
  	     /* Run all the non powercycle tests */
		 if(testProfilePtr->powerCycleRequired!= FALSE) {
		   continue;
		 }
	  }
	  else {
		/* If the test id does not match , do not continue */
		if(testID != testProfilePtr->testID) {
		  continue;
		}
	  }

     /* Display the test profile selected */
     display_testProfile(testProfilePtr);


    if(MMCSD_socGetInitCfg(MMCSD_INSTANCE_EMMC,&hwAttrsConfig)!=0) {
        MMCSD_log ("\nUnable to obtain config.Exiting. TEST FAILED.\r\n");
        return;
    }

     if(hwAttrsConfigDefaultSaved==0) {
	   /* Save the default hwAttrsConfig, so that it can be retrieved
	    * later after changing the hwAttrs for custom tests */
		 hwAttrsConfigDefault = hwAttrsConfig;
		 hwAttrsConfigDefaultSaved=1;
	 }

#if defined(SOC_OMAPL137)
     /* There is no eMMC support for OMAPL137. This test is verified
      * with MMC card inserted into the same slot used for SD card testing.
      * Default card type will be SD. Change the card type to eMMC for the test here
      */
     hwAttrsConfig.cardType = MMCSD_CARD_EMMC;
     hwAttrsConfigDefault.cardType = MMCSD_CARD_EMMC;
#endif

     /* Set the test profile. For default tests let the hwAttrs config
      * settings such as mode, busWidth etc be unchanged */
   if(testProfilePtr->testID!= MMCSD_REGRESSION_DEFAULT_TEST)
   {
      /* Set the Interrupt parameter */
      hwAttrsConfig.enableInterrupt = testProfilePtr->intr;
      /* Set the Mode parameters */
      hwAttrsConfig.supportedBusVoltages = testProfilePtr->busVoltage;
      /* Set the bus width */
      hwAttrsConfig.supportedBusWidth = testProfilePtr->busWidth;
#if defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
      /* Set the Mode parameters */
      hwAttrsConfig.supportedModes = testProfilePtr->mode;
#endif

   } else {
        /* For default test, retrieve the saved default hwAttrs */
  	    if(hwAttrsConfigDefaultSaved==1) {
  	       hwAttrsConfig= hwAttrsConfigDefault;
  	    }
   }
#ifdef MMCSD_DMA_ENABLED
     hwAttrsConfig.enableDma=1;

#ifdef MMCSD_EDMA_ENABLED
     hwAttrsConfig.edmaHandle = gEdmaHandle;
#endif

#ifdef MMCSD_ADMA_ENABLED /* Enable Interrupts for ADMA2 completion */
#ifdef SIMULATOR
     hwAttrsConfig.enableInterrupt=0;
#else
     hwAttrsConfig.enableInterrupt=1;
#endif
#endif
#endif

      if(hwAttrsConfig.enableDma==1) {
         MMCSD_log ("DMA is enabled \r\n");
      }  else {
         MMCSD_log ("DMA is disabled \n");
      }


      if(hwAttrsConfig.enableInterrupt==1) {
         MMCSD_log ("Interrupts are Enabled \n");
      }  else {
         MMCSD_log ("Interrupts are disabled \n");
      }


      if(MMCSD_socSetInitCfg(MMCSD_INSTANCE_EMMC,&hwAttrsConfig)!=0) {
        MMCSD_log ("\nUnable to set config.Exiting. TEST FAILED.\r\n");
         return;
 	}

#if !defined(SOC_OMAPL137) && !defined(SOC_AM65XX) && !defined(SOC_J721E) && !defined(SOC_J7200)
    GPIO_init();

    EmmcsReset();
#endif

     ret=HSMMCSDReadWriteTest_RAW(testProfilePtr);

    if(ret==0) {
   	  num_tests_passed++;
#ifdef MEASURE_TIME
       MMCSD_log("\n-------- Benchmarks for the below profile -----------\n");
       display_testProfile(testProfilePtr);
       mmcsd_display_benchmarks(testProfilePtr->benchmarks);
#endif
	}
	num_tests_run++;

    MMCSD_log("Test Complete for this profile \n\n");

     if(testProfilePtr->powerCycleRequired) {
         MMCSD_log("\n--------- PLEASE NOTE  ---------- \n");
         MMCSD_log("\n This test required powercycle. \n Before running the next test, Powercycle/System-reset and run other test\n");
      }

      if(testID != MMCSD_REGRESSION_ALL_NON_POWERCYCLE_TESTS) {
		  /* Test completed for this profile. Exit */
		 break;
      }
     } /* testprofile = 0 to .. */
   } /* Loop in the test menu */

   if(num_tests_passed == num_tests_run) {
     MMCSD_log ("\nAll tests have PASSED  \n");
   } else {
     MMCSD_log ("\nSome tests have failed \n");
   }

   MMCSD_log("%d/%d tests passed\n",num_tests_passed,num_tests_run);

#ifdef MMCSD_REGRESSION_TEST
   MMCSD_log("\nExiting the regression test\n");
#endif

}

volatile uint32_t emuwait_board=1;
/*
 *  ======== main ========
 */

int main(void)
{
#ifndef BARE_METAL
	Task_Handle task;
	Error_Block eb;
#endif
    /* Call board init functions */
    Board_initCfg boardCfg;
    Board_STATUS board_status;

#if !defined(SOC_OMAPL137)  && defined(GPIO_ENABLED)
    board_initGPIO();
#endif
    boardCfg = BOARD_INIT_PINMUX_CONFIG |
        BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;

#if defined(SOC_AM65XX) &&  !defined(__aarch64__)
    /* Clear it until the issue is resolved */
    boardCfg &= ~(BOARD_INIT_MODULE_CLOCK);
#endif

    board_status=Board_init(boardCfg);
    if(board_status!=BOARD_SOK) {
		while(emuwait_board);
	}

#ifdef evmAM437x
     pinmux_emmc_AM437x();
#endif
#ifndef BARE_METAL
    Error_init(&eb);
    task = Task_create(mmcsd_test, NULL, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    /* Start BIOS */
    BIOS_start();
#else
  mmcsd_test();
#endif
    return (0);
}

uint32_t txRampBase=0;
int32_t fillMmcPageData(uint8_t *buf, int32_t length, uint8_t flag,uint32_t *rampBase)
{
    int32_t i;
    uint32_t data = 0x00;
    uint8_t incFlag = 0x00;

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
            break;
        case SDMMC_DATA_PATTERN_55:
            data = 0x55;
            break;
        case SDMMC_DATA_PATTERN_INC:
             data = 0x00;
             incFlag = 0x01;
             break;
        case SDMMC_DATA_PATTERN_RAMP32:
             MMCSD_log("\nSD Read/Write 32 bit ramp ");
             break;
		default:
            return -1;
    }

    if(flag==SDMMC_DATA_PATTERN_RAMP32) {
         uint32_t *buf_32 = (uint32_t *)buf;
         for(i =0; i < length/sizeof(uint32_t); i++)  {
             *buf_32=*rampBase;
              buf_32++;
             *rampBase = *rampBase+1;
         }

    } else {
     for(i =0; i < length; i++)  {
        *(buf+i) = data;
         if(incFlag) {
            data++;
         }
      }
    }



    return 0;
}
int32_t HSMMCSDReadWriteTest_RAW(mmcsdTestMMCProfile_t *testProfilePtr)
{
  MMCSD_Handle handle=NULL;
  int32_t j,testRet=-1;
  unsigned long int mmcStartSector;
  int32_t block;
  uint32_t num_blocks_write,num_blocks_read,sizes,num_blocks_write_per_iteration,num_blocks_read_per_iteration;
  MMCSD_Error retVal = MMCSD_OK;

  MMCSD_init();

  MMCSD_log ("\n\nPerforming RAW mode read/write tests ..\n\n");

  retVal=MMCSD_open(MMCSD_INSTANCE_EMMC, NULL, &handle);
  if(retVal!=MMCSD_OK) {
     MMCSD_log ("\n MMCSD_Open failed with retval=%d\r\n",retVal);
     goto raw_test_exit;
  } else {
     MMCSD_log ("\nMMCSD_Open() completed successfully\n");
  }
  mmcStartSector=MMCSTARTSECTOR;

  /* Fill up the data pattern once */
  fillMmcPageData(&tx[0], (MMCSD_TEST_MAX_BUFSIZE), SDMMC_DATA_PATTERN_RAMP32,&txRampBase);

  for(sizes=0;sizes<MMCSD_TEST_NUM_SIZES;sizes++)
  {
    num_blocks_write = mmcsd_test_sizes[sizes]/SECTORSIZE;
    num_blocks_read  = mmcsd_test_sizes[sizes]/SECTORSIZE;

    /* This can be changed to do a custom test */
    num_blocks_write_per_iteration=num_blocks_write;
    num_blocks_read_per_iteration=num_blocks_read;

    /* Clear receive buffer */
    fillMmcPageData(&rx[0], (SECTORSIZE*num_blocks_read), DATA_PATTERN_00,NULL);

#ifdef MEASURE_TIME
     profile_reset_results();
     mmcsd_reset_benchmarks(&(testProfilePtr->benchmarks->RAW_measurements[sizes]));
#endif
     MMCSD_log("\nRAW READ/WRITE: Writing test pattern (%d KB) to the EMMC starting at sector 0x%x in %d block(s) %d KB each \n",mmcsd_test_sizes[sizes]/1024,(unsigned int)mmcStartSector,(num_blocks_write/num_blocks_write_per_iteration),(num_blocks_write_per_iteration*SECTORSIZE)/1024);
#ifdef MEASURE_TIME
     profile_start_point(PROFILE_MMCSD_WRITE);
#endif
    /* Write TEST_GROUP_SECTORS_WRITE blocks at a time */
     for(block=0;block<(num_blocks_write);block+=num_blocks_write_per_iteration)
    {
        retVal = MMCSD_write(handle, &tx[block*SECTORSIZE], mmcStartSector+block, num_blocks_write_per_iteration);
      if(retVal != MMCSD_OK)
      {
          MMCSD_log("\nRAW READ/WRITE: FAIL: Write failed on sector %x\n", (uint32_t) (mmcStartSector + block));
          goto raw_test_exit;
       }
     }
#ifdef MEASURE_TIME
     profile_end_point(PROFILE_MMCSD_WRITE);
#endif

     MMCSD_log("RAW READ/WRITE: Reading test pattern (%d KB) from the EMMC starting at sector 0x%x in %d block(s) %d KB each \n",mmcsd_test_sizes[sizes]/1024,(unsigned int)mmcStartSector,(num_blocks_read/num_blocks_read_per_iteration),(num_blocks_read_per_iteration*SECTORSIZE)/1024);
#ifdef MEASURE_TIME
     profile_start_point(PROFILE_MMCSD_READ);
#endif

     for(block=0;block<(num_blocks_read);block+=num_blocks_read_per_iteration)
     {
        retVal = MMCSD_read(handle, &rx[block*SECTORSIZE], mmcStartSector+block, num_blocks_read_per_iteration);
        if(retVal != MMCSD_OK)
        {
          MMCSD_log("RAW READ/WRITE: FAIL: Read failed on sector %x", (uint32_t) (mmcStartSector + block));
          goto raw_test_exit;
        }
     }

#ifdef MEASURE_TIME
     profile_end_point(PROFILE_MMCSD_READ);
#endif

    if(retVal != MMCSD_OK)
    {
      MMCSD_log("RAW READ/WRITE: AIL: Read failed on sector 0x%x", (uint32_t)mmcStartSector);
      goto raw_test_exit;
    }

    /* Check the pattern */
    for ( j = 0 ; j < (SECTORSIZE*num_blocks_read) ; j++ )
    {
		/* Compare the data read against the expected */
		if ( tx[j] != rx[j])
		{
			MMCSD_log ("FAIL: Data comparison failed @ ");
          MMCSD_log("sector 0x%x", (uint32_t)mmcStartSector);
            MMCSD_log(" ,data %x", j);
			MMCSD_log(" ,rx = %x", rx[j]);
			MMCSD_log(" ,tx = %x", tx[j]);

          goto raw_test_exit;
        }
	 }

      MMCSD_log ("RAW READ/WRITE: PASS: Read/Write Success for this size (%d KB)\r\n",mmcsd_test_sizes[sizes]/1024);

#ifdef MEASURE_TIME
     profile_calculate_results(mmcsd_test_sizes[sizes]);
     mmcsd_store_benchmarks(&(testProfilePtr->benchmarks->RAW_measurements[sizes]),mmcsd_test_sizes[sizes]);
#endif

  }

  testRet=0;

raw_test_exit:
    if(handle) {
      MMCSD_log("\nRAW READ/WRITE : Closing the driver..");
      MMCSD_close(handle);
    }
    return testRet;
}

#if !defined(SOC_OMAPL137) && defined(GPIO_ENABLED)
static void EmmcsReset(void)
{
    /* EMMC reset */
    GPIO_write(GPIO_PIN_EMMC_RST, GPIO_PIN_VAL_LOW);
    delay(100);
    GPIO_write(GPIO_PIN_EMMC_RST, GPIO_PIN_VAL_HIGH);
    delay(100);
}
#endif

#if !defined(SOC_OMAPL137) && defined(GPIO_ENABLED)
/*
 *  ======== Delay function ========
 */
static void delay(unsigned int delayValue)
{
    volatile uint32_t delay1 = delayValue*10000;
    while (delay1--) ;
}
#endif
