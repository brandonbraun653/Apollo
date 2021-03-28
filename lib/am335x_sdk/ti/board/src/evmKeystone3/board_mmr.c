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
 *  \file   board_mmr.c
 *
 *  \brief  MMR configuration file
 *
 *  This file contains the function to unlock the MMR registers
 *
 */

#include "board_internal.h"

Board_STATUS MMR_unlock(uint32_t *kick0, uint32_t *kick1)
{
    /* Initialize the status variable */
    Board_STATUS status = BOARD_SOK;

    /* If either of the kick lock registers are locked */
    if(!(*kick0 & 0x01) || !(*kick1 & 0x01))
    {
        /* Unlock the partition by writing the unlock values to the kick lock registers */
        *kick0 = KICK0_UNLOCK_VAL;
        *kick1 = KICK1_UNLOCK_VAL;
    }

    /* Check to see if either of the kick registers are unlocked. */
    if(!(*kick0 & 0x01) || !(*kick1 & 0x01))
    {
        status = BOARD_INVALID_PARAM;
    }

    return status;
}

/**
 * \brief  Unlocks MMR registers
 *
 * \return  Board_STATUS
 */
Board_STATUS Board_unlockMMR(void)
{
    uint32_t *lock0;
    uint32_t *lock1;

    /* Unlock MAIN MMR registers */
    lock0 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK0_KICK0);
    lock1 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK0_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK0);
    lock1 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK1_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK2_KICK0);
    lock1 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK2_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK3_KICK0);
    lock1 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK3_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK6_KICK0);
    lock1 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK6_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK7_KICK0);
    lock1 = (uint32_t *)(CSL_CTRL_MMR0_CFG0_BASE + CSL_MAIN_CTRL_MMR_CFG0_LOCK7_KICK1);
    MMR_unlock(lock0, lock1);

    /* Unlock wakeup MMR registers */
    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK0_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK0_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK1_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK1_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK2_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK3_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK3_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK6_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK6_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK0);
    lock1 = (uint32_t *)(CSL_WKUP_CTRL_MMR0_CFG0_BASE + CSL_WKUP_CTRL_MMR_CFG0_LOCK7_KICK1);
    MMR_unlock(lock0, lock1);

    /* Unlock MCU MMR registers */
    lock0 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK0);
    lock1 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK0_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK0);
    lock1 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK1_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK0);
    lock1 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK2_KICK1);
    MMR_unlock(lock0, lock1);

    lock0 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK6_KICK0);
    lock1 = (uint32_t *)(CSL_MCU_CTRL_MMR0_CFG0_BASE + CSL_MCU_CTRL_MMR_CFG0_LOCK6_KICK1);
    MMR_unlock(lock0, lock1);
    
    return BOARD_SOK;
}

