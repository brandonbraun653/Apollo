/* ========================================================================== */
/**
 *  @file   board_internal.h
 *
 *  @brief  Private definitions for the Board Library.
 *
 *  ============================================================================
 */
/* --COPYRIGHT--,BSD
 * Copyright (c) 2018, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --/COPYRIGHT--*/

#ifndef BOARD_INTERNAL_H_
#define BOARD_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * Include Files                                                             *
 *****************************************************************************/
#include <ti/csl/csl_types.h>
#include <ti/csl/cslr_device.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/drv/spi/SPI.h>
#include <ti/drv/spi/soc/SPI_soc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/board/board.h>

/*****************************************************************************
 * Internal Objects                                                          *
 *****************************************************************************/
extern I2C_config_list I2C_config;
extern const SPI_Config SPI_config[];

typedef struct
{
    I2C_Handle i2cHandle;
    SPI_Handle spiHandle;
} Board_gblObj;
extern Board_gblObj Board_obj;

/*****************************************************************************
 * Macros                                                                    *
 *****************************************************************************/

/* Macro values defining the different OPP Configuration supported. */
#define OPP_NOM                  (0)
#define OPP_OD                   (1)
#define OPP_HIGH                 (2)

/*****************************************************************************
 * Function Prototypes                                                       *
 *****************************************************************************/

/* Board_STATUS Board_unlockMMR(); */

/**
 *  \brief      Modify PLL settings as required by the examples.
 *
 *  When integrating with SBL, this function should be obsoleted and instead
 *  the appropriate entries should be added to pDpll* tables for the specified
 *  OPP in
 *  <PDK>/ti/boot/sbl_auto/sbl_lib/src/tda2xx/sbl_lib_tda2xx_prcm_dpll.c
 *
 */
Board_STATUS Board_pllConfig(void);

/**
 *  \brief      Enable additional modules used by the examples.
 *
 *  When integrating with SBL, this function should be obsoleted and instead
 *  the appropriate entries should be added to gModuleEnableTable in
 *  <PDK>/ti/boot/sbl_auto/sbl_utils/src/tda2xx/sbl_utils_tda2xx.c.
 */
Board_STATUS Board_moduleEnable();

/**
 *  \brief      Configure Gigabit Ethernet interface.
 */
Board_STATUS Board_gmiiConfig(void);

Board_STATUS Board_watchdogDisable();

/**
 *  \brief      Configure pinmux for modules used in the examples.
 *
 *  When integrating with SBL, this function should be obsoleted and instead
 *  the appropriate entries should be added to gPadDelayConfig* tables in
 *  <PDK>/ti/boot/sbl_auto/sbl_utils/src/tda2xx/sbl_utils_tda2xx_iodelay.c.
 *  With Silicon revision 1.1 or earlier, the tables with suffix 1_0 should be
 *  modified.  Otherwise, the tables with suffix 2_0 should be modified
 */
Board_STATUS Board_pinmuxConfig();

/**
 *  \brief      Get the silicon revision of the device.
 */
uint32_t Board_getSiliconRev(void);

#ifdef __cplusplus
}
#endif

#endif
