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
 *
 * \file   pwm_test.h
 *
 * \brief  This is the header file for pwm diagnostic test
 *
 ******************************************************************************/

#ifndef _PWM_TEST_H_
#define _PWM_TEST_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <ti/csl/soc.h>
#include <ti/csl/csl_epwm.h>

#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/UART_stdio.h>

#include "ti/board/board.h"
#include "ti/board/board_cfg.h"

#if defined(evmAM335x)  /* evmAM335x */

#include <soc_am335x.h>
#include <hw_pwmss.h>
#include <hw_cm_per.h>
#include <hw_control_am335x.h>

/*Module clock is the frequency of PWMSS operates*/
#define MODULE_CLK                              (100000000) /* 100MHz */
#define PWM_BASE_ADDRESS                        (SOC_PWMSS0_REGS)
#define DELAY                                   (4500000U)

#elif defined(evmAM572x)  /* evmAM572x */

#include <ti/csl/soc/am572x/src/cslr_soc_mpu_baseaddress.h>
#include <ti/csl/soc/am572x/src/cslr_control_core_pad_io.h>

/*Address of the PAD config pinMux register*/
#define CTRL_CORE_PAD_GPIO6_10_ADDR             (CSL_MPU_CORE_PAD_IO_REGISTERS_REGS + \
                                                 CSL_CONTROL_CORE_PAD_IO_PAD_GPIO6_10)

/*Module clock is the frequency of PWMSS operates*/
#define MODULE_CLK                              (133000000U)/*133MHz*/
#define PWM_BASE_ADDRESS                        (CSL_MPU_PWMSS2_IPWMSS_REGS)
#define DELAY                                   (625000000)

#elif defined(evmK2G)  /* evmK2G */

#include <ti/csl/soc/k2g/src/cslr_soc_baseaddress.h>

#define BOOTCFG_EPWM_CTL_REG_OFFSET             (0xE40)
#define BOOTCFG_PAD_CONFIG_REG_73_OFFSET        (0x1124)

/*Module clock is the frequency of PWMSS operates*/
#define MODULE_CLK                              (100000000)/*100MHz*/
#define PWM_BASE_ADDRESS                        (CSL_PWM_3_CFG_REGS)
#define DELAY                                   (9000000)

#elif defined(idkAM437x)

#include <am437x.h>
#include <hw_pwmss.h>
#include <hw_control_am43xx.h>

/*Module clock is the frequency of PWMSS operates*/
#define MODULE_CLK                              (100000000)/*100MHz*/
#define PWM_BASE_ADDRESS                        (SOC_PWMSS2_REG)
#define DELAY                                   (9000000)

#endif

#define TBCLK_FREQ                              (MODULE_CLK/4)
#define PWM_FREQ                                (1000)/*1KHz*/

/* TBCNT MODE bits */
#define TB_COUNT_UP                             (0x0)

/* PRDLD bit */
#define TB_IMMEDIATE                            (0x1)

/* LOADAMODE and LOADBMODE bits */
#define CC_CTR_ZERO                             (0x0)

/* SHDWAMODE and SHDWBMODE bits */
#define CC_SHADOW                               (0x0)

#define AQ_NO_ACTION                            (0x0)
#define AQ_CLEAR                                (0x1)
#define AQ_TOGGLE                               (0x3)

#define CLEAR_PHASE_REG                         (0x0000U)
#define RESET_TB_COUNT_VALUE                    (0x00000000U)
#define OVER_WRITE_SHADOW_DISABLED              (0x0000)

#endif /* _PWM_TEST_H_  */
