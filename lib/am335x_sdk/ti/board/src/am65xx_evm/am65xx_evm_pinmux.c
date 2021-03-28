/******************************************************************************
 * Copyright (c) 2017 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file am65xx_evm_pinmux.c
 *
 *  \brief This file Enables pinmux for the AM65xx evm board 
 *
 */

#include <ti/csl/soc.h>				
#include "board_internal.h"
#include "am65xx_evm_pinmux.h"

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
void Board_pinMuxSetMode(uint32_t offset, uint32_t mode)
{
    volatile uint32_t *addr;
    addr = (uint32_t *)(MAIN_PMUX_CTRL + offset);

    *addr &= ~(MODE_PIN_MASK);
    *addr |= mode;
}

/**
 * \brief  Board pinmuxing enable function
 *
 * Enables pinmux for the AM65xx evm board interfaces. Pin mux is done based
 * on the default/primary functionality of the board. Any pins shared by
 * multiple interfaces need to be reconfigured to access the secondary
 * functionality.
 *
 * \param   void
 *
 * \return  BOARD_SOK in case of success or appropriate error code
 *
 */
Board_STATUS Board_pinmuxConfig (void)
{
    pinmuxModuleCfg_t* pModuleData = NULL;
    pinmuxPerCfg_t* pInstanceData = NULL;
    int32_t i, j, k;
    uint32_t rdRegVal;

    if (Board_isSocPG1() == TRUE)
    {
        gSystemPinCfg[0].doPinConfig = FALSE;
        gSystemPinCfg[0].instPins = gSystem0PinCfgPG1;

        gWkup_systemPinCfg[0].doPinConfig = FALSE;
        gWkup_systemPinCfg[0].instPins = gWkup_system0PinCfgPG1;
    }

    Board_unlockMMR();

    for(i = 0; PINMUX_END != gAM65xxMainPinmuxData[i].moduleId; i++)
    {
        pModuleData = gAM65xxMainPinmuxData[i].modulePinCfg;
        for(j = 0; (PINMUX_END != pModuleData[j].modInstNum); j++)
        {
            if(pModuleData[j].doPinConfig == TRUE)
            {
                pInstanceData = pModuleData[j].instPins;
                for(k = 0; (PINMUX_END != pInstanceData[k].pinOffset); k++)
                {
                    rdRegVal = HW_RD_REG32((MAIN_PMUX_CTRL + pInstanceData[k].pinOffset));
                    rdRegVal = (rdRegVal & PINMUX_BIT_MASK);
                    HW_WR_REG32((MAIN_PMUX_CTRL + pInstanceData[k].pinOffset),
                                (pInstanceData[k].pinSettings));
                }
            }
        }
    }

	for(i = 0; PINMUX_END != gAM65xxWkupPinmuxData[i].moduleId; i++)
    {
        pModuleData = gAM65xxWkupPinmuxData[i].modulePinCfg;
        for(j = 0; (PINMUX_END != pModuleData[j].modInstNum); j++)
        {
            if(pModuleData[j].doPinConfig == TRUE)
            {
                pInstanceData = pModuleData[j].instPins;
                for(k = 0; (PINMUX_END != pInstanceData[k].pinOffset); k++)
                {
                    rdRegVal = HW_RD_REG32((WKUP_PMUX_CTRL + pInstanceData[k].pinOffset));
                    rdRegVal = (rdRegVal & PINMUX_BIT_MASK);
                    HW_WR_REG32((WKUP_PMUX_CTRL + pInstanceData[k].pinOffset),
                                 (pInstanceData[k].pinSettings));
                }
            }
        }
    }

    return BOARD_SOK;
}

void Board_uartTxPinmuxConfig(void)
{
    /* Unlock partition lock kick */
    HW_WR_REG32(BOARD_MCU_UART_TX_LOCK_KICK_ADDR, KICK0_UNLOCK_VAL);
    HW_WR_REG32(BOARD_MCU_UART_TX_LOCK_KICK_ADDR + 4U, KICK1_UNLOCK_VAL);

    /* Configure pinmux for UART Tx pin */
    HW_WR_REG32(BOARD_MCU_UART_TX_PINMUX_ADDR, BOARD_MCU_UART_TX_PINMUX_VAL);
}
