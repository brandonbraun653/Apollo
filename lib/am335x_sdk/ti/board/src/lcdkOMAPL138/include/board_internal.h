/* ========================================================================== */
/**
 *  @file   board_internal.h
 *
 *  @brief  Private definitions for the Board Library.
 *
 *  ============================================================================
 */
/* --COPYRIGHT--,BSD
 * Copyright (c) 2017, Texas Instruments Incorporated
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
extern "C"
{
#endif

/*****************************************************************************
 * Include Files                                                             *
 *****************************************************************************/
#include <ti/csl/csl_types.h>
#include <ti/csl/cslr_device.h>

#include <ti/csl/csl_syscfg.h>
#include <ti/csl/cslr_syscfg.h>
#include <ti/csl/csl_syscfgAux.h>

#include <ti/csl/csl_emif4f.h>
#include <ti/csl/cslr_ddr2_mddr.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include <ti/board/board.h>

/*****************************************************************************
 * Internal Objects                                                          *
 *****************************************************************************/
extern I2C_config_list I2C_config;

typedef struct
{
    I2C_Handle i2cHandle;
} Board_gblObj;
extern Board_gblObj Board_obj;

/*****************************************************************************
 * Macros                                                                    *
 *****************************************************************************/

#define BOARD_PINMUX0_MCASP_ENABLE       (0x00111111u)
#define BOARD_PINMUX0_GPIO_ENABLE        (0x08000000u)

#define BOARD_PINMUX1_GPIO_ENABLE        (0x08888000u)
#define BOARD_PINMUX1_MCASP_ENABLE       (0x10000111u)

#define BOARD_PINMUX2_EMAC_ENABLE        (0x88888880u)
#define BOARD_PINMUX2_MCASP_ENABLE       (0x00000001u)

#define BOARD_PINMUX3_EMAC_ENABLE        (0x88888888u)

#define BOARD_PINMUX4_UART_ENABLE        (0x22220000u)
#define BOARD_PINMUX4_I2C_ENABLE         (0x00002200u)
#define BOARD_PINMUX4_EMAC_ENABLE        (0x00000088u)

#define BOARD_PINMUX5_EMIF_ENABLE        (0x11000000u)
#define BOARD_PINMUX5_SPI_ENABLE         (0x00110111u)
#define BOARD_PINMUX5_GPIO_ENABLE        (0x00008000u)

#define BOARD_PINMUX6_EMIF_ENABLE        (0x11110001u)
#define BOARD_PINMUX6_GPIO_ENABLE        (0x00008880u)

#define BOARD_PINMUX7_EMIF_ENABLE        (0x11111111u)
#define BOARD_PINMUX8_EMIF_ENABLE        (0x11111111u)
#define BOARD_PINMUX9_EMIF_ENABLE        (0x11111111u)

/* MMCSD (CD) */
#define BOARD_PINMUX10_MMCSD_ENABLE      (0x82222222u)

#define BOARD_PINMUX11_EMIF_ENABLE       (0x11111000u)
#define BOARD_PINMUX11_MMCSD_ENABLE      (0x00000022u)

#define BOARD_PINMUX12_EMIF_ENABLE       (0x11111111u)

/* Last two pins are RESETOUT and CLKOUT */
#define BOARD_PINMUX13_GPIO_ENABLE       (0x88888811u)

#define BOARD_PINMUX14_VPIF_ENABLE       (0x11111111u)
#define BOARD_PINMUX15_VPIF_ENABLE       (0x11001111u)

#define BOARD_PINMUX16_LCD_ENABLE        (0x22222200u)
#define BOARD_PINMUX16_VPIF_ENABLE       (0x00000011u)

#define BOARD_PINMUX17_LCD_ENABLE        (0x22222222u)

#define BOARD_PINMUX18_GPIO_ENABLE       (0x80800000u)
#define BOARD_PINMUX18_LCD_ENABLE        (0x02000022u)
#define BOARD_PINMUX18_MMCSD_ENABLE      (0x00022200u)

#define BOARD_PINMUX19_LCD_ENABLE        (0x02000022u)
#define BOARD_PINMUX19_MMCSD_ENABLE      (0x00022200u)

#define DDR2 0
#define MDDR 1
#define VTP_TIMEOUT 200
#define DDR_DEBUG 0

#define hDDR2Cfg     ((CSL_Ddr2_MddrRegs*)CSL_DDR2_0_CTRL_REGS)

/*****************************************************************************
 * Function Prototypes                                                       *
 *****************************************************************************/
Board_STATUS Board_unlockMMR();
Board_STATUS Board_PLLInit(void);
Board_STATUS Board_moduleClockInit();
Board_STATUS Board_DDR3Init();
Board_STATUS Board_pinmuxConfig();
Board_STATUS Board_uartStdioInit();
Board_STATUS Board_internalInitI2C();
void Board_moduleClockEnable(uint32_t module);
void Board_moduleClockSyncReset(uint32_t module);
Board_STATUS Board_configEmifPinMux(void);

#ifdef __cplusplus
}
#endif

#endif
