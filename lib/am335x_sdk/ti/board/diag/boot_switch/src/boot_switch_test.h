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
 *
 * \file   boot_switch_test.h
 *
 * \brief  This is the header file for boot switch diagnostic test.
 *
 */

#ifndef _BOOT_SWITCH_TEST_H_
#define _BOOT_SWITCH_TEST_H_ 

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/drv/uart/UART_stdio.h>
#include <ti/csl/soc.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_soc.h>

#include <ti/csl/csl_gpio.h>

#include "diag_common_cfg.h"
#include "board.h"
#include "board_cfg.h"

#if defined(am65xx_evm)
#include "src/am65xx_evm/am65xx_evm_pinmux.h"
#elif defined(am65xx_idk)
#include "src/am65xx_idk/am65xx_idk_pinmux.h"
#elif defined(j721e_evm)
#include "board_pinmux.h"
#include "board_utils.h"
#endif

#if defined(SOC_J721E)
#include "board_internal.h"
#endif

#ifdef __cplusplus
extern "C" {
#endif

#if (defined(am65xx_evm) || defined(am65xx_idk))
#define PADCONFIG_MAX_COUNT             (21U)
#define MAIN_PADCONFIG_MAX_COUNT        (19U)
#define GPIO_PADCONFIG_MUX_MODE         (7U)
#define MODE_PINMUX_MASK                (0xFU)

#define NUM_OF_PATTERNS                 (4U)
#define NUM_OF_SW                       (3U)

#define START_OF_WKUP_PIN_OFFSET        (19U)

#define TOT_NUM_OF_SW                   (21U)

#else
#define PADCONFIG_MAX_COUNT             (16U)
#define MAIN_PADCONFIG_MAX_COUNT        (8U)

#define NUM_OF_PATTERNS                 (4U)
#define NUM_OF_SW                       (2U)

#define START_OF_WKUP_PIN_OFFSET        (8U)
#define TOT_NUM_OF_SW                   (16U)

#endif

typedef struct switchDetails
{
    /* Switch name */
    char swName[4];
    /* Number of switch */
    uint8_t numOfSwPos;
    /* Switch start position */
    uint8_t pinOffset;
}switchDetails_t;

typedef enum bootSwVerifyPattern
{
    PATTERN_00 = 0,
    PATTERN_55,
    PATTERN_AA,
    PATTERN_FF
}bootSwVerifyPattern_t;


/**
 * \brief  boot mode switch test function
 *
 * This test verifies the boot switch mode by reading the 
 *  boot values and compared with expected values.
 *
 * \return  int8_t
 *             0  - In case of success
 *            -1  - In case of failure
 *
 */
int8_t BoardDiag_bootSwitchTest(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _BOOT_SWITCH_TEST_H_ */
