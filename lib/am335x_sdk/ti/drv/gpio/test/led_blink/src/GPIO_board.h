/**
 *  \file   GPIO_board.h
 *
 *  \brief  GPIO board header file.
 *
 */

/*
 * Copyright (C) 2014 - 2018 Texas Instruments Incorporated - http://www.ti.com/
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


#ifndef _GPIO_BOARD_H
#define _GPIO_BOARD_H

#ifdef __cplusplus
extern "C" {
#endif


/* Example/Board Header files */
#include <ti/board/board.h>

#if defined (SOC_AM572x) || defined (SOC_AM574x)
#include <ti/csl/soc/am572x/src/cslr_soc_mpu_baseaddress.h>
#endif

#if defined (SOC_AM571x)
#include <ti/csl/soc/am571x/src/cslr_soc_mpu_baseaddress.h>
#endif

#if defined (SOC_AM65XX)
#include <ti/csl/src/ip/intr_router/V0/csl_intr_router.h>
#include <ti/csl/soc/am65xx/src/cslr_soc_baseaddress.h>
#include <ti/csl/soc/am65xx/src/cslr_mcu_ctrl_mmr.h>
#include <ti/csl/soc/am65xx/src/cslr_mcu_pll_mmr.h>
#include <ti/csl/soc/am65xx/src/cslr_wkup_ctrl_mmr.h>
#endif

#if defined (SOC_J721E)
#include <ti/csl/src/ip/intr_router/V0/csl_intr_router.h>
#include <ti/csl/soc/j721e/src/cslr_soc_baseaddress.h>
#include <ti/csl/soc/j721e/src/cslr_mcu_ctrl_mmr.h>
#include <ti/csl/soc/j721e/src/cslr_mcu_pll_mmr.h>
#include <ti/csl/soc/j721e/src/cslr_wkup_ctrl_mmr.h>
#endif

#if defined (SOC_J7200)
#include <ti/csl/soc/j7200/src/cslr_soc_baseaddress.h>
#include <ti/csl/soc/j7200/src/cslr_mcu_ctrl_mmr.h>
#include <ti/csl/soc/j7200/src/cslr_mcu_pll_mmr.h>
#include <ti/csl/soc/j7200/src/cslr_wkup_ctrl_mmr.h>
#endif
/**********************************************************************
 ************************** Macros ************************************
 **********************************************************************/
#if defined (idkAM572x) || defined (idkAM574x)
#define GPIO_INTR_LED_BASE_ADDR_1P2      (CSL_MPU_GPIO4_REGS)
#define GPIO_LED_PIN_NUM_1P2             (0x04U)
#define GPIO_INTR_LED_BASE_ADDR_1P3      (CSL_MPU_GPIO7_REGS)
#define GPIO_LED_PIN_NUM_1P3             (0x17U)
#endif

#if defined (idkAM571x)
#define GPIO_INTR_LED_BASE_ADDR      (CSL_MPU_GPIO2_REGS)
#define GPIO_LED_PIN_NUM             (0x15U)
#endif

#if defined (evmAM572x)
#if defined (__TI_ARM_V7M4__)
#define GPIO_INTR_LED_BASE_ADDR      (CSL_MPU_GPIO1_REGS)
#define GPIO_LED_PIN_NUM             (0x10U)
#else
#define GPIO_INTR_LED_BASE_ADDR      (CSL_MPU_GPIO7_REGS)
#define GPIO_LED_PIN_NUM             (0x08U)
#endif
#endif

#if defined (evmAM572x) || defined (idkAM571x) || \
    defined (skAM437x) || defined (evmAM437x) || \
    defined (icev2AM335x) || defined (skAM335x) || defined (bbbAM335x)
#define GPIO_BASE_ADDR GPIO_INTR_LED_BASE_ADDR
#define GPIO_LED_PIN   GPIO_LED_PIN_NUM
#endif

#if defined (evmK2H) || defined (evmK2K)
#define K2H_EVM_USER0_LED_RED    (12U) /* GPIO pin 12 */
#define K2H_EVM_USER0_LED_GREEN  (13U) /* GPIO pin 13 */
#define K2H_EVM_USER1_LED_BLUE   (14U) /* GPIO pin 14 */
#define K2H_EVM_USER2_LED_BLUE   (15U) /* GPIO pin 15 */

#define GPIO_LED0_PIN_NUM        K2H_EVM_USER0_LED_GREEN
#define GPIO_LED0_PORT_NUM       (0U)  /* GPIO port 0 */
#define GPIO_LED1_PIN_NUM        K2H_EVM_USER2_LED_BLUE
#define GPIO_LED1_PORT_NUM       (0U)  /* GPIO port 0 */
#endif

#if defined (evmK2E)
#define K2E_EVM_USER0_LED_RED    (12U) /* GPIO pin 12 */
#define K2E_EVM_USER0_LED_GREEN  (13U) /* GPIO pin 13 */
#define K2E_EVM_USER1_LED_BLUE   (14U) /* GPIO pin 14 */
#define K2E_EVM_USER2_LED_BLUE   (15U) /* GPIO pin 15 */

