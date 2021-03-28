/*
 * audio_evmInit.c
 *
 * This file contains Audio application related EVM (platform) specific routines
 * implementation. 
 * This is part of the EVM Initialization library (evmInit) which contains pinmux
 * enabling routines for peripherals used by the application, and may contain 
 * related device pre-driver initialization routines.
 *
 * Copyright (C) 2009-2018 Texas Instruments Incorporated - http://www.ti.com/
 *
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
 *  \file   audio_evmInit.c
 *
 *  \brief  This file contains the board specific code for enabling the use of
 *          audio driver.
 *
 *  (C) Copyright 2009-2018, Texas Instruments, Inc
 *
 */

#include <xdc/std.h>
#define SW_I2C
#ifndef SW_I2C
#include <i2c/include/I2c.h>
#endif
#include <xdc/runtime/System.h>
#include <Audio_evmInit.h>
#include <ti/csl/cslr_device.h>
#include <ti/csl/soc.h>
#include <ti/drv/mcasp/soc/mcasp_soc.h>
#include <mcasp_cfg.h>
#include <board.h>

#include <ti/csl/hw_types.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/starterware/include/hw/am437x.h>
#include <ti/starterware/include/hw/hw_control_am43xx.h>
#include <ti/starterware/include/am43xx/am437x/hw_cm_wkup.h>
#include <ti/starterware/include/am43xx/am437x/hw_cm_per.h>
#include <ti/starterware/board/am43xx/am43xx_pinmux.h>
#include <ti/starterware/include/chipdb.h>
#include <ti/starterware/include/prcm.h>
#include <ti/starterware/include/error.h>
#include <ti/starterware/include/pinmux.h>
#include <ti/drv/gpio/GPIO.h>
#include <ti/drv/gpio/soc/GPIO_v1.h>
#include <ti/board/board.h>
#include "MCASP_log.h"

/*============================================================================*/
/*                          MACRO DEFINITIONS                                 */
/*============================================================================*/

/**
 *  \brief    Initializes platform specific modules
 *
 *  This function initializes the modules like PLL, DDR, I2C etc
 *  which are required for audio processing. Need to call this function
 *  before doing any HW related operations.
 *
 *  \return    Platform_EOK on Success or error code
 */



extern Board_STATUS Board_init(Board_initCfg);
void Configure_XBAR(void);


/*
 * Function to enable the pinmux for the mcasp and i2c devices in the soc.
 *
 */
/* GPIO pin value definitions */
#define GPIO_PIN_VAL_LOW     (0U)
#define GPIO_PIN_VAL_HIGH    (1U)
/* GPIO Driver board specific pin configuration structure */
GPIO_PinConfig gpioPinConfigs[] = {
    /* Input pin with interrupt disabled */
    GPIO_DEVICE_CONFIG(1, 24) | GPIO_CFG_OUTPUT,
};

/* GPIO Driver call back functions */
GPIO_CallbackFxn gpioCallbackFunctions[] = {
    NULL,
};

/* GPIO Driver configuration structure */
GPIO_v1_Config GPIO_v1_config = {
    gpioPinConfigs,
    gpioCallbackFunctions,
    sizeof(gpioPinConfigs) / sizeof(GPIO_PinConfig),
    sizeof(gpioCallbackFunctions) / sizeof(GPIO_CallbackFxn),
    0,
    };

#ifndef DEVICE_LOOPBACK

