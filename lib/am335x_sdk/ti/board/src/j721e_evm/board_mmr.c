/******************************************************************************
 * Copyright (c) 2019-2020 Texas Instruments Incorporated - http://www.ti.com
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
 *  \file   board_mmr.c
 *
 *  \brief  MMR configuration file
 *
 *  This file contains the function to unlock the MMR registers
 *
 */

#include "board_internal.h"
#include <ti/csl/soc/j721e/src/cslr_wkup_ctrl_mmr.h>

/**
 * \brief  Configures kick registers to lock/unlock MMR access
 *
 * \param   kick0    [IN]   KICK0 register address
 * \param   kick1    [IN]   KICK1 register address
 * \param   lockCtrl [IN]   Register lock/unlock control
 *                          0 - Unlocks the MMR register write access
 *                          1 - Locks the MMR register write access
 *
 * \return  BOARD_SOK - MMR kick register configurations successful
 *          BOARD_FAIL - MMR kick register configurations failed
 */
static Board_STATUS MMR_config(uint32_t *kick0, uint32_t *kick1, uint8_t lockCtrl)
{
    /* Initialize the status variable */
    Board_STATUS status = BOARD_SOK;

    if(lockCtrl == 0)
    {
        /* If either of the kick lock registers are locked */
        if(!(*kick0 & 0x01))
        {
            /* Unlock the partition by writing the unlock values to the kick lock registers */
            *kick0 = BOARD_KICK0_UNLOCK_VAL;
            *kick1 = BOARD_KICK1_UNLOCK_VAL;
        }

        /* Confirm both the kick registers are unlocked */
        if(!(*kick0 & 0x01))
        {
            status = BOARD_FAIL;
        }
    }
    else
    {
        /* Lock the partition by writing the lock values to the kick lock registers */
        *kick0 = BOARD_KICK0_LOCK_VAL;
        *kick1 = BOARD_KICK1_LOCK_VAL;

        /* Confirm both the kick registers are locked */
        if(*kick0 & 0x01)
        {
            status = BOARD_FAIL;
        }
    }

    return status;
}

/**
 * \brief  Unlocks MMR registers
 *
 * \param   lockCtrl [IN]   Register lock/unlock control
 *                          0 - Unlocks the MMR register write access
 *                          1 - Locks the MMR register write access
 *
 * \return  BOARD_SOK - MMR kick register configurations successful
 *          BOARD_FAIL - MMR kick register configurations failed
 */
Board_STATUS Board_ctrlMMR(uint8_t lockCtrl)
{
    Board_STATUS status = BOARD_SOK;
    uint32_t *lock0;
    uint32_t *lock1;

    Board_setRATCfg();

    /* Unlock MAIN MMR registers */
    lock0 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK0_KICK0);
    lock1 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK0_KICK1);
    status = MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK0);
    lock1 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK2_KICK0);
    lock1 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK2_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK3_KICK0);
    lock1 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK3_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK5_KICK0);
    lock1 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK5_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK6_KICK0);
    lock1 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK6_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK7_KICK0);
    lock1 = (uint32_t *)(BOARD_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK7_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    /* Unlock wakeup MMR registers */
    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK0_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK0_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK1_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK1_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK3_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK3_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK6_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK6_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    /* Unlock MCU MMR registers */
    lock0 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK0);
    lock1 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0);
    lock1 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0);
    lock1 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    lock0 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK0);
    lock1 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK3_KICK1);
    status |= MMR_config(lock0, lock1, lockCtrl);

    Board_restoreRATCfg();

    return status;
}

/**
 * \brief  Locks MMR registers
 *
 * \return  Board_STATUS
 */
Board_STATUS Board_lockMMR(void)
{
    Board_STATUS status;

    status = Board_ctrlMMR(1);

    return status;
}

/**
 * \brief  Unlocks MMR registers
 *
 * \return  Board_STATUS
 */
Board_STATUS Board_unlockMMR(void)
{
    Board_STATUS status;

    status = Board_ctrlMMR(0);

    return status;
}
