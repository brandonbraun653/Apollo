/**
 *  \file   board_gpioLed.c
 *
 *  \brief:
 *  GPIO LED configurations
 *
*/
/*
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
 **/

#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include <ti/csl/cslr.h>
#include <ti/csl/soc/am572x/src/cslr_control_core_pad_io.h>
#include <ti/board/src/idkAM572x/include/idkam572x_pinmux.h>

#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_v1.h>

#include <src/boardcfg/board_gpioLed.h>


/***********************************************************************/
/* Macros                                        */
/***********************************************************************/

/* Used for McSPI HVS */
/* Port and pin number mask for GPIO Load pin.
   Bits 7-0: Pin number  and Bits 15-8: Port number */
#if defined (idkAM571x)
#define AM57X_IDK_GPIO_LD_PIN    (0x0217)
#else
#define AM57X_IDK_GPIO_LD_PIN    (0x0313)
#endif

/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] =
{
    /* Output pin : AM57X_IDK_RED0_LED */
    GPIO_DEVICE_CONFIG(6, 19) |
    GPIO_CFG_OUTPUT ,

#if defined (idkAM571x)
    /* Output pin : AM57X_IDK_GRN0_LED */
    GPIO_DEVICE_CONFIG(4, 0) |
    GPIO_CFG_OUTPUT,
#else
    /* Output pin : AM57X_IDK_GRN0_LED */
    GPIO_DEVICE_CONFIG(3, 9) |
    GPIO_CFG_OUTPUT,
#endif

    /* Output pin : AM57X_IDK_YEL0_LED */
    GPIO_DEVICE_CONFIG(1, 4) |
    GPIO_CFG_OUTPUT,

    /* Output pin : AM57X_IDK_RED1_LED */
    GPIO_DEVICE_CONFIG(6, 7) |
    GPIO_CFG_OUTPUT,

    /* Output pin : AM57X_IDK_GRN1_LED */
    GPIO_DEVICE_CONFIG(2, 29) |
    GPIO_CFG_OUTPUT,

    /* Output pin : AM57X_IDK_YEL1_LED */
    GPIO_DEVICE_CONFIG(1, 5) |
    GPIO_CFG_OUTPUT,

    /* Output pin : AM57X_IDK_RED2_LED */
    GPIO_DEVICE_CONFIG(7, 9) |
    GPIO_CFG_OUTPUT,

    /* Output pin : AM57X_IDK_GRN2_LED */
    GPIO_DEVICE_CONFIG(7, 8) |
    GPIO_CFG_OUTPUT,

    /* Output pin : AM57X_IDK_YEL2_LED */
    GPIO_DEVICE_CONFIG(7, 10) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_RED3_LED */
    GPIO_DEVICE_CONFIG(7, 11) |
    GPIO_CFG_OUTPUT ,

#if defined (idkAM571x)
    /* Output pin : AM57X_IDK_GRN3_LED */
    GPIO_DEVICE_CONFIG(7, 25) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_YEL3_LED */
    GPIO_DEVICE_CONFIG(7, 24) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_RED0_STATUS_LED */
    GPIO_DEVICE_CONFIG(2, 25) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_GRN0_STATUS_LED */
    GPIO_DEVICE_CONFIG(2, 26) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_YEL0_STATUS_LED */
    GPIO_DEVICE_CONFIG(2, 27) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_RED1_STATUS_LED */
    GPIO_DEVICE_CONFIG(2, 28) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_GRN1_STATUS_LED */
    GPIO_DEVICE_CONFIG(2, 21) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_YEL1_STATUS_LED */
    GPIO_DEVICE_CONFIG(2, 19) |
    GPIO_CFG_OUTPUT ,
    /* Used for McSPI HVS */
    AM57X_IDK_GPIO_LD_PIN | GPIO_CFG_OUTPUT
#else
    /* Output pin : AM57X_IDK_GRN3_LED */
    GPIO_DEVICE_CONFIG(3, 17) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_YEL3_LED */
    GPIO_DEVICE_CONFIG(3, 18) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_RED0_STATUS_LED */
    GPIO_DEVICE_CONFIG(4, 0) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_GRN0_STATUS_LED */
    GPIO_DEVICE_CONFIG(3, 11) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_YEL0_STATUS_LED */
    GPIO_DEVICE_CONFIG(3, 12) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_RED1_STATUS_LED */
    GPIO_DEVICE_CONFIG(3, 10) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_GRN1_STATUS_LED */
    GPIO_DEVICE_CONFIG(7, 23) |
    GPIO_CFG_OUTPUT ,

    /* Output pin : AM57X_IDK_YEL1_STATUS_LED */
    GPIO_DEVICE_CONFIG(7, 22) |
    GPIO_CFG_OUTPUT ,
    /* Used for McSPI HVS */
    AM57X_IDK_GPIO_LD_PIN | GPIO_CFG_OUTPUT
#endif

};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] =
{
    NULL
};

/* GPIO Driver configuration structure */
GPIO_v1_Config GPIO_v1_config =
{
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0x2U,
};

