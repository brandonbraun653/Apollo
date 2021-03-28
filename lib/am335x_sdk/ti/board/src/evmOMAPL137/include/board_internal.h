/* ========================================================================== */
/**
 *  @file   board_internal.h
 *
 *  @brief  Private definitions for the Board Library.
 *
 *  ============================================================================
 */
/* --COPYRIGHT--,BSD
 * Copyright (c) 2016-2017, Texas Instruments Incorporated
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

#ifndef _BOARD_INTERNAL_H_
#define _BOARD_INTERNAL_H_

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * Include Files                                                             *
 *****************************************************************************/
#include <ti/csl/csl_types.h>
#include <ti/csl/cslr_device.h>

#include <ti/csl/csl_syscfg.h>
#include <ti/csl/src/ip/syscfg/V0/csl_syscfg.h>
#include <ti/csl/src/ip/syscfg/V0/csl_syscfgAux.h>

#include <ti/csl/csl_emif4f.h>

#include <ti/drv/spi/SPI.h>

#include <ti/drv/i2c/I2C.h>
#include <ti/drv/i2c/soc/I2C_soc.h>

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
/* EMIFB and EMU pin configuration */
#define BOARD_PINMUX0_EMIFB_ENABLE        (0x11112188u)
/* EMIFB pin configuration */
#define BOARD_PINMUX_EMIFB_ENABLE         (0x11111111u)

/* EMIFB pin configuration */
#define BOARD_PINMUX7_EMIFB_ENABLE        (0x00000111u)
/* SPI0_SCS[0], SPI0_ENA, SPI0_CLK, SPI0_SIMO[0] &
   SPI0_SOMI[0] pin configuration */
#define BOARD_PINMUX7_SPI_ENABLE          (0x11111000u)

/* UART2_RXD pin configuration */
#define BOARD_PINMUX8_UART_ENABLE         (0x20000000u)
/* AXR1[11] & AXR1[10] pin configuration */
#define BOARD_PINMUX8_MCASP_ENABLE        (0x01100000u)
/* I2C0_SCL & I2C0_SDA pin configuration */
#define BOARD_PINMUX8_I2C_ENABLE          (0x00022000u)
/* SPI1_CLK, SPI1_SIMO[0] & SPI1_SOMI[0] pin configuration */
#define BOARD_PINMUX8_SPI_ENABLE          (0x00000111u)

/* AFSR0, AFSR0, AFSX0, ACLKX0 & AHCLKX0 pin configuration */
#define BOARD_PINMUX9_MCASP_ENABLE        (0x11011100u)
/* RMII_MHZ_50_CLK pin configuration */
#define BOARD_PINMUX9_EMAC_ENABLE         (0)
/* USB0_DRVVBUS pin configuration */
#define BOARD_PINMUX9_USB_ENABLE          (0x00000010u)
/* UART2_TXD pin configuration */
#define BOARD_PINMUX9_UART_ENABLE         (0x00000002u)

/* EMAC(RMII) pin configuration */
#define BOARD_PINMUX10_EMAC_ENABLE        (0x22222220u)
/* AMUTE0 pin configuration */
#define BOARD_PINMUX10_MCASP_ENABLE       (0x00000001u)

/* AFSX1, ACLKX1, AHCLKX1, AXR2[0], AXR0[10] & AXR0[9] pin configuration */
#define BOARD_PINMUX11_MCASP_ENABLE       (0x11142200u)
/* EMAC(MDIO) pin configuration */
#define BOARD_PINMUX11_EMAC_ENABLE        (0x00000022u)

/* McASP1 pin configuration */
#define BOARD_PINMUX12_MCASP_ENABLE       (0x11111111u)

/* MMCSD_DAT[1] & MMCSD_DAT[0] pin configuration */
#define BOARD_PINMUX13_MMCSD_ENABLE       (0x22000000u)
/* McASP1 pin configuration */
#define BOARD_PINMUX13_MCASP_ENABLE       (0x00111111u)

/* GP0[9] & GP0[8] pin configuration */
#define BOARD_PINMUX14_GPIO_ENABLE        (0x88000000u)
/* MMCSD_DAT[7] to MMCSD_DAT[2] pin configuration */
#define BOARD_PINMUX14_MMCSD_ENABLE       (0x00222222u)

/* MMCSD_CLK pin configuration */
#define BOARD_PINMUX15_MMCSD_ENABLE       (0x20000000u)
/* EMA_A[0] pin configuration */
#define BOARD_PINMUX15_EMIFA_ENABLE       (0x01000000u)
/* GP0[15] to GP0[10] pin configuration */
#define BOARD_PINMUX15_GPIO_ENABLE        (0x00888888u)

/* EMIFA pin configuration */
#define BOARD_PINMUX16_EMIFA_ENABLE       (0x11111110u)
/* MMCSD_CMD pin configuration */
#define BOARD_PINMUX16_MMCSD_ENABLE       (0x00000002u)

/* EMIFA pin configuration */
#define BOARD_PINMUX17_EMIFA_ENABLE       (0x21111111u)

/* EMIFA pin configuration */
#define BOARD_PINMUX18_EMIFA_ENABLE       (0x11111110u)
/* GP2[2] (SDCD) pin configuration */
#define BOARD_PINMUX18_MMCSD_ENABLE       (0x00000008u)

/* EMIFA pin configuration */
#define BOARD_PINMUX19_EMIFA_ENABLE       (0x00000001u)

/*Syscfg SUSPSRC Register Mask for TImer 1*/
#define SYSCFG_SUSPSRC_TIMER64_1SRC_MASK  (0x10000000u)

/*Syscfg SUSPSRC Register Mask for TImer 0*/
#define SYSCFG_SUSPSRC_TIMER64_0SRC_MASK  (0x08000000u)

/*Syscfg SUSPSRC Register shift value for TImer 0*/
#define SYSCFG_SUSPSRC_TIMER64_0SRC_SHIFT (0x0000001Bu)

/*Syscfg SUSPSRC Register shift value for TImer 1*/
#define SYSCFG_SUSPSRC_TIMER64_1SRC_SHIFT (0x0000001Cu)

/*Syscfg SUSOSRC Register Token values  for TImer 0 and 1*/
#define SYSCFG_SUSPSRC_TIMER64_01SRC_ARM  (0x00000000u)

/*****************************************************************************
 * Function Prototypes                                                       *
 *****************************************************************************/
Board_STATUS Board_unlockMMR(void);
Board_STATUS Board_PLLInit(void);
Board_STATUS Board_moduleClockInit(void);
Board_STATUS Board_DDR3Init(void);
Board_STATUS Board_pinmuxConfig(void);
Board_STATUS Board_configEmifPinMux(void);
Board_STATUS Board_uartStdioInit(void);
Board_STATUS Board_internalInitI2C(void);
Board_STATUS Board_EthConfig(void);

#ifdef __cplusplus
}
#endif

#endif /* _BOARD_INTERNAL_H_ */
