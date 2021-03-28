/**
 *  \file   main.c
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


#ifndef BARE_METAL
/* XDCtools Header files */
#include <xdc/std.h>
#include <xdc/runtime/System.h>
#include <stdio.h>
#include <string.h>
#include <ti/sysbios/knl/Task.h>
#include <xdc/runtime/Error.h>

#include <ti/osal/osal.h>
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
#include "MMCSD_log.h"
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/src/MMCSD_osal.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

#ifdef MMCSD_TEST_FATFS_BENCHMARK_ENABLED
#include <ti/fs/fatfs/ff.h>
#include <ti/fs/fatfs/FATFS.h>

#include <ti/drv/mmcsd/MMCSD.h>

/* MMCSD function table for MMCSD implementation */
FATFS_DrvFxnTable FATFS_drvFxnTable = {
    MMCSD_close,
    MMCSD_control,
    MMCSD_init,
    MMCSD_open,
    MMCSD_write,
    MMCSD_read
};

/* FATFS configuration structure */
FATFS_HwAttrs FATFS_initCfg[_VOLUMES] =
{
#if defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
    {  /* MMC1 is SD card  for AM65xx GP EVM */
        1U
    },
#else
    {
        0U
    },
#endif
    {
        1U
    },
    {
        2U
    },
    {
        3U
    }
};

/* FATFS objects */
FATFS_Object FATFS_objects[_VOLUMES];

/* FATFS configuration structure */
const FATFSConfigList FATFS_config = {
    {
        &FATFS_drvFxnTable,
        &FATFS_objects[0],
        &FATFS_initCfg[0]
    },

    {
         &FATFS_drvFxnTable,
         &FATFS_objects[1],
         &FATFS_initCfg[1]
    },

    {
         &FATFS_drvFxnTable,
         &FATFS_objects[2],
         &FATFS_initCfg[2]
    },

    {NULL, NULL, NULL},

    {NULL, NULL, NULL}
};

#endif



#ifdef MMCSD_EDMA_ENABLED
#include <ti/sdo/edma3/drv/edma3_drv.h>
#include <ti/sdo/edma3/rm/edma3_rm.h>
#include <ti/sdo/edma3/drv/sample/bios6_edma3_drv_sample.h>
#define MMCSD_DMA_ENABLED 1
#endif

#ifdef MMCSD_ADMA_ENABLED
#define MMCSD_DMA_ENABLED 1
#endif

#if !defined(SOC_AM65XX) && !defined(SOC_J721E) && !defined(SOC_J7200)
#define GPIO_ENABLED
#endif


/* TI-RTOS Header files */
#include <ti/csl/cslr_device.h>
#include <ti/csl/csl_chip.h>
#include "MMCSD_log.h"
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/src/MMCSD_osal.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

#include <ti/board/board.h>

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
#define MMCSTARTSECTOR  0x4000 //@8MB for VLAB only
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
#define SDMMC_STRESS_PATTERN_RANDOM_SMH 9
#define SDMMC_STRESS_PATTERN 10

#ifndef BARE_METAL
#define MMCSD_TEST_NUM_SIZES (5U) /* 0.25 MB, 0.5 MB, 1 MB , 2MB , 5MB*/
#if defined (SOC_OMAPL137) || defined (SOC_OMAPL138)
uint32_t mmcsd_test_sizes[MMCSD_TEST_NUM_SIZES]={(1024*256),(1024*512),(1024*1024),(1024*1024*2),(1024*1024*3)};
#else
uint32_t mmcsd_test_sizes[MMCSD_TEST_NUM_SIZES]={(1024*256),(1024*512),(1024*1024),(1024*1024*2),(1024*1024*5)};
#endif
#else
#define MMCSD_TEST_NUM_SIZES (1U) /* 32K */
uint32_t mmcsd_test_sizes[MMCSD_TEST_NUM_SIZES]={(1024*32)};
#endif


#define SECTORSIZE    (512) /* Size of a block */

/* On K2G, GPIO1_12 shares pin with MMC0SDCD */
#define GPIO_MUX_SEL 4


#ifndef GPIO_PIN_MMC_SDCD_ACTIVE_STATE
#define GPIO_PIN_MMC_SDCD_ACTIVE_STATE 0
#endif

#if  defined(iceK2G) || defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
#define MMCSD_INSTANCE_SDCARD  1
#else
  #define MMCSD_INSTANCE_SDCARD  0
  #define MMCSD_INSTANCE_EMMC    1
#endif

/* MUX SEL for K2G */
#define GPIO_MUX_SEL 4

#ifdef MMCSD_EDMA_ENABLED
#if defined(SOC_K2G)
/* MMCSD is connected to EDMA_1 for K2G */
#define MMCSD_EDMACC_NUM 1
#else
#define MMCSD_EDMACC_NUM 0
#endif

#endif

#ifdef GPIO_ENABLED


#ifndef GPIO_PIN_MMC_SDCD_ACTIVE_STATE
  #define GPIO_PIN_MMC_SDCD_ACTIVE_STATE 0
