/*
 * Copyright (C) 2017 Texas Instruments Incorporated - http://www.ti.com/
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

 /**
 *  \file   pwm_test.c
 *
 *  \brief  PWM diagnostic test file
 *
 *  Targeted Functionality: Validating the CSL functional layer APIs for
 *  PWM module
 *
 *  Operation: This tests demonstrate the usage of PWM CSL FL APIs by 
 *  configuring the PWM module to generate a pulse of 1KHz with different 
 *  duty cycle - 25, 50 and 75%.
 *  
 *  Supported SoCs: K2G, AM572x, AM437x & AM335x
 *
 *  Supported Platforms: evmK2G, evmAM572x, idkAM437x & evmAM335x
 *
 *  Note: Manual verification is needed to confirm the PWM pulse generation.
 *  Details of PWM pin used on each platform is given below
 *  evmK2G     - J12 pin 33
 *  evmAM572x  - P17 pin 5
 *  idkAM437x  - J16 pin 14
 *  evmAM335x  - J5 pin 13
 *  
 */
 
#include "pwm_test.h"

CSL_EpwmAqActionCfg_t aqctrla = {AQ_NO_ACTION, AQ_CLEAR, AQ_TOGGLE, AQ_NO_ACTION, AQ_NO_ACTION, AQ_NO_ACTION};

/* Function to setup PWM module one-time configurations */
static void BoardDiag_pwmInit(uint32_t pwmssBaseAddr)
{
    /*Time base clock configuring using prescaler*/
    CSL_epwmTbTimebaseClkCfg(pwmssBaseAddr, TBCLK_FREQ, MODULE_CLK);

    /*Clearing phase and direction set to count up*/
    CSL_epwmTbSyncEnable(pwmssBaseAddr, CLEAR_PHASE_REG, TB_COUNT_UP);

    /*Disabling the Sync*/
    CSL_epwmTbSyncDisable(pwmssBaseAddr);

    /*Configuring the EPWM_AQCTLA register*/
    CSL_epwmAqActionOnOutputCfg(pwmssBaseAddr, CSL_EPWM_OUTPUT_CH_A, &aqctrla);
}

/* Function to configure PWM pulse generation */
static void BoardDiag_pwmConfig(uint32_t pwmssBaseAddr, float dutyCycle)
{ 
    float period = TBCLK_FREQ/PWM_FREQ;
    
    /* This is the compare count value to be configured to
     * generate the requested dutyCycle.
     */
    uint32_t cmpCntVal = (period - (uint32_t)(period * (dutyCycle/100)));

    /* PWM pulse frequency configuration */
    CSL_epwmTbPwmFreqCfg(pwmssBaseAddr, TBCLK_FREQ, PWM_FREQ, TB_COUNT_UP,
                         TB_IMMEDIATE);

    /* Configuring EPWM_CMPCTL register */
    CSL_epwmCounterComparatorCfg(pwmssBaseAddr, CSL_EPWM_CC_CMP_A,
                                 cmpCntVal, CC_SHADOW,
                                 CC_CTR_ZERO, OVER_WRITE_SHADOW_DISABLED);

    /* Resetting the counter */
    CSL_epwmTbWriteTbCount(pwmssBaseAddr, RESET_TB_COUNT_VALUE);
}

/* Enables clock for PWM module */
static void BoardDiag_pwmClockConfig(void)
{
#if defined(evmAM335x)
    /* Enable PRCM for PWMSS0 */
    HW_WR_REG32((SOC_CM_PER_REGS + CM_PER_EPWMSS0_CLKCTRL), 0x02);

    /* Enable the PWM clock using the PMWSS0 CLKCONFIG Register*/
    HW_WR_REG32((PWM_BASE_ADDRESS + PWMSS_CLKCONFIG), 0x100);

    /* Time base clock for PWMSS1 module */
    HW_WR_REG32((SOC_CONTROL_REGS + CONTROL_PWMSS_CTRL), 0x1);
#elif defined(evmAM572x)
    /* Enable PRCM for PWMSS2 */
    HW_WR_REG32(SOC_L4PER_CM_CORE_BASE + CM_L4PER2_PWMSS2_CLKCTRL, 0x2);
    while ((HW_RD_REG32(SOC_L4PER_CM_CORE_BASE +
                        CM_L4PER2_PWMSS2_CLKCTRL) & (0x00030000)) != 0x0);
    /* Time base clock for PWMSS2 module */
    HW_WR_FIELD32(SOC_CTRL_MODULE_CORE_CORE_REGISTERS_BASE +
                  CTRL_CORE_CONTROL_IO_2,
				  CTRL_CORE_CONTROL_IO_2_PWMSS2_TBCLKEN, 1);
#elif defined(evmK2G)
    /* Time base clock enable for EHRPWM_3 module */
    HW_WR_REG32((CSL_BOOT_CFG_REGS + BOOTCFG_EPWM_CTL_REG_OFFSET), 0x08);
#elif defined(idkAM437x)
    /* Enabling the pwm clock for the PWMSS2 module */
    HW_WR_REG32(PWM_BASE_ADDRESS + PWMSS_CLKCONFIG, 0x100);

    /*Enabling the Time-base clock for the PWMMSS2 module */
    HW_WR_REG32(SOC_CONTROL_MODULE_REG + CTRL_PWMSS, 0x4);
#endif
}

