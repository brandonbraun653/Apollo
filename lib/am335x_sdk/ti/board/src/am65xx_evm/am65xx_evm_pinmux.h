/******************************************************************************
 * Copyright (c) 2018 Texas Instruments Incorporated - http://www.ti.com
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
 *****************************************************************************/

/**
 * \file   am65xx_evm_pinmux.h
 *
 * \brief  AM65xx EVM pinmux interface header file.
 *
 */


#ifndef _AM65XXEVM_PIN_MUX_H_
#define _AM65XXEVM_PIN_MUX_H_

/* ========================================================================== */
/*                             Include Files                                  */
/* ========================================================================== */

#include "pinmux.h"
#include "csl_types.h"
#include "AM65xx_pinmux.h"
#include <ti/csl/soc/am65xx/src/cslr_wkup_ctrl_mmr.h>

#ifdef __cplusplus
extern "C" {
#endif

#define MODE_PIN_MASK                   (0xFU)
#define PINMUX_BIT_MASK                 (0xFFF8FFF0U)

/* MAIN CTRL base address + offset to beginning of PAD CONFIG  section */
#define MAIN_PMUX_CTRL	(CSL_CTRL_MMR0_CFG0_BASE + 0x1C000)
 
/* WKUP CTRL base address + offset to beginning of PAD CONFIG section */
#define WKUP_PMUX_CTRL	(CSL_WKUP_CTRL_MMR0_CFG0_BASE + 0x1C000)

/* Default pinmux configuration of UART Tx pin used by ROM/SBL */
#define BOARD_MCU_UART_TX_PINMUX_VAL            (PIN_MODE(4) | ((PIN_PULL_DISABLE) & \
                                                 (~PIN_PULL_DIRECTION & ~PIN_INPUT_ENABLE)))
#define BOARD_MCU_UART_TX_PINMUX_ADDR           (WKUP_PMUX_CTRL + PIN_MCU_OSPI1_D2)
#define BOARD_MCU_UART_TX_LOCK_KICK_ADDR        (CSL_WKUP_CTRL_MMR0_CFG0_BASE + \
                                                 CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK0)

/**
 *  \brief    This function used to set the specified pinMux
 *            mode for a specified pinMux offset address register.
 *
 *  \param    offset     [IN]       Pad config offset address
 *            mode       [IN]       Pad config mux mode.
 *
 *  \return   int8_t
 *               0 - in case of success
 *              -1 - in case of failure.
 *
 */
void Board_pinMuxSetMode(uint32_t offset, uint32_t mode);

/**
 * \brief  Board UART Tx pinmuxing enable function
 *
 * Enables pinmux for the UART Tx pin of the default UART instance used
 * by ROM/SBL.
 *
 * \param   void
 *
 * \return  void
 *
 */
void Board_uartTxPinmuxConfig(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */
#endif /* _AM65XXEVM_PIN_MUX_H_ */