#define GPIO_LED0_PIN_NUM        K2E_EVM_USER0_LED_GREEN
#define GPIO_LED0_PORT_NUM       (0U)  /* GPIO port 0 */
#define GPIO_LED1_PIN_NUM        K2E_EVM_USER1_LED_BLUE
#define GPIO_LED1_PORT_NUM       (0U)  /* GPIO port 0 */
#endif

#if defined (evmK2L)
/* No gpio pin directly connect to LED on K2L EVM */
#define GPIO_LED0_PIN_NUM        (8U)
#define GPIO_LED0_PORT_NUM       (0U)  /* GPIO port 0 */
#define GPIO_LED1_PIN_NUM        (9U)
#define GPIO_LED1_PORT_NUM       (0U)  /* GPIO port 0 */
#endif

#if defined (evmK2G)
#define GPIO_LED0_PIN_NUM        (108U) /* by default PADCONFIG139 set to GPIO0_108 */
#define GPIO_LED0_PORT_NUM       (0U)   /* GPIO port 0 */
#define GPIO_LED1_PIN_NUM        (11U)  /* by default PADCONFIG186 set to GPIO1_11 */
#define GPIO_LED1_PORT_NUM       (1U)   /* GPIO port 1 */

#ifdef _TMS320C6X
#define GPIO_MUX_SEL             (16U) /* Event slect number for DSP GPIOMUX int */
#else
#define GPIO_MUX_SEL             (0U)  /* Event slect number for ARM GPIOMUX int */
#endif
#endif

#if defined (iceK2G)
#define GPIO_LED0_PIN_NUM        (11U) /* by default PADCONFIG139 set to GPIO0_108 */
#define GPIO_LED0_PORT_NUM       (0U)   /* GPIO port 0 */
#define GPIO_LED1_PIN_NUM        (12U)  /* by default PADCONFIG186 set to GPIO1_11 */
#define GPIO_LED1_PORT_NUM       (1U)   /* GPIO port 1 */

#ifdef _TMS320C6X
#define GPIO_MUX_SEL             (16U) /* Event slect number for DSP GPIOMUX int */
#else
#define GPIO_MUX_SEL             (0U)  /* Event slect number for ARM GPIOMUX int */
#endif
#endif

#if defined (evmC6678)
/* No gpio pin directly connect to LED on C6678 EVM */
#define GPIO_LED0_PIN_NUM        (8U)
#define GPIO_LED0_PORT_NUM       (0U)  /* GPIO port 0 */
#define GPIO_LED1_PIN_NUM        (9U)
#define GPIO_LED1_PORT_NUM       (0U)  /* GPIO port 0 */
#endif

#if defined (evmC6657)
/* No gpio pin directly connect to LED on C6678 EVM */
#define GPIO_LED0_PIN_NUM        (8U)
#define GPIO_LED0_PORT_NUM       (0U)  /* GPIO port 0 */
#define GPIO_LED1_PIN_NUM        (9U)
#define GPIO_LED1_PORT_NUM       (0U)  /* GPIO port 0 */
#endif

#if defined (am65xx_evm) || defined (am65xx_idk) || defined (j721e_sim)
#if defined(AM65XX_BETA_BOARD)
#define GPIO_LED0_PIN_NUM        BOARD_WKUP_GPIO_LD18_GREEN_PIN_NUM
#define GPIO_LED0_PORT_NUM       BOARD_WKUP_GPIO_LD18_GREEN_PORT_NUM
#define GPIO_LED1_PIN_NUM        BOARD_WKUP_GPIO_LD18_RED_PIN_NUM
#define GPIO_LED1_PORT_NUM       BOARD_WKUP_GPIO_LD18_RED_PORT_NUM
#else
#define GPIO_LED0_PIN_NUM        BOARD_WKUP_GPIO_LD16_PIN_NUM
#define GPIO_LED0_PORT_NUM       BOARD_WKUP_GPIO_LD16_PORT_NUM
#define GPIO_LED1_PIN_NUM        BOARD_WKUP_GPIO_LD17_PIN_NUM
#define GPIO_LED1_PORT_NUM       BOARD_WKUP_GPIO_LD17_PORT_NUM
#endif
#endif

#if defined (j721e_evm) || defined (j7200_evm)
/* J7ES: use WAKEUP GPIO0_6 --> TP45 for testing */
#define GPIO_LED0_PIN_NUM        BOARD_USER_LED1 /* Pin 6 */
#define GPIO_LED0_PORT_NUM       0 /* use WAKEUP GPIO0 */
#define GPIO_LED1_PIN_NUM        BOARD_USER_LED1 /* Pin 6 */
#define GPIO_LED1_PORT_NUM       0 /* use WAKEUP GPIO0 */
#endif

/* ON Board LED pins which are connected to GPIO pins. */
typedef enum GPIO_LED {
    USER_LED0 = 0,
    USER_LED1
}GPIO_LED;


#define GPIO_PIN_VAL_LOW     (0U)
#define GPIO_PIN_VAL_HIGH    (1U)


#ifdef __cplusplus
}
#endif

#endif /* _GPIO_LOG_H */