#endif
/* ON Board LED pins which are connected to GPIO pins. */
typedef enum GPIO_PIN {
    GPIO_PIN_MMC_SDCD      = 0U,
    GPIO_PIN_COUNT
}GPIO_PIN;

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Output pin : AM335X_ICE V2_LD_PIN */
    GPIO_DEVICE_CONFIG(GPIO_MMC_SDCD_PORT_NUM, GPIO_MMC_SDCD_PIN_NUM) |
    GPIO_CFG_IN_INT_BOTH_EDGES | GPIO_CFG_INPUT,
};


/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL,
};

/* GPIO Driver configuration structure */
#if defined(SOC_K2G) || defined (SOC_OMAPL137) || defined (SOC_OMAPL138)
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

/* Callback function */
void AppGpioCallbackFxn(void);

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

	ret=Mmu_map(0x42120000, 0x42120000, 0x00001000, &attrs); /* mmcsd        */

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

#if defined(SOC_K2H) || defined(SOC_K2K) || defined(SOC_K2E) || defined(SOC_K2L) || defined(SOC_K2G) || defined(SOC_C6678) || defined(SOC_C6657) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
    GPIO_v0_HwAttrs gpio_cfg;

    /* Get the default SPI init configurations */
    GPIO_socGetInitCfg(GPIO_MMC_SDCD_PORT_NUM, &gpio_cfg);

    /* Modify the default GPIO configurations if necessary */

    /* Set the default GPIO init configurations */
    GPIO_socSetInitCfg(GPIO_MMC_SDCD_PORT_NUM, &gpio_cfg);

#if defined(SOC_K2G)
    /* Setup GPIO interrupt configurations */
    GPIO_socSetIntMux(GPIO_MMC_SDCD_PORT_NUM, GPIO_MMC_SDCD_PIN_NUM, NULL, GPIO_MUX_SEL);
#endif
#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
    /* Setup GPIO interrupt configurations */
    GPIO_socSetBankInt(GPIO_MMC_SDCD_PORT_NUM, GPIO_MMC_SDCD_PIN_NUM, NULL);
#endif
#endif

}
#endif


/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */

/*
 *  ======== test function ========
 */
typedef enum {
   MMCSD_REGRESSION_DS_1BIT_TEST,
   MMCSD_REGRESSION_DS_TEST,
   MMCSD_REGRESSION_HS_TEST,
   MMCSD_REGRESSION_HS_TEST_INTR,
   MMCSD_REGRESSION_1BIT_TEST,
   MMCSD_REGRESSION_4BIT_TEST,
   MMCSD_REGRESSION_INTRMODE_TEST,
   MMCSD_REGRESSION_POLLINGMODE_TEST,
   MMCSD_REGRESSION_UHS_SDR12_TEST,
   MMCSD_REGRESSION_UHS_SDR25_TEST,
   MMCSD_REGRESSION_UHS_SDR50_TEST,
   MMCSD_REGRESSION_UHS_DDR50_TEST,
   MMCSD_REGRESSION_UHS_SDR104_TEST,
   MMCSD_REGRESSION_DEFAULT_TEST,
   MMCSD_REGRESSION_TEST_MAX,
   MMCSD_REGRESSION_UHS_ALL_NON_POWERCYCLE_TESTS= -1,
   MMCSD_REGRESSION_TEST_EXIT = -2,
} mmcsdSDTestIDs_e;


typedef struct {
	/* Test Details */
  mmcsdSDTestIDs_e testID;
  char testDescription[50];
  bool powerCycleRequired; /* if the test needs power cycle before/after the test */
  /* Device Config details */
  MMCSD_SupportedSDModes_e mode;
  MMCSD_BusVoltage_e  busVoltage;
  uint32_t busWidth; /* MMCSD_BUS_WIDTH_1BIT/4BIT/8BIT */
  uint32_t  intr;
  mmcsdTestBenchmarks_t *benchmarks;
} mmcsdTestSDProfile_t;

#if defined(SOC_AM65XX)
/* UHS Tests are disabled for AM65x PG 1.0 due to the silicon issue in 1.8 voltage switching */
#define  MMCSD_UHS_TEST_DISABLED
#endif
mmcsdTestBenchmarks_t SDProfiles_3p3V_DS_1bit_benchmarks;
mmcsdTestSDProfile_t SDProfiles_3p3V_DS_1bit = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_DS_1BIT_TEST,  /* testID */
	                                        " DS Mode 1-bit Test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_DS, /* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_3_3V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_1BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
	                                        &SDProfiles_3p3V_DS_1bit_benchmarks,
										   };

mmcsdTestBenchmarks_t SDProfiles_3p3V_DS_benchmarks;
mmcsdTestSDProfile_t SDProfiles_3p3V_DS = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_DS_TEST,  /* testID */
	                                        " DS Mode Test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_DS, /* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_3_3V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_4BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
	                                        &SDProfiles_3p3V_DS_benchmarks,
										   };

mmcsdTestBenchmarks_t SDProfiles_3p3V_HS_benchmarks;
mmcsdTestSDProfile_t SDProfiles_3p3V_HS = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_HS_TEST,  /* testID */
	                                        " HS Mode Test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_HS, /* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_3_3V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_4BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
	                                        &SDProfiles_3p3V_HS_benchmarks,
										   };

