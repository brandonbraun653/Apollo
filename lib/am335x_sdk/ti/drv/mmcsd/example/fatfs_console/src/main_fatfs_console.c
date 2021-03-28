/**
 *  \file   main_fatfs_console.c
 *
 *  \brief  Example application main file. This application demonstartes
 *          the file operations on FAT formatted MMCSD device.
 *
 */

/*
 * Copyright (C) 2014-2018 Texas Instruments Incorporated - http://www.ti.com/
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
#include <stdio.h>
#include <ti/sysbios/knl/Task.h>
#include <ti/sysbios/knl/Semaphore.h>

/* BIOS Header files */
#include <ti/sysbios/BIOS.h>
#ifdef MMCSD_EDMA_ENABLED
#include <ti/sysbios/family/arm/a15/Cache.h>
#include <ti/sdo/edma3/drv/edma3_drv.h>
#include <ti/sdo/edma3/rm/edma3_rm.h>
#include <ti/sdo/edma3/drv/sample/bios6_edma3_drv_sample.h>
#endif
#include <xdc/runtime/Error.h>

/* TI-RTOS Header files */
#include <ti/csl/cslr_device.h>
#include "MMCSD_log.h"
#include <ti/fs/fatfs/diskio.h>
#include <ti/fs/fatfs/FATFS.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>
#include <ti/drv/mmcsd/example/fatfs_console/src/fs_shell_app_utils.h>

#include <ti/board/board.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#ifdef MMCSD_EDMA_ENABLED
#if defined(SOC_K2G)
/* MMCSD is connected to EDMA_1 for K2G */
#define MMCSD_EDMACC_NUM 1
#else
#define MMCSD_EDMACC_NUM 0
#endif
#endif

/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/
/* MUX selection for K2G */
#if defined(SOC_K2G)
 #define GPIO_MUX_SEL 4
#endif

#define GPIO_PIN_MMCSD_ACTIVE_STATE 0

/**********************************************************************
 ************************** Internal functions ************************
 **********************************************************************/


/**********************************************************************
 ************************** Global Variables **************************
 **********************************************************************/

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
#if defined(SOC_K2G) || defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
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
    {
        0U
    },
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
const FATFS_Config FATFS_config[_VOLUMES + 1] = {
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

FATFS_Handle fatfsHandle = NULL;

Semaphore_Handle hSem = NULL;

Uint32 fatfsShellProcessFlag = 0;

/* Callback function */
void AppGpioCallbackFxn(void);

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

/*
 *  ======== test function ========
 */
void mmcsd_fatfs_console(UArg arg0, UArg arg1)
{
#ifdef MMCSD_EDMA_ENABLED
    EDMA3_DRV_Result edmaResult = 0;
    EDMA3_RM_Handle gEdmaHandle = NULL;
#if defined(SOC_OMAPL137) || defined(SOC_OMAPL138)
    MMCSD_v0_HwAttrs hwAttrsConfig;
#else
    MMCSD_v1_HwAttrs hwAttrsConfig;
#endif
#endif
	/* Perform board specific GPIO init  */
    board_initGPIO();
#ifdef MMCSD_EDMA_ENABLED
    gEdmaHandle = (EDMA3_RM_Handle)edma3init(MMCSD_EDMACC_NUM, &edmaResult);

	if(MMCSD_socGetInitCfg(0,&hwAttrsConfig)!=0) {
 	   MMCSD_log ("\nUnable to obtain MMCSD config.Exiting. TEST FAILED.\r\n");
	   return;
	}

    hwAttrsConfig.edmaHandle = gEdmaHandle;
    if(MMCSD_socSetInitCfg(0,&hwAttrsConfig)!=0) {
        MMCSD_log ("\nUnable to set config.Exiting. TEST FAILED.\r\n");
         return;
 	}
#endif
    /* GPIO initialization */
    GPIO_init();

    /* Set the callback function */
    GPIO_setCallback(GPIO_PIN_MMC_SDCD, AppGpioCallbackFxn);

    /* Enable GPIO interrupt on the specific gpio pin */
    GPIO_enableInt(GPIO_PIN_MMC_SDCD);

    /* MMCSD FATFS initialization */
    FATFS_init();

    if (GPIO_PIN_MMCSD_ACTIVE_STATE == GPIO_read(GPIO_PIN_MMC_SDCD))
    {
        Semaphore_post(hSem);
    }
    else
    {
        MMCSD_log ("\nPlease insert card.\r\n");
    }

    while(1)
    {
        Semaphore_pend(hSem, BIOS_WAIT_FOREVER );
        if (GPIO_PIN_MMCSD_ACTIVE_STATE == GPIO_read(GPIO_PIN_MMC_SDCD))
        {
            FATFS_open(0U, NULL, &fatfsHandle);
            fatfsShellProcessFlag = 1;
            MMCSD_log ("\nCard inserted.\r\n");
        }
        else
        {
            fatfsShellProcessFlag = 0;
            MMCSD_log ("\nCard Removed.\r\n");
            MMCSD_log ("\nPlease insert card.\r\n");
            FATFS_close(fatfsHandle);
        }
    }
}

/*
 *  ======== Fatfs shell process task function ========
 */
void fatfs_console_taskFn(UArg arg0, UArg arg1)
{
    FSShellAppUtilsProcess();
}

/*
 *  ======== main ========
 */
int main(void)
{
	Task_Handle task;
	Error_Block eb;
	Task_Params taskParams;
	Semaphore_Params semParams;
    /* Call board init functions */
    Board_initCfg boardCfg;
    boardCfg = BOARD_INIT_PINMUX_CONFIG | 
        BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;
    Board_init(boardCfg);

    Task_Params_init(&taskParams);
    Semaphore_Params_init( &semParams );
    Error_init(&eb);

    hSem = ( Semaphore_Handle )Semaphore_create( 0, &semParams, &eb );

    taskParams.instance->name = "FATFFS_Driver";
    taskParams.priority = 2;
    taskParams.stackSize = 0x2048;
    task = Task_create(mmcsd_fatfs_console, &taskParams, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    taskParams.instance->name = "FShellUtilsProcess";
    taskParams.priority = 1;
    taskParams.stackSize = 0x2048;
    task = Task_create(fatfs_console_taskFn, &taskParams, &eb);
    if (task == NULL) {
        System_printf("Task_create() failed!\n");
        BIOS_exit(0);
    }

    /* Start BIOS */
    BIOS_start();
    
    return (0);
}


/*
 *  ======== Callback function ========
 */
void AppGpioCallbackFxn(void)
{
    Semaphore_post(hSem);
}