/* Configures pinmux for PWM module */
static void BoardDiag_pwmPinmuxConfig(void)
{
	uint32_t regVal;

#if defined(evmAM335x)
    regVal = HW_RD_REG32(SOC_CONTROL_REGS + CONTROL_CONF_SPI0_SCLK);
	regVal = ((regVal & ~0x07) | 0x03);
    HW_WR_REG32(SOC_CONTROL_REGS + CONTROL_CONF_SPI0_SCLK, regVal);
#elif defined(evmAM572x)
    regVal = HW_RD_REG32(CTRL_CORE_PAD_GPIO6_10_ADDR);
	regVal = ((regVal & ~0x0F) | 0x0A);
    HW_WR_REG32(CTRL_CORE_PAD_GPIO6_10_ADDR, regVal);
#elif defined(evmK2G)
    regVal = HW_RD_REG32(CSL_BOOT_CFG_REGS + BOOTCFG_PAD_CONFIG_REG_73_OFFSET);
	regVal = ((regVal & ~0x0F) | 0x04);
    HW_WR_REG32(CSL_BOOT_CFG_REGS + BOOTCFG_PAD_CONFIG_REG_73_OFFSET, regVal);
#elif defined(idkAM437x)
    regVal = HW_RD_REG32(SOC_CONTROL_MODULE_REG + CTRL_CONF_GPMC_AD8);
	regVal = ((regVal & ~0x0F) | 0x04);
    HW_WR_REG32(SOC_CONTROL_MODULE_REG + CTRL_CONF_GPMC_AD8, regVal);
#endif
}

/* Function to generate delay */
void BoardDiag_pwmAppDelay(uint32_t delay)
{
    volatile uint32_t cnt = 0;
	
    while(cnt < delay)
    {
        asm("");
        cnt++;
    }
}

/*
 *  ======== main ========
 */
int main(void)
{
    uint8_t dutyCycle;

    Board_initCfg boardCfg;

#ifdef PDK_RAW_BOOT
    boardCfg = BOARD_INIT_MODULE_CLOCK |
    BOARD_INIT_PINMUX_CONFIG |
    BOARD_INIT_UART_STDIO;
#else
    boardCfg = BOARD_INIT_UART_STDIO;
#endif

    Board_init(boardCfg);

    UART_printf("\n*********************************************\n");
    UART_printf  ("*                 PWM Test                  *\n");
    UART_printf  ("*********************************************\n");

    BoardDiag_pwmClockConfig();
    BoardDiag_pwmPinmuxConfig();
    BoardDiag_pwmInit(PWM_BASE_ADDRESS);

    /* Configures PWM for different duty cycles */
    for(dutyCycle = 25; dutyCycle <= 75; dutyCycle += 25)
    {
        UART_printf("\nGenerating %dKHz PWM pulse with %d Duty Cycle\n", PWM_FREQ/1000, dutyCycle);
        BoardDiag_pwmConfig(PWM_BASE_ADDRESS, dutyCycle);
        BoardDiag_pwmAppDelay(DELAY);
    }

    /* Reset the duty cycle to 50% */
	BoardDiag_pwmConfig(PWM_BASE_ADDRESS, 50);
    
    UART_printf("\nPWM Test Completed!\n");
    
    /* Restore the default pin mux since the pin mux is changed for PWM */
    boardCfg = BOARD_INIT_PINMUX_CONFIG;
    Board_init(boardCfg);
    
    return 0;
}