mmcsdTestBenchmarks_t SDProfiles_1p8V_SDR12_benchmarks;
mmcsdTestSDProfile_t SDProfiles_1p8V_SDR12 = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_UHS_SDR12_TEST,  /* testID */
	                                        " SDR12 Mode Test",  /* testDescription */
	                                        TRUE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_DS, /* mode. If 1.8 V this is SDR12 */
	                                       (MMCSD_BusVoltage_e)(MMCSD_BUS_VOLTAGE_3_3V | MMCSD_BUS_VOLTAGE_1_8V), /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_4BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
	                                        &SDProfiles_1p8V_SDR12_benchmarks,
										   };

mmcsdTestBenchmarks_t SDProfiles_1p8V_SDR25_benchmarks;
mmcsdTestSDProfile_t SDProfiles_1p8V_SDR25 = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_UHS_SDR25_TEST,  /* testID */
	                                        " SDR25 Mode Test",  /* testDescription */
	                                        TRUE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_HS, /* mode. If 1.8 V this is SDR12 */
	                                       (MMCSD_BusVoltage_e)(MMCSD_BUS_VOLTAGE_3_3V | MMCSD_BUS_VOLTAGE_1_8V), /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_4BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
	                                        &SDProfiles_1p8V_SDR25_benchmarks,
										   };


mmcsdTestBenchmarks_t SDProfiles_1p8V_SDR50_benchmarks;
mmcsdTestSDProfile_t SDProfiles_1p8V_SDR50 = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_UHS_SDR50_TEST,  /* testID */
	                                        " SDR50 Mode Test",  /* testDescription */
	                                        TRUE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_SDR50, /* mode. If 1.8 V this is SDR12 */
	                                       (MMCSD_BusVoltage_e)(MMCSD_BUS_VOLTAGE_3_3V | MMCSD_BUS_VOLTAGE_1_8V), /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_4BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
	                                        &SDProfiles_1p8V_SDR50_benchmarks,
										   };

mmcsdTestBenchmarks_t SDProfiles_1p8V_DDR50_benchmarks;
mmcsdTestSDProfile_t SDProfiles_1p8V_DDR50 = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_UHS_DDR50_TEST,  /* testID */
	                                        " DDR50 Mode Test",  /* testDescription */
	                                        TRUE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_DDR50, /* mode. If 1.8 V this is SDR12 */
	                                       (MMCSD_BusVoltage_e)(MMCSD_BUS_VOLTAGE_3_3V | MMCSD_BUS_VOLTAGE_1_8V), /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_4BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
	                                        &SDProfiles_1p8V_DDR50_benchmarks,
										   };

mmcsdTestBenchmarks_t SDProfiles_1p8V_SDR104_benchmarks;
mmcsdTestSDProfile_t SDProfiles_1p8V_SDR104 = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_UHS_SDR104_TEST,  /* testID */
	                                        " SDR104 Mode Test",  /* testDescription */
	                                        TRUE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_SDR104, /* mode. If 1.8 V this is SDR12 */
	                                       (MMCSD_BusVoltage_e)(MMCSD_BUS_VOLTAGE_3_3V | MMCSD_BUS_VOLTAGE_1_8V), /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_4BIT, /* busWidth */
	                                        1, /* Interrupt Enabled/Disabled */
	                                        &SDProfiles_1p8V_SDR104_benchmarks,
										   };

mmcsdTestBenchmarks_t SDProfiles_Default_benchmarks;
/* Default test profile which runs at the default configuration allowed in MMCSD_soc.c */
mmcsdTestSDProfile_t SDProfiles_Default = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_DEFAULT_TEST,  /* testID */
	                                        "Default Unit Test (Max speed)",  /* testDescription */
	                                        TRUE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_ALL, /* mode */
	                                       (MMCSD_BusVoltage_e)(MMCSD_BUS_VOLTAGE_3_3V | MMCSD_BUS_VOLTAGE_3_0V | MMCSD_BUS_VOLTAGE_1_8V), /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_4BIT, /* busWidth */
	                                        0, /* Interrupt Enabled/Disabled */
	                                        &SDProfiles_Default_benchmarks,
										   };

mmcsdTestSDProfile_t SDProfiles_All_NonPowerCycleTests = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_UHS_ALL_NON_POWERCYCLE_TESTS,  /* testID */
	                                        " All non powercycle tests",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_DS, /*  mode: Irrelevant. */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_3_3V, /* bus Voltage. Irrelevant. */
	                                        MMCSD_BUS_WIDTH_4BIT, /* busWidth. Irrelevant. */
	                                        0, /* Interrupt Enabled/Disabled .Irrelevant. */
	                                        NULL,
										   };


mmcsdTestSDProfile_t SDProfiles_Exit = {
	                                        /*** Test Config details ***/
	                                        MMCSD_REGRESSION_TEST_EXIT,  /* testID */
	                                        " Exit the regression test",  /* testDescription */
	                                        FALSE, /* powerCycleRequired */
	                                        /*** Device config details ***/
	                                       (MMCSD_SupportedSDModes_e)MMCSD_SUPPORT_SD_DS, /* mode */
	                                       (MMCSD_BusVoltage_e)MMCSD_BUS_VOLTAGE_3_3V, /* bus Voltage */
	                                        MMCSD_BUS_WIDTH_4BIT, /* busWidth */
	                                        0, /* Interrupt Enabled/Disabled .Irrelevant. */
	                                        NULL,
										   };

