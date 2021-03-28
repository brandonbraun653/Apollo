/*
 *  Copyright (C) 2013-2017 Texas Instruments Incorporated - http://www.ti.com/
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
 */
 /**
 *  \file   main.c
 *
 *  \brief This file demonstrates toggling gpio pins high and low
 *         using GPIO dal API's.
 *
 */

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */
#include "stdint.h"
#include <ti/csl/csl_gpio.h>
#if defined (SOC_AM574x) || defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_AM65XX)
#include <ti/board/board.h>
#endif
#if defined (SOC_AM65XX)
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/osal/osal.h>
#else
#include <ti/csl/example/utils/uart_console/inc/uartConfig.h>
#endif
#include <ti/csl/soc.h>
#include <ti/csl/hw_types.h>

/* ========================================================================== */
/*                                 Macros                                     */
/* ========================================================================== */
/* None */

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
static void GpioAppPrint(const char * str);

/* ========================================================================== */
/*                            Global Variables                                */
/* ========================================================================== */
#if defined (SOC_AM65XX)
uint32_t gPinDirection = GPIO_DIRECTION_OUTPUT;
#else
uint32_t gPinDirection = GPIO_DIR_OUTPUT;
#endif

/*To use GpioAppPrint( function for prints*/
/*To use UARTConfigPuts function for prints*/
#if (defined (SOC_AM574x) || defined (SOC_AM572x)) || (defined (SOC_AM571x))
uint32_t uartBaseAddr = CSL_MPU_UART3_REGS;
#endif
#if defined (SOC_TDA2EX) || defined (SOC_DRA72x) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x)
uint32_t uartBaseAddr = SOC_UART1_BASE;
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
uint32_t uartBaseAddr = SOC_UART3_BASE;
#endif

#if (defined (SOC_AM574x) || defined (SOC_AM572x)) || (defined (SOC_AM571x))
uint32_t gpio_base_address = CSL_MPU_GPIO7_REGS;
uint32_t gpio_pin          = 8;
#elif defined (SOC_TDA2EX) || defined (SOC_DRA72x) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x)
uint32_t gpio_base_address = SOC_GPIO1_BASE;
uint32_t gpio_pin          = 14;
#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
uint32_t gpio_base_address = SOC_GPIO4_BASE;
uint32_t gpio_pin          = 9;
#elif defined (SOC_AM65XX)
uint32_t gpio_base_address = CSL_WKUP_GPIO0_BASE;
uint32_t gpio_pin          = 50;
#endif

/* ========================================================================== */
/*                          Function Definitions                              */
/* ========================================================================== */
void padconfig_PrcmEnable()
{
#if defined (SOC_AM574x) || defined (SOC_AM572x) || defined (SOC_AM571x) || defined (SOC_AM65XX)
    /*Pad configurations */
    Board_initCfg boardCfg;
    boardCfg = BOARD_INIT_UNLOCK_MMR | BOARD_INIT_UART_STDIO | 
               BOARD_INIT_MODULE_CLOCK | BOARD_INIT_PINMUX_CONFIG;
    Board_init(boardCfg);  
#endif
#if defined (SOC_AM574x) || defined (SOC_AM572x) || defined (SOC_AM571x)
    HW_WR_REG32(CSL_MPU_CORE_PAD_IO_REGISTERS_REGS+CSL_CONTROL_CORE_PAD_IO_PAD_DCAN1_TX,0x0006000E);
    /*Enable GPIO clock*/
    HW_WR_REG32(CSL_MPU_L4PER_CM_CORE_REGS+CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG,0x102);
     while ((HW_RD_REG32(CSL_MPU_L4PER_CM_CORE_REGS+CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO2_CLKCTRL_REG) & (0x00030000U)) != 0x0)
        {
            ;
        }
    HW_WR_REG32(CSL_MPU_L4PER_CM_CORE_REGS+CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG,0x102);
     while ((HW_RD_REG32(CSL_MPU_L4PER_CM_CORE_REGS+CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO3_CLKCTRL_REG) & (0x00030000U)) != 0x0)
        {
            ;
        }
    HW_WR_REG32(CSL_MPU_L4PER_CM_CORE_REGS+CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG,0x102);
    while ((HW_RD_REG32(CSL_MPU_L4PER_CM_CORE_REGS+CSL_L4PER_CM_CORE_COMPONENT_CM_L4PER_GPIO4_CLKCTRL_REG) & (0x00030000U)) != 0x0)
        {
            ;
        }
#endif
#if defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_TDA2EX) || defined (SOC_DRA72x) || defined (SOC_DRA75x)
    /*Pad configurations */
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_RXD,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_UART1_TXD,0x00040000);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_DCAN1_TX,0x0006000E);
    /*Enable GPIO clock*/
    HW_WR_REG32(SOC_L4PER_CM_CORE_BASE+CM_L4PER_GPIO2_CLKCTRL,0x102);
    while ((HW_RD_REG32(SOC_L4PER_CM_CORE_BASE+CM_L4PER_GPIO2_CLKCTRL) & (0x00030000U)) != 0x0)
        {
            ;
        }
    HW_WR_REG32(SOC_L4PER_CM_CORE_BASE+CM_L4PER_GPIO3_CLKCTRL,0x102);
     while ((HW_RD_REG32(SOC_L4PER_CM_CORE_BASE+CM_L4PER_GPIO3_CLKCTRL) & (0x00030000U)) != 0x0)
        {
            ;
        }
    HW_WR_REG32(SOC_L4PER_CM_CORE_BASE+CM_L4PER_GPIO4_CLKCTRL,0x102);
    while ((HW_RD_REG32(SOC_L4PER_CM_CORE_BASE+CM_L4PER_GPIO4_CLKCTRL) & (0x00030000U)) != 0x0)
        {
            ;
        }
    /* Set the UART Parameters */
    UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8, UART_STOP_BIT_1, UART_NO_PARITY,
                   UART_16x_MODE);