void I2C1_ClockCfg()
{
    HWREG(SOC_CM_PER_REG + PRCM_CM_PER_I2C1_CLKCTRL) |=
                             PRCM_CM_PER_I2C1_CLKCTRL_MODULEMODE_ENABLE;

    while((HWREG(SOC_CM_PER_REG + PRCM_CM_PER_I2C1_CLKCTRL) &
      PRCM_CM_PER_I2C1_CLKCTRL_MODULEMODE_MASK) != PRCM_CM_PER_I2C1_CLKCTRL_MODULEMODE_ENABLE);

    while(!(HWREG(SOC_CM_PER_REG + PRCM_CM_PER_L4LS_CLKSTCTRL) &
           (PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_GCLK_MASK |
            PRCM_CM_PER_L4LS_CLKSTCTRL_CLKACTIVITY_I2C_FCLK_MASK)));

    HWREG(SOC_CONTROL_MODULE_REG +PIN_SPI0_D1)=PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(2);
    HWREG(SOC_CONTROL_MODULE_REG +PIN_SPI0_CS0)=PIN_RX_ACTIVE | PIN_PULL_UP_EN | PIN_MODE(2);


}
#endif
void McASP1_ClockCfg(void)
{
#ifdef DEVICE_LOOPBACK
	uint32_t dpllDiv = 0U;
    uint32_t dpllMult = 0U;
    uint32_t dpllPostDivM4 = 0U;
    uint32_t dpllPostDivM5 = 0U;
    uint32_t dpllPostDivM6 = 0U;
    uint32_t crystalFreqSel;
    uint32_t regVal = 0U;
    uint32_t inputClk;
	/* Set the Core PLL (ADPLLS), as per Section 8.1.6.7 in the TRM */
	/*
	1. Switch PLL to bypass mode by setting CM_CLKMODE_DPLL_CORE.DPLL_EN to 0x4

	2. Wait for CM_IDLEST_DPLL_CORE.ST_MN_BYPASS = 1 to ensure PLL is in bypass
	(CM_IDLEST_DPLL_CORE.ST_DPLL_CLK should also change to 0 to denote the PLL is unlocked).
	3. Configure Multiply and Divide values by setting CM_CLKSEL_DPLL_CORE.DPLL_MULT and
	DPLL_DIV to the desired values.
	4. Configure M4, M5 and M6 dividers by setting HSDIVIDER_CLKOUT1_DIV bits in
	CM_DIV_M4_DPLL_CORE,CM_DIV_M5_DPLL_CORE, and CM_DIV_M6_DPLL_CORE to the
	desired values.
	5. Switch over to lock mode by setting CM_CLKMODE_DPLL_CORE.DPLL_EN to 0x7.
	6. Wait for CM_IDLEST_DPLL_CORE.ST_DPLL_CLK = 1 to ensure PLL is locked
	(CM_IDLEST_DPLL_CORE.ST_MN_BYPASS should also change to 0 to denote the PLL is out of
	bypass mode).
	*/
    /* Get input clock frequency. */
    /* Get input clock frequency. */
    crystalFreqSel = HW_RD_FIELD32(SOC_CONTROL_MODULE_REG + CTRL_STS,
        CTRL_STS_SYSBOOT15_14);

    switch(crystalFreqSel)
     {
         case 0U:
         {
             inputClk = 19U;
             break;
         }

         case 1U:
         {
             inputClk = 24U;
             break;
         }

         case 2U:
         {
             inputClk = 25U;
             break;
         }

         case 3U:
         {
             inputClk = 26U;
             break;
         }

         default:
         {
             break;
         }
     }

     /*
      * pllDiv = (inputClk/refClk) - 1U
      * PLL divider derived from input clock with referance clock as 1MHz.
      * PLL divider is same for all PLLs.
      */

    /* The below values are chosen for this EVM because of the following reason */
    /* The MCASP needs a bit clock of 3.072 Mhz (ACLK) - This is derived from
     *   48Khz * 64 bits (because of L+R 32 bit channels) = 3.072 Mhz
     *   But ACLK = AuxCLK /( AHCLKDIV + ACLKDIV)
     *   If we keep AHCLKDIV + ACLKDIV = 8 approx, we get a desired AuxCLK=  24.576 Mhz
     *
     *   In AM335x , the AUXCLK is provided by L4_PER_CLK which is the output of Core PLL
     *   By programming the ADPLLS and the dividers of the Core PLL appropriately, we can
     *   get the 24.576 Mhz, or in this example a close enough value 24.61 Mhz.
     *
     *   The L4_PER_CLK = CLKDCOOUT (of the ADPLLS) /(M4 Div) * (2)
     *                  = (2*(M/(N+1))/((M4 Div)*2)
     */
    dpllDiv = inputClk-1;/* 23 */
    dpllMult = 1000U;
    dpllPostDivM4 = 39U;
    dpllPostDivM5 = 8U;
    dpllPostDivM6 = 4U;

    /* Put the PLL in bypass mode */
     /* Put the PLL in bypass mode */
     HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_CORE,
     PRCM_CM_CLKMODE_DPLL_CORE_EN, PRCM_CM_CLKMODE_DPLL_CORE_EN_MN_BYP_MODE);

     while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_CORE,
         PRCM_CM_IDLEST_DPLL_CORE_ST_MN_BYPASS));

     /* Set the multipler and divider values for the PLL */
     regVal = HW_RD_REG32(SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_CORE);
     HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_CORE_MULT, dpllMult);
     HW_SET_FIELD(regVal, PRCM_CM_CLKSEL_DPLL_CORE_DIV, dpllDiv);
     HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_CLKSEL_DPLL_CORE), regVal);

     /* Configure the High speed dividers */
     /* Set M4 divider */
     HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_DIV_M4_DPLL_CORE), dpllPostDivM4);

     /* Set M5 divider */
     HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_DIV_M5_DPLL_CORE), dpllPostDivM5);

     /* Set M6 divider */
     HW_WR_REG32((SOC_CM_WKUP_REG + PRCM_CM_DIV_M6_DPLL_CORE), dpllPostDivM6);

     /* Now LOCK the PLL by enabling it */
     HW_WR_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_CLKMODE_DPLL_CORE,
         PRCM_CM_CLKMODE_DPLL_CORE_EN, PRCM_CM_CLKMODE_DPLL_CORE_EN_LOCK_MODE);

     while(0U == HW_RD_FIELD32(SOC_CM_WKUP_REG + PRCM_CM_IDLEST_DPLL_CORE,
         PRCM_CM_IDLEST_DPLL_CORE_ST_CLK));