/******************************************************************************************/
/* Displays a test profile */
/******************************************************************************************/
void display_testProfile(mmcsdTestSDProfile_t *testProfilePtr)
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
  	    case MMCSD_SUPPORT_SD_DS:

   	      if(testProfilePtr->busVoltage & MMCSD_BUS_VOLTAGE_1_8V) {
  		    /* If UHS-I card 1.8V is used, MMCSD_SUPPORT_SD_DS is used as SDR12 */
   	        snprintf(modeString, sizeof(modeString),"%s","SDR12");
   	      } else {
   	        snprintf(modeString, sizeof(modeString),"%s","DS");
		  }

		  break;
	    case MMCSD_SUPPORT_SD_HS:
   	      if(testProfilePtr->busVoltage & MMCSD_BUS_VOLTAGE_1_8V) {
  		    /* If UHS-I card 1.8V is used, MMCSD_SUPPORT_SD_HS is used as SDR25 */
   	        snprintf(modeString, sizeof(modeString),"%s","SDR25");
   	      } else {
   	        snprintf(modeString, sizeof(modeString),"%s","HS");
		  }
		  break;

	    case MMCSD_SUPPORT_SD_SDR50:
   	      snprintf(modeString, sizeof(modeString),"%s","SDR50");
		  break;

	    case MMCSD_SUPPORT_SD_DDR50:
   	      snprintf(modeString, sizeof(modeString),"%s","DDR50");
		  break;

	    case MMCSD_SUPPORT_SD_SDR104:
   	      snprintf(modeString, sizeof(modeString),"%s","MMCSD_SUPPORT_SDR104");
   	      break;

	    case MMCSD_SUPPORT_SD_ALL:
   	      snprintf(modeString, sizeof(modeString),"%s","MMCSD_SUPPORT_SD_ALL (Default)");
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
	    case (MMCSD_BUS_WIDTH_4BIT | MMCSD_BUS_WIDTH_1BIT):
   	      snprintf(busWidthString, sizeof(busWidthString),"%s","(1-bit & 4-bit)");
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


mmcsdTestSDProfile_t * mmcsdTestProfiles[] = {

#ifdef MMCSD_REGRESSION_TEST
/* The below tests are for the detailed regression test only */
	&SDProfiles_3p3V_DS_1bit,
	&SDProfiles_3p3V_DS,
	&SDProfiles_3p3V_HS,
#ifndef MMCSD_UHS_TEST_DISABLED
    &SDProfiles_1p8V_SDR12,
	&SDProfiles_1p8V_SDR25,
	&SDProfiles_1p8V_SDR50,
	&SDProfiles_1p8V_DDR50,

#if !defined(SOC_J721E) && !defined(SOC_J7200)
	&SDProfiles_1p8V_SDR104,
#endif
#endif
    &SDProfiles_Default,
	&SDProfiles_All_NonPowerCycleTests,
	&SDProfiles_Exit,
#else
/* The default non-regression test case which tests the default case */
   &SDProfiles_Default,
#endif
	NULL,
};

/******************************************************************************************/
/* Displays a Regression Test menu */
/******************************************************************************************/

int32_t mmcsd_regression_seek_testID()
{
   mmcsdTestSDProfile_t *testProfilePtr;
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
     for(testprofile=0;testprofile<sizeof(mmcsdTestProfiles)/sizeof(mmcsdTestSDProfile_t *);testprofile++)
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

         if( !((selection == MMCSD_REGRESSION_UHS_ALL_NON_POWERCYCLE_TESTS) ||
             (selection == MMCSD_REGRESSION_TEST_EXIT)) ) {
             MMCSD_log ("Invalid selection: %d !! Please enter a valid test ID from the table!!!\n", selection);
         } else {
		   validInput=TRUE;
		 }
	  }

  } while(validInput==FALSE);

  return(selection);
}

static int32_t HSMMCSDReadWriteTest_RAW(mmcsdTestSDProfile_t *testProfilePtr);

#ifdef MMCSD_TEST_FATFS_BENCHMARK_ENABLED
static int32_t HSMMCSDReadWriteTest_FATFS(mmcsdTestSDProfile_t *testProfilePtr);
#endif

#ifdef MMCSD_EDMA_ENABLED
EDMA3_RM_Handle gEdmaHandle = NULL;
#endif

#if defined (SOC_OMAPL137) || defined (SOC_OMAPL138)
MMCSD_v0_HwAttrs           hwAttrsConfigDefault;
#elif defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
MMCSD_v2_HwAttrs           hwAttrsConfigDefault;
#else
MMCSD_v1_HwAttrs hwAttrsConfigDefault;
#endif
uint32_t hwAttrsConfigDefaultSaved=0;

