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
 *
 * \file   emmc_stress_test.h
 *
 * \brief  This is the header file for eMMC stress test.
 *
 */

#ifndef _EMMC_STRESS_TEST_H_
#define _EMMC_STRESS_TEST_H_
 
/* TI-RTOS Header files */
#include <ti/csl/cslr_device.h>
#include <ti/drv/mmcsd/MMCSD.h>
#include <ti/drv/mmcsd/soc/MMCSD_soc.h>

/* UART Header files */
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

/* GPIO Header files */
#include <ti/drv/gpio/GPIO.h>
#ifdef SOC_K2G
#include <ti/drv/gpio/soc/GPIO_soc.h>
#else
#include <ti/drv/gpio/soc/GPIO_soc.h>
#endif

#include "board.h"
#include "board_cfg.h"

#if (defined(SOC_K2G) || defined(SOC_AM65XX))
#include "diag_common_cfg.h"
#endif

/* Global data pointers */
#define HSMMCSD_DATA_SIZE              (512U)
#define PAGE_OFFSET                    (0x0U)

/* @1.5GB 100 */
#define MMCSTARTSECTOR                 (0x300000U) 
/* 0x800 0x5000 10MB 512 */
#define MMCTESTSECTORS                 (0x20U) 

#define SECTORSIZE                     (512U)
#define TESTSECTORS                    (1U) //16 //1
#define TEST_SECTOR_OFFSET             (0x300000U)
#define TOTAL_EMMC_SECTORS             (0x1D20000)/* MAXIE_TBD: TOTAL_EMMC_SECTORS Macro need to be updated with the 
                                                          proper value after reading the CSD Contents */

/* GPIO pin value definitions */
#define GPIO_PIN_VAL_LOW               (0U)
#define GPIO_PIN_VAL_HIGH              (1U)

/* Enable the below macro to have prints on the IO Console */
//#define IO_CONSOLE

#ifndef IO_CONSOLE
#define MMCSD_log                       UART_printf
#else
#define MMCSD_log                       printf
#endif

#if !(defined (EVM_K2G))
typedef CSL_control_core_pad_ioRegs *CSL_padRegsOvly;
#endif

/* ON Board LED pins which are connected to GPIO pins. */
typedef enum GPIO_PIN {
    GPIO_PIN_EMMC_RST      = 0U,
    GPIO_PIN_COUNT
}GPIO_PIN;

/**
 *  \brief    The function performs the eMMC Stress test.
 *
 *  \return   int8_t  
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
int8_t BoardDiag_emmc_stress_test(void);

#endif /* _EMMC_STRESS_TEST_H_ */