void gpioLedPinmuxConfig()
{
    Uint32 regVal = 0U;
    /* AM57XX_INDETHER_LED0_RED */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_XREF_CLK2_XREF_CLK2_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_XREF_CLK2 = regVal;

#if defined (idkAM571x)
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_VIN2A_VSYNC0_VIN2A_VSYNC0_MUXMODE,
             0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_VIN2A_VSYNC0 =
        regVal;
#else
    /* AM57XX_INDETHER_LED0_GRN */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_VIN1A_D5_VIN1A_D5_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_VIN1A_D5 = regVal;
#endif
    /* AM57XX_INDETHER_LED0_YEL */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_MCASP2_AXR4_MCASP2_AXR4_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_MCASP2_AXR4 =
        regVal;

    /* AM57XX_INDETHER_LED1_RED */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_MCASP2_AXR5_MCASP2_AXR5_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_MCASP2_AXR5 =
        regVal;

    /* AM57XX_INDETHER_LED1_GRN */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_MCASP2_AXR6_MCASP2_AXR6_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_MCASP2_AXR6 =
        regVal;

    /* AM57XX_INDETHER_LED1_YEL */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_MCASP2_AXR7_MCASP2_AXR7_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_MCASP2_AXR7 =
        regVal;

    /* AM57XX_INDETHER_LED2_RED */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_SPI1_D0_SPI1_D0_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_SPI1_D0 = regVal;

    /* AM57XX_INDETHER_LED2_GRN */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_SPI1_D1_SPI1_D1_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_SPI1_D1 = regVal;

    /* AM57XX_INDETHER_LED2_YEL */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_SPI1_CS0_SPI1_CS0_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_SPI1_CS0 = regVal;

    /* AM57XX_INDETHER_LED3_RED */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_SPI1_CS1_SPI1_CS1_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_SPI1_CS1 = regVal;

#if defined (idkAM571x)
    /* AM57XX_INDETHER_LED3_GRN */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_UART2_RTSN_UART2_RTSN_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_UART1_RTSN = regVal;

    /* AM57XX_INDETHER_LED3_YEL */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_UART2_CTSN_UART2_CTSN_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_UART1_CTSN = regVal;

    /* AM57XX_STATUSLED0_RED */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_GPMC_WEN_GPMC_WEN_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_GPMC_WEN = regVal;

    /* AM57XX_STATUSLED0_GRN */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_GPMC_BEN0_GPMC_BEN0_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_GPMC_BEN0 = regVal;

    /* AM57XX_STATUSLED0_YEL */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_GPMC_BEN1_GPMC_BEN1_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_GPMC_BEN1 = regVal;

    /* AM57XX_STATUSLED1_RED */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_GPMC_WAIT0_GPMC_WAIT0_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_GPMC_WAIT0 = regVal;

    /* AM57XX_STATUSLED1_GRN */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_GPMC_CS3_GPMC_CS3_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_GPMC_CS3 = regVal;

    /* AM57XX_STATUSLED1_YEL */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_GPMC_CS0_GPMC_CS0_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_GPMC_CS0 = regVal;
#else
    /* AM57XX_INDETHER_LED3_GRN */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_VIN1A_D13_VIN1A_D13_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_VIN1A_D13 = regVal;

    /* AM57XX_INDETHER_LED3_YEL */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_VIN1A_D14_VIN1A_D14_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_VIN1A_D14 = regVal;

    /* AM57XX_STATUSLED0_RED */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_VIN2A_VSYNC0_VIN2A_VSYNC0_MUXMODE,
             0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_VIN2A_VSYNC0 =
        regVal;

    /* AM57XX_STATUSLED0_GRN */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_VIN1A_D7_VIN1A_D7_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_VIN1A_D7 = regVal;

    /* AM57XX_STATUSLED0_YEL */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_VIN1A_D8_VIN1A_D8_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_VIN1A_D8 = regVal;

    /* AM57XX_STATUSLED1_RED */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_VIN1A_D6_VIN1A_D6_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_VIN1A_D6 = regVal;

    /* AM57XX_STATUSLED1_GRN */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_UART1_TXD_UART1_TXD_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_UART1_TXD = regVal;

    /* AM57XX_STATUSLED1_YEL */
    CSL_FINS(regVal, CONTROL_CORE_PAD_IO_PAD_UART1_RXD_UART1_RXD_MUXMODE, 0xEU);
    ((CSL_padRegsOvly) CSL_MPU_CORE_PAD_IO_REGISTERS_REGS)->PAD_UART1_RXD = regVal;
#endif
}

void  Board_setTriColorLED(uint32_t gpioLeds, uint8_t value)
{
    if(gpioLeds & BOARD_TRICOLOR0_RED)
    {
        GPIO_write(0, value);
    }

    if(gpioLeds & BOARD_TRICOLOR0_GREEN)
    {
        GPIO_write(1, value);
    }

#if !defined (idkAM571x)
    if(gpioLeds & BOARD_TRICOLOR0_YELLOW)
    {
        GPIO_write(2, value);
    }
#endif

    if(gpioLeds & BOARD_TRICOLOR1_RED)

    {
        GPIO_write(3, value);
    }

    if(gpioLeds & BOARD_TRICOLOR1_GREEN)
    {
        GPIO_write(4, value);
    }

    if(gpioLeds & BOARD_TRICOLOR1_YELLOW)
    {
        GPIO_write(5, value);
    }
}