#ifdef BARE_METAL
void mmcsd_test()
#else
void mmcsd_test(UArg arg0, UArg arg1)
#endif
{
    MMCSD_Error ret;
    int32_t fatfstest_ret;
    bool test_fail=FALSE;
	uint32_t num_tests_run=0,num_tests_passed=0,num_tests_failed=0;
	uint32_t testprofile;
	int32_t testID=0; /* Default */
	mmcsdTestSDProfile_t *testProfilePtr;

#if defined (SOC_OMAPL137) || defined (SOC_OMAPL138)
    MMCSD_v0_HwAttrs           hwAttrsConfig;
#elif defined (SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
    MMCSD_v2_HwAttrs           hwAttrsConfig;
#else
    MMCSD_v1_HwAttrs           hwAttrsConfig;
#endif

#ifdef MMCSD_EDMA_ENABLED
    EDMA3_DRV_Result edmaResult = 0;
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
     /* No Menu required in case of the default unit test. */
      testID = MMCSD_REGRESSION_DEFAULT_TEST;
#endif

      if(testID==MMCSD_REGRESSION_TEST_EXIT) {
         break;
      }

   /* Valid test ID entered. Now search for the test containing the testID in the list of test profiles */


   for(testprofile=0;testprofile<sizeof(mmcsdTestProfiles)/sizeof(mmcsdTestSDProfile_t *);testprofile++)
   {
     testProfilePtr = mmcsdTestProfiles[testprofile];

     if(testProfilePtr==NULL) {
	   MMCSD_log("\nEnd of test profiles");
	   break;
	 }

	  if((testProfilePtr->testID == MMCSD_REGRESSION_UHS_ALL_NON_POWERCYCLE_TESTS) ||
	     (testProfilePtr->testID == MMCSD_REGRESSION_TEST_EXIT)) {
		 /* No test to run in this profile */
		  continue;
	 }

     if(testID == MMCSD_REGRESSION_UHS_ALL_NON_POWERCYCLE_TESTS) {
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


	 if(MMCSD_socGetInitCfg(MMCSD_INSTANCE_SDCARD,&hwAttrsConfig)!=0) {
	    MMCSD_log ("\nUnable to obtain config.Exiting. TEST FAILED.\r\n");
	   return;
	 }

     if(hwAttrsConfigDefaultSaved==0) {
	   /* Save the default hwAttrsConfig, so that it can be retrieved
	    * later after changing the hwAttrs for custom tests */
		 hwAttrsConfigDefault = hwAttrsConfig;
		 hwAttrsConfigDefaultSaved=1;
	 }
#ifdef iceK2G
  /* On K2G ICE EVM , MMC2 is SD Card whereas the default value in the hwInit (defined in soc/k2g/MMCSD_soc.c)
   * corresponds to the K2G EVM where the SD card is in MMC1 and EMMC is in MMC2.
   * Consequently, to run SD Card on K2G ICE, those values need to be re-configured before init()
   */
	 hwAttrsConfig.cardType=MMCSD_CARD_SD;
	 hwAttrsConfigDefault.cardType=MMCSD_CARD_SD;
	 hwAttrsConfig.supportedBusWidth= (MMCSD_BUS_WIDTH_1BIT | MMCSD_BUS_WIDTH_4BIT);
#endif

     readWriteTestFlag = 1;



     /* Set the test profile. For default tests let the hwAttrs config
      * settings such as mode, busWidth etc be unchanged */
    if(testProfilePtr->testID!= MMCSD_REGRESSION_DEFAULT_TEST)
    {

      hwAttrsConfig.enableInterrupt = testProfilePtr->intr;
      hwAttrsConfig.supportedBusVoltages = testProfilePtr->busVoltage;
#if defined(SOC_AM65XX) || defined(SOC_J721E) || defined(SOC_J7200)
      hwAttrsConfig.supportedModes = testProfilePtr->mode;
      hwAttrsConfig.supportedBusWidth = testProfilePtr->busWidth;
#endif
    } else {
        /* For default test, retrieve the saved default hwAttrs */
  	    if(hwAttrsConfigDefaultSaved==1) {
  	       hwAttrsConfig= hwAttrsConfigDefault;
  	    }
   }

  /* Use the voltage switch function implemented by the board library, if it exists.
    * The default is NULL intialized in MMCSD_soc.c */

#if defined(BOARD_MMC_VOLTAGESWITCH_FN)
      MMCSD_log ("\nBoard MMC Voltage Switch Function present\n");
	  hwAttrsConfig.switchVoltageFxn = BOARD_MMC_VOLTAGESWITCH_FN;
#endif
#ifdef MMCSD_DMA_ENABLED
     /* EDMA / ADMA2 / SDMA */
     hwAttrsConfig.enableDma=1;


#ifdef MMCSD_EDMA_ENABLED
      hwAttrsConfig.edmaHandle = gEdmaHandle;
#endif

#ifdef MMCSD_ADMA_ENABLED
     /* Enable Interrupts for ADMA2 completion */
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



     if(MMCSD_socSetInitCfg(MMCSD_INSTANCE_SDCARD,&hwAttrsConfig)!=0) {
       MMCSD_log ("\nUnable to set config.Exiting. TEST FAILED.\r\n");
       return;
     }

	 num_tests_run++;
     ret=HSMMCSDReadWriteTest_RAW(testProfilePtr);

      /* End of MMCSD RAW Tests */
#ifdef MMCSD_TEST_FATFS_BENCHMARK_ENABLED
     {
       fatfstest_ret=HSMMCSDReadWriteTest_FATFS(testProfilePtr);
     }
#else
     fatfstest_ret=0;
#endif

     if((ret!=0) || (fatfstest_ret!=0)) {
 	    test_fail=TRUE;
 	    num_tests_failed++;
 	 } else {
      #ifdef MEASURE_TIME
            /* Display the test profile selected */
       MMCSD_log("\n-------- Benchmarks for the below profile -----------");
       display_testProfile(testProfilePtr);
       mmcsd_display_benchmarks(testProfilePtr->benchmarks);
      #endif

	    num_tests_passed++;
	 }

  	  if(test_fail==TRUE) {
		MMCSD_log("\nTest FAILED for this test configuration \n");
		test_fail=FALSE; /* Reset the test for the next configuration */
	  } else {
		MMCSD_log("\nTest PASSED for this test configuration\n");
	  }

      MMCSD_log("Test Complete for this profile \n\n");

      if(testProfilePtr->powerCycleRequired) {
         MMCSD_log("\n--------- PLEASE NOTE  ---------- \n");
         MMCSD_log("\n This test required powercycle. \n Before running the next test, either Powercycle and run other test  OR  Pop the SD Card out & back in \n");
      }

      if(testID != MMCSD_REGRESSION_UHS_ALL_NON_POWERCYCLE_TESTS) {
		  /* Test completed for this profile. Exit */
		 break;
      }
     } /* testprofile = 0 to .. */

#ifndef MMCSD_REGRESSION_TEST
      testID = MMCSD_REGRESSION_TEST_EXIT;
#endif

   } /* Loop in the test menu */


#ifdef MMCSD_REGRESSION_TEST
   MMCSD_log("\nExiting the regression test\n");
#endif


    if(num_tests_failed==0) {
      MMCSD_log("\nAll tests have PASSED\n");
      MMCSD_log("%d/%d tests passed\n",num_tests_passed,num_tests_run);
    } else {
      MMCSD_log("Some tests have FAILED.");
      MMCSD_log(" (%d/%d tests passed)\n",num_tests_passed,num_tests_run);
    }

}