#else
    HWREG(SOC_CM_PER_REG + PRCM_CM_PER_MCASP1_CLKCTRL) =
                           PRCM_CM_PER_MCASP1_CLKCTRL_MODULEMODE_ENABLE;

    while((HWREG(SOC_CM_PER_REG + PRCM_CM_PER_MCASP1_CLKCTRL) &
      PRCM_CM_PER_MCASP1_CLKCTRL_MODULEMODE_MASK) != PRCM_CM_PER_MCASP1_CLKCTRL_MODULEMODE_ENABLE);


    /*
    ** Waiting for IDLEST field in CM_PER_MCASP1_CLKCTRL register to attain the
    ** desired value.
    */
    while((PRCM_CM_PER_MCASP1_CLKCTRL_IDLEST_FUNC <<
           PRCM_CM_PER_MCASP1_CLKCTRL_IDLEST_SHIFT)!=
          (HWREG(SOC_CM_PER_REG + PRCM_CM_PER_MCASP1_CLKCTRL) &
           PRCM_CM_PER_MCASP1_CLKCTRL_IDLEST_MASK));

#endif

}
	
	
	
void I2C1_Enable(void);
void configureAudio(void)
{
	Board_STATUS stat = BOARD_SOK;
	Board_initCfg arg = BOARD_INIT_PINMUX_CONFIG | BOARD_INIT_MODULE_CLOCK | BOARD_INIT_UART_STDIO;
    stat = Board_init(arg);

    if( BOARD_SOK != stat)
    {
        MCASP_log("Board init failed!!");
        return;
    }
#ifndef DEVICE_LOOPBACK
    /* GPIO 0_24 is connected to the AIC Codec's CLKRST . Turning this high
	   enables the AIC Codec */
	GPIO_init();
    GPIO_write(0, GPIO_PIN_VAL_HIGH);
	I2C1_ClockCfg();
#endif
    McASP1_ClockCfg();
}

/*
 * Function to configure SOC specific parameters. This includes SOC
 * specific parameters such as interrupt configuration using Muxes,
 * interrupt configuration etc.
 */
void configMcASP_SocHwInfo()
{
  /* Configure the interrupts for the McASP Instance MCASP_NUM */
  /* ON Keystone, it involves CIC programming as well.
   * The McASP does that internally, if configured with the correct parameters.
   * Such as muxNum, muxInEvent, muxOutEvent,
   * cpuInEventNum, cpuIntNum
  */
    Mcasp_HwInfo hwInfo;

    Mcasp_socGetInitCfg(MCASP_NUM, &hwInfo);


/* Change anything if needed */
    Mcasp_socSetInitCfg(MCASP_NUM,&hwInfo);
}
/* ========================================================================== */
/*                              END OF FILE                                   */
/* ========================================================================== */