#endif
#if defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_SCLK,0x00040001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_SPI1_CS0,0x00000001);
    HW_WR_REG32(SOC_CORE_PAD_IO_REGISTERS_BASE+CTRL_CORE_PAD_IO_DCAN1_TX,0x0006000E);
    /* Set the access to the GPMC registers - Enable GPMC Clock */
    HW_WR_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_GPIO2_CLKCTRL, 0x102);
    while ((HW_RD_REG32(SOC_L4PER_CM_CORE_BASE +
                    CM_L4PER_GPIO2_CLKCTRL) & (0x00030000U)) != 0x0)
       {
            ;
       }
   HW_WR_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_GPIO3_CLKCTRL, 0x102);
   while ((HW_RD_REG32(SOC_L4PER_CM_CORE_BASE +
                    CM_L4PER_GPIO2_CLKCTRL) & (0x00030000U)) != 0x0)
       {
            ;
       }
   HW_WR_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER_GPIO4_CLKCTRL, 0x102);
   while ((HW_RD_REG32(SOC_L4PER_CM_CORE_BASE +
                    CM_L4PER_GPIO2_CLKCTRL) & (0x00030000U)) != 0x0)
       {
            ;
       }
    /* Set the UART Parameters */
    UARTConfigInit(uartBaseAddr, BAUD_RATE_115200, UART_WORD_LENGTH_8, UART_STOP_BIT_1, UART_NO_PARITY,
                   UART_16x_MODE);
#endif
}
void delay(void)
{
#if defined (SOC_AM65XX)
    Osal_delay(1000);
#else
    volatile uint32_t i;
    for (i = 0; i < 4000000; i++)
    {}
#endif
}

int main(void)
{
    volatile uint32_t checkOutput = 1;

    padconfig_PrcmEnable();
    
    GpioAppPrint("\nGPIO Output App");
    GpioAppPrint("\nGenerating a square wave on GPIO pin");
#if defined (SOC_AM574x) || defined (SOC_AM572x) || defined (SOC_TDA2XX) || defined (SOC_TDA2PX) || defined (SOC_DRA75x) || defined (SOC_AM571x) || defined (SOC_TDA2EX) || defined (SOC_DRA72x)
    GpioAppPrint("\nProbe the GPIO1 pin 14 on JP2 connector - pin 1 on EVM");
#elif defined (SOC_TDA3XX) || defined (SOC_DRA78x)
    GpioAppPrint("\nProbe the GPIO4 pin 9 on J6108 connector - pin 1 on EVM");
#elif defined (SOC_AM65XX)
    GpioAppPrint("\nOn Rev E2 Board it toggles the LD16 LED which is driven from GPIO0-50");
#endif

#if defined (SOC_AM65XX)
    GPIOSetDirMode_v0(gpio_base_address, gpio_pin, gPinDirection);
    while (checkOutput)
    {
        GPIOPinWrite_v0(gpio_base_address, gpio_pin, GPIO_PIN_HIGH);
        delay();

        GPIOPinWrite_v0(gpio_base_address, gpio_pin, GPIO_PIN_LOW);
        delay();
    }

#else
    GPIOModuleReset(gpio_base_address);

    GPIOModuleEnable(gpio_base_address);

    GPIODirModeSet(gpio_base_address, gpio_pin, gPinDirection);

    while (checkOutput)
    {
        GPIOPinWrite(gpio_base_address, gpio_pin, GPIO_PIN_HIGH);
        delay();

        GPIOPinWrite(gpio_base_address, gpio_pin, GPIO_PIN_LOW);
        delay();
    }
#endif

    return 0;
}

static void GpioAppPrint(const char * str)
{
#if defined (SOC_AM65XX)
    UART_printf(str);
#else
    UARTConfigPuts(uartBaseAddr, str, -1);
#endif
}

/********************************* End of file ******************************/