volatile uint32_t emuwait_board=1;
/*
 *  ======== main ========
 */
int main(void)
{
	Board_STATUS board_status;
#ifndef BARE_METAL
    Task_Handle task;
    Error_Block eb;
#endif

#ifdef GPIO_ENABLED
	board_initGPIO();
#endif

    Board_initCfg boardCfg;
    boardCfg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_UART_STDIO | BOARD_INIT_MODULE_CLOCK;

#if defined(SOC_AM65XX) &&  !defined(__aarch64__)
    /* Clear it until the issue is resolved */
    boardCfg &= ~(BOARD_INIT_MODULE_CLOCK);
#endif

    board_status=Board_init(boardCfg);
    if(board_status!=BOARD_SOK) {
		while(emuwait_board);
	}

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
            //MMCSD_log("\nSD Read/Write pattern 0xAA ");
            break;
        case SDMMC_DATA_PATTERN_55:
            data = 0x55;
            //MMCSD_log("\nSD Read/Write pattern 0x55 ");
            break;
        case SDMMC_DATA_PATTERN_INC:
             data = 0;
             incFlag = 0x01;
             //MMCSD_log("\nSD Read/Write incremental data");
             break;
        case SDMMC_DATA_PATTERN_RAMP32:
             //MMCSD_log("\nSD Read/Write 32 bit ramp ");
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

    }
    else {
     for(i =0; i < length; i++)  {
        *(buf+i) = data;
         if(incFlag) {
            data++;
         }
      }
    }



    return 0;
}

