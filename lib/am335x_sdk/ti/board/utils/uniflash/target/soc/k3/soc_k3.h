/*
 * Copyright (C) 2019 Texas Instruments Incorporated - http://www.ti.com/
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

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#ifndef _SOC_K3_H_
#define _SOC_K3_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <string.h>
#include <strings.h>

#include <ti/board/board.h>
#include <ti/csl/soc.h>
#include <diag_common_cfg.h>

#include <ti/csl/arch/csl_arch.h>
#include <ti/csl/src/ip/rat/V0/csl_rat.h>

#include <ti/drv/sciclient/sciclient.h>
#include <ti/drv/sciclient/src/sciclient_priv.h>
#include <ti/drv/uart/UART.h>
#include <ti/drv/uart/src/UART_osal.h>
#include <ti/drv/uart/UART_stdio.h>
#include <ti/drv/uart/soc/UART_soc.h>

#if defined(SOC_J721E)
#include <ti/csl/soc/j721e/src/cslr_wkup_ctrl_mmr.h>
#include <ti/csl/soc/j721e/src/cslr_mcu_pll_mmr.h>

#define UFP_UART_PLL_BASE                   (CSL_MCU_PLL0_CFG_BASE)
#define UFP_UART_PLL_KICK0_OFFSET           (CSL_MCU_PLL_MMR_CFG_PLL1_LOCKKEY0)
#define UFP_UART_PLL_KICK1_OFFSET           (CSL_MCU_PLL_MMR_CFG_PLL1_LOCKKEY1)
#define UFP_UART_PLL_DIV_OFFSET             (CSL_MCU_PLL_MMR_CFG_PLL1_HSDIV_CTRL3)
#define UFP_UART_PLL_DIV_VAL                (0x00008031)
#define UFP_UART_PLL_KICK0_UNLOCK_VAL       (0x68EF3490)
#define UFP_UART_PLL_KICK1_UNLOCK_VAL       (0xD172BC5A)
#define UFP_UART_PLL_KICK_LOCK_VAL          (0x0)
#define UFP_MCU_ARMSS_ATCM_BASE             (CSL_MCU_ARMSS_ATCM_BASE)
#elif defined(SOC_AM65XX)
#define UFP_MCU_ARMSS_ATCM_BASE             (CSL_MCU_ATCM_BASE)
#endif

#define UFP_ROM_UART_MODULE_INPUT_CLK       (48000000U)
#define UFP_SYSFW_UART_MODULE_INPUT_CLK     (96000000U)

#define UFP_SYSFW_NOT_PROCESSED    (0x0U)
#define UFP_SYSFW_CLEAR_TEXT       (0x55555555u)
#define UFP_SYSFW_ENCRYPTED        (0xAAAAAAAAu)
#define UFP_SYSFW_MAX_SIZE         (0x41000U)

#define UFP_MAIN_DEVSTAT_ADDR      (CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_MAIN_DEVSTAT)
#define UFP_WKUP_DEVSTAT_ADDR      (CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_WKUP_DEVSTAT)

#if defined(SOC_J721E)
#define UFP_MAIN_DEVSTAT_NOBOOT_CFG     (0x1U)
#define UFP_WKUP_DEVSTAT_NOBOOT_CFG     (0x38U)
#define UFP_MAIN_DEVSTAT_NOBOOT_MASK    (0xEFU)
#define UFP_WKUP_DEVSTAT_NOBOOT_MASK    (0xF8U)
#else
#define UFP_MAIN_DEVSTAT_NOBOOT_CFG    (0)
#define UFP_WKUP_DEVSTAT_NOBOOT_CFG    (0)
#define UFP_MAIN_DEVSTAT_NOBOOT_MASK   (0xFFU)
#define UFP_WKUP_DEVSTAT_NOBOOT_MASK   (0)
#endif

#ifdef __cplusplus
}
#endif

#endif /* _SOC_K3_H_ */