/*****************************************************************************
* Read Write test performed through MMCSD driver (direct read/write) in RAW mode
* i.e writing various sizes of buffers (0.25 MB/ 0.5MB/ 1MB/ 2MB) buffers written
* to the card and reading back the pattern and the performance is measured.
******************************************************************************/
int32_t HSMMCSDReadWriteTest_RAW(mmcsdTestSDProfile_t *testProfilePtr)
{
  MMCSD_Handle handle=NULL;
  int32_t j,testRet=-1;
  unsigned long int mmcStartSector;
  int32_t block;
  uint32_t num_blocks_write,num_blocks_read,sizes,num_blocks_write_per_iteration,num_blocks_read_per_iteration;
  /* Media configuration such as SD card size, blocksize, blockCount */
  MMCSD_mediaParams  mediaParams;
  MMCSD_Error retVal = MMCSD_OK;

  MMCSD_init();

  MMCSD_log ("\n\nPerforming RAW mode read/write tests ..\n\n");

  retVal=MMCSD_open(MMCSD_INSTANCE_SDCARD, NULL, &handle);
  if(retVal!=MMCSD_OK) {
     MMCSD_log ("\nMMCSD_Open failed with retval=%d\r\n",retVal);
     goto raw_test_exit;

  } else {
     MMCSD_log ("\nMMCSD_Open() completed successfully\n");
  }

  /* Getting Card parameters */
  MMCSD_log("Getting SD Card parameters\n");
  if((retVal=MMCSD_control(handle, MMCSD_CMD_GETMEDIAPARAMS, (void *)&mediaParams))!=MMCSD_OK) {
    MMCSD_log("Getting SD Card parameters failed !!");
    goto raw_test_exit;
  }

  /* The blockCount & size below are unsigned long long, which needs %llu, which is currently not
   * supported by UART_printf(). Hence splitting them in to two 32 bit words for printing below.
  */
  MMCSD_log("SD Card: BlockSize = %d,  BlockCount = 0x%x%x, CardSize = 0x%x%x bytes\n",mediaParams.blockSize,
                                              (unsigned int)(mediaParams.blockCount >> 32),
                                              (unsigned int)(mediaParams.blockCount & 0xFFFFFFFF),
                                              (unsigned int)(mediaParams.size >> 32),
                                              (unsigned int)(mediaParams.size & 0xFFFFFFFF));



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

    MMCSD_log("\nRAW READ/WRITE: Writing test pattern (%d KB) to the SD card starting at sector 0x%x in %d block(s) %d KB each \n",mmcsd_test_sizes[sizes]/1024,mmcStartSector,(num_blocks_write/num_blocks_write_per_iteration),(num_blocks_write_per_iteration*SECTORSIZE)/1024);

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



    MMCSD_log("RAW READ/WRITE: Reading test pattern (%d KB) from the SD card starting at sector 0x%x in %d block(s) %d KB each \n",mmcsd_test_sizes[sizes]/1024,(unsigned int)mmcStartSector,(num_blocks_read/num_blocks_read_per_iteration),(num_blocks_read_per_iteration*SECTORSIZE)/1024);

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

#ifdef MMCSD_TEST_FATFS_BENCHMARK_ENABLED
DIR MMCSD_FS_DirObj;
FILINFO MMCSD_FS_FileInfo;
char MMCSD_FS_Cwd[512]="0:";
#define SOC_CACHELINE_SIZE (512)
#define FS_SHELL_APP_UTILS_PATH_BUF_SIZE (512)
/* Defines size of the buffers that hold temporary data. */
/*****************************************************************************
A temporary data buffer used when manipulating file paths, or reading data
from the memory card.
******************************************************************************/
static FIL MMCSD_FS_ReadFileObj  __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

/*****************************************************************************
A temporary data buffer used when manipulating file paths, or reading data
from the memory card.
******************************************************************************/
static FIL MMCSD_FS_WriteFileObj  __attribute__ ((aligned (SOC_CACHELINE_SIZE)));

/*****************************************************************************
A temporary data buffer used when manipulating file paths, or reading data
from the memory card.
******************************************************************************/
static char MMCSD_FS_filepath[FS_SHELL_APP_UTILS_PATH_BUF_SIZE]="0:/temp_fatfs.txt";

/*****************************************************************************
* Read Write test performed through FATFS driver . THis test involves
* writing various sizes of buffers (0.25 MB/ 0.5MB/ 1MB/ 2MB) buffers written
* to a temporary file and reading back the pattern and the performance is measured.
******************************************************************************/
int32_t HSMMCSDReadWriteTest_FATFS(mmcsdTestSDProfile_t *testProfilePtr)
{
  int32_t j;
  FRESULT fresultRead = FR_NOT_READY;
  FRESULT fresultWrite = FR_NOT_READY;
  FRESULT fresultClose= FR_NOT_READY;
  FRESULT fresultDelete = FR_NOT_READY;
  FATFS_Handle fatfsHandle = NULL;

  uint32_t bytesWrite = 0;
  uint32_t bytesRead = 0;
  uint32_t flagWrite = FALSE;
  uint32_t flagRead = FALSE;
  int32_t fatfsTestRet=-1;
  uint32_t sizes;

  FATFS_Error fatfs_ret;

   MMCSD_log ("\n\nPerforming FATFS read/write tests ..\n\n");
  /* MMCSD FATFS initialization */
  fatfs_ret=FATFS_init();
  if(fatfs_ret==FATFS_ERR) {
    MMCSD_log("\n FATFS init failed!!");
    goto fatfs_test_exit;
  }

  /* Open FATFS instance */
  fatfs_ret=FATFS_open(0U, NULL, &fatfsHandle);
  if(fatfs_ret==FATFS_ERR) {
	MMCSD_log("\n FATFS open failed!!");
    goto fatfs_test_exit;
  }

  /* Fill up the data pattern once */
  fillMmcPageData(&tx[0], (MMCSD_TEST_MAX_BUFSIZE), SDMMC_DATA_PATTERN_RAMP32,&txRampBase);

  for(sizes=0;sizes<MMCSD_TEST_NUM_SIZES;sizes++)
  {

     /* Clear receive buffer */
     fillMmcPageData(&rx[0], mmcsd_test_sizes[sizes], DATA_PATTERN_00,NULL);

#ifdef MEASURE_TIME
     profile_reset_results();
     mmcsd_reset_benchmarks(&(testProfilePtr->benchmarks->FATFS_measurements[sizes]));
#endif

    fresultWrite = f_open(&MMCSD_FS_WriteFileObj, MMCSD_FS_filepath,FA_WRITE|FA_OPEN_ALWAYS);

     if(fresultWrite != FR_OK) {
       MMCSD_log("FATFS READ/WRITE: Fail to open file %s for write !!!!\n",MMCSD_FS_filepath);
       goto fatfs_test_exit;
     } else  {
       flagWrite = TRUE;
     }

     if(TRUE == flagWrite) {

       MMCSD_log("\nFATFS READ/WRITE: Writing test pattern (%d KB) to file %s with \n",mmcsd_test_sizes[sizes]/1024,MMCSD_FS_filepath);

#ifdef MEASURE_TIME
       profile_start_point(PROFILE_MMCSD_WRITE);
#endif
       fresultWrite = f_write(&MMCSD_FS_WriteFileObj, &tx[0],
                                       mmcsd_test_sizes[sizes], &bytesWrite);
#ifdef MEASURE_TIME
       profile_end_point(PROFILE_MMCSD_WRITE);
#endif
       if(fresultWrite != FR_OK)  {
          MMCSD_log("\n FATFS READ/WRITE: Fail to write into file with error code %d!!!!\n",fresultWrite);
          goto fatfs_test_exit;
       }

       if(bytesWrite!= mmcsd_test_sizes[sizes]) {
          MMCSD_log("\n FATFS READ/WRITE: FAIL: Write operation wrote only %d of %d bytes",bytesWrite,mmcsd_test_sizes[sizes]);
          goto fatfs_test_exit;
       }
     }

   	 /*
	   * Close the Write file.
	 */
	  if(TRUE == flagWrite){
		fresultClose = f_close(&MMCSD_FS_WriteFileObj);

		if(fresultClose != FR_OK) {
          MMCSD_log("FATFS READ/WRITE: Fail to close write file with an error code %d!!!!\n",fresultWrite);
          goto fatfs_test_exit;
		}
  	  }


    fresultRead = f_open(&MMCSD_FS_ReadFileObj, MMCSD_FS_filepath, FA_READ);
    if(fresultRead != FR_OK)  {
       MMCSD_log("FATFS READ/WRITE: Fail to open file %s for reading with return code %d!!!!\n",MMCSD_FS_filepath,fresultRead);
       goto fatfs_test_exit;
    }  else  {
       flagRead = TRUE;
    }


    if(TRUE == flagRead) {

     MMCSD_log("FATFS READ/WRITE: Reading test pattern (%d KB) from file %s with \n",mmcsd_test_sizes[sizes]/1024,MMCSD_FS_filepath);

#ifdef MEASURE_TIME
      profile_start_point(PROFILE_MMCSD_READ);
#endif
      fresultRead = f_read(&MMCSD_FS_ReadFileObj, &rx[0], mmcsd_test_sizes[sizes], &bytesRead);
#ifdef MEASURE_TIME
      profile_end_point(PROFILE_MMCSD_READ);
#endif


      if(fresultRead != FR_OK) {
        MMCSD_log("\n FATFS READ/WRITE: Fail to write into file!!!!\n");
        goto fatfs_test_exit;
      }

      if(bytesRead!= mmcsd_test_sizes[sizes]) {
        MMCSD_log("\nFATFS READ/WRITE: FAIL: Read operation wrote only %d of %d bytes",bytesRead,mmcsd_test_sizes[sizes]);
        goto fatfs_test_exit;
      }
    }

  	 /* Close the read file */
	  if(FR_OK == fresultClose){
		fresultClose = f_close(&MMCSD_FS_ReadFileObj);

		if(fresultClose != FR_OK) {
           MMCSD_log("\nFATFS: Fail to close write file with an error code %d!!!!\n",fresultClose);
           goto fatfs_test_exit;
		}
  	  }

   	 /* Delete the read file */
	  if(TRUE == fresultDelete){
		fresultDelete = f_unlink(MMCSD_FS_filepath);

		if(fresultDelete != FR_OK) {
            MMCSD_log("FATFS READ/WRITE: Fail to close write file with an error code %d!!!!\n",fresultDelete);
            goto fatfs_test_exit;
		}
  	  }



    /* Check the pattern */
    for ( j = 0 ; j < (mmcsd_test_sizes[sizes]) ; j++ )
    {
        /* Compare the data read against the expected */
        if ( tx[j] != rx[j])
        {
            MMCSD_log ("FATFS READ/WRITE: Data comparison failed at byte at %d ",j);
            MMCSD_log(" ,rx[%d] = %x", rx[j],j);
            MMCSD_log(" ,tx[%d] = %x", tx[j],j);
            goto fatfs_test_exit;
        }
     }

     MMCSD_log ("FATFS PASS: Read/Write Success for this size (%d KB)  \r\n",mmcsd_test_sizes[sizes]/1024 );

#ifdef MEASURE_TIME
     profile_calculate_results(mmcsd_test_sizes[sizes]);
     mmcsd_store_benchmarks(&(testProfilePtr->benchmarks->FATFS_measurements[sizes]),mmcsd_test_sizes[sizes]);
#endif

  }

  fatfsTestRet=0;

fatfs_test_exit:
  if(fatfsHandle) {
    fatfs_ret=FATFS_close(fatfsHandle);
    if(fatfs_ret==FATFS_ERR) {
      MMCSD_log("\n FATFS close failed!!");
	  fatfsTestRet=-1;
	}
  }
  return fatfsTestRet;
}

#endif


/*
 *  ======== Callback function ========
 */
void AppGpioCallbackFxn(void)
{
#ifdef GPIO_ENABLED

    if (GPIO_PIN_MMC_SDCD_ACTIVE_STATE == GPIO_read(GPIO_PIN_MMC_SDCD))
    {
        readWriteTestFlag = 1;
    }
    else
    {
        readWriteTestFlag = 0;
    }
#endif
}
